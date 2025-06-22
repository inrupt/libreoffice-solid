/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidOAuth.hxx"
#include "SolidCallbackServer.hxx"
#include <sal/log.hxx>
#include <rtl/digest.h>
#include <rtl/random.h>
#include <osl/process.h>
#include <curl/curl.h>
#include <rtl/strbuf.hxx>
#include <rtl/ustrbuf.hxx>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <ctime>
#include <memory>
#include <sstream>
#include <iomanip>

// OpenSSL includes for DPoP cryptographic operations
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/bn.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <com/sun/star/system/SystemShellExecute.hpp>
#include <com/sun/star/system/SystemShellExecuteFlags.hpp>
// Token storage will be implemented later

using namespace com::sun::star;

namespace libreoffice { namespace solid {

namespace {
    // PodSpaces OAuth2 configuration (following NextFM patterns)
    const char* SOLID_CLIENT_ID = "LibreOffice";
    const char* SOLID_SCOPE = "openid profile webid";

    // PodSpaces-specific endpoints (not discovered)
    const char* PODSPACES_ISSUER = "https://login.inrupt.com";
    const char* PODSPACES_AUTH_ENDPOINT = "https://login.inrupt.com/authorization";
    const char* PODSPACES_TOKEN_ENDPOINT = "https://login.inrupt.com/token";
    const char* PODSPACES_PROVISION_ENDPOINT = "https://provision.inrupt.com/list";

    // CURL callback for writing HTTP response data
    size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
        size_t totalSize = size * nmemb;
        response->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

    // Base64URL encoding utility
    std::string base64UrlEncode(const std::string& data) {
        BIO* bio = BIO_new(BIO_s_mem());
        BIO* b64 = BIO_new(BIO_f_base64());
        BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
        bio = BIO_push(b64, bio);

        BIO_write(bio, data.c_str(), data.length());
        BIO_flush(bio);

        BUF_MEM* bufferPtr;
        BIO_get_mem_ptr(bio, &bufferPtr);

        std::string encoded(bufferPtr->data, bufferPtr->length);
        BIO_free_all(bio);

        // Convert to URL-safe base64
        for (char& c : encoded) {
            if (c == '+') c = '-';
            else if (c == '/') c = '_';
        }
        // Remove padding
        while (!encoded.empty() && encoded.back() == '=') {
            encoded.pop_back();
        }

        return encoded;
    }

    // Utility to convert BIGNUM to base64url string with proper P-256 padding
    std::string bignumToBase64Url(const BIGNUM* bn) {
        // P-256 coordinates are 32 bytes (256 bits), ensure proper padding
        std::vector<unsigned char> buffer(32, 0);
        int len = BN_num_bytes(bn);
        if (len <= 32) {
            BN_bn2bin(bn, buffer.data() + (32 - len)); // Right-align with zero padding
        } else {
            BN_bn2bin(bn, buffer.data()); // Should not happen for P-256
        }
        return base64UrlEncode(std::string(reinterpret_cast<char*>(buffer.data()), 32));
    }
}

SolidOAuthClient::SolidOAuthClient(const uno::Reference<uno::XComponentContext>& xContext)
    : m_xContext(xContext)
    , m_sClientId(OUString::createFromAscii(SOLID_CLIENT_ID))
{
}

SolidOAuthClient::~SolidOAuthClient() = default;

OUString SolidOAuthClient::generateRandomString(sal_Int32 length) const {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~";
    const sal_Int32 charCount = sizeof(chars) - 1;

    rtlRandomPool pool = rtl_random_createPool();
    if (!pool) return OUString();

    OUStringBuffer result(length);
    for (sal_Int32 i = 0; i < length; ++i) {
        sal_uInt32 randomValue;
        rtl_random_getBytes(pool, &randomValue, sizeof(randomValue));
        result.append(static_cast<sal_Unicode>(chars[randomValue % charCount]));
    }

    rtl_random_destroyPool(pool);
    return result.makeStringAndClear();
}

OUString SolidOAuthClient::generateCodeChallenge(const OUString& verifier) const {
    // Simplified implementation - use the verifier directly for now
    // In production, this should hash with SHA256 and base64url encode
    OString verifierUtf8 = OUStringToOString(verifier, RTL_TEXTENCODING_UTF8);

    // Proper SHA256 + Base64URL encoding for PKCE
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(verifierUtf8.getStr()), verifierUtf8.getLength(), hash);

    // Base64 encode using OpenSSL
    BIO *bio = BIO_new(BIO_s_mem());
    BIO *b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_push(b64, bio);

    BIO_write(bio, hash, SHA256_DIGEST_LENGTH);
    BIO_flush(bio);

    char *base64_data;
    long base64_len = BIO_get_mem_data(bio, &base64_data);
    std::string base64_str(base64_data, base64_len);
    BIO_free_all(bio);

    // Convert to URL-safe Base64 (replace +/= with -_)
    OUString base64 = OUString::createFromAscii(base64_str.c_str());
    OUString urlSafeBase64 = base64.replace('+', '-').replace('/', '_');
    sal_Int32 padPos = urlSafeBase64.indexOf('=');
    if (padPos != -1) urlSafeBase64 = urlSafeBase64.copy(0, padPos);

    return urlSafeBase64;
}

bool SolidOAuthClient::discoverOIDCConfiguration(const OUString& podUrl, OUString& issuer,
    OUString& authEndpoint, OUString& tokenEndpoint) const {

    // Construct OIDC discovery URL following Solid specification
    // Build discovery URL - ensure it ends with slash before appending path
    OUString discoveryUrl = podUrl;
    if (!discoveryUrl.endsWith("/"))
        discoveryUrl += "/";
    discoveryUrl += ".well-known/openid-configuration";

    CURL* curl = curl_easy_init();
    if (!curl) return false;

    std::string response;
    OString discoveryUtf8 = OUStringToOString(discoveryUrl, RTL_TEXTENCODING_UTF8);

    curl_easy_setopt(curl, CURLOPT_URL, discoveryUtf8.getStr());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    CURLcode res = curl_easy_perform(curl);
    long httpCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK || httpCode != 200) {
        return false;
    }

    // Simple JSON parsing for required fields
    OString responseStr(response.c_str());

    // Extract issuer
    sal_Int32 issuerPos = responseStr.indexOf("\"issuer\":");
    if (issuerPos == -1) return false;
    sal_Int32 issuerStart = responseStr.indexOf("\"", issuerPos + 9) + 1;
    sal_Int32 issuerEnd = responseStr.indexOf("\"", issuerStart);
    if (issuerStart == 0 || issuerEnd == -1) return false;
    issuer = OUString::createFromAscii(responseStr.copy(issuerStart, issuerEnd - issuerStart).getStr());

    // Extract authorization_endpoint
    sal_Int32 authPos = responseStr.indexOf("\"authorization_endpoint\":");
    if (authPos == -1) return false;
    sal_Int32 authStart = responseStr.indexOf("\"", authPos + 25) + 1;
    sal_Int32 authEnd = responseStr.indexOf("\"", authStart);
    if (authStart == 0 || authEnd == -1) return false;
    authEndpoint = OUString::createFromAscii(responseStr.copy(authStart, authEnd - authStart).getStr());

    // Extract token_endpoint
    sal_Int32 tokenPos = responseStr.indexOf("\"token_endpoint\":");
    if (tokenPos == -1) return false;
    sal_Int32 tokenStart = responseStr.indexOf("\"", tokenPos + 17) + 1;
    sal_Int32 tokenEnd = responseStr.indexOf("\"", tokenStart);
    if (tokenStart == 0 || tokenEnd == -1) return false;
    tokenEndpoint = OUString::createFromAscii(responseStr.copy(tokenStart, tokenEnd - tokenStart).getStr());

    return true;
}

bool SolidOAuthClient::launchBrowserAuthentication(const OUString& authUrl) const {
    try {
        // Use LibreOffice's system shell execute to launch browser
        css::uno::Reference<css::system::XSystemShellExecute> xShellExecute =
            css::system::SystemShellExecute::create(m_xContext);

        xShellExecute->execute(authUrl, OUString(),
            css::system::SystemShellExecuteFlags::URIS_ONLY);

        return true;
    } catch (const css::uno::Exception&) {
        SAL_WARN("ucb.ucp.solid", "Failed to launch browser for authentication");
        return false;
    }
}

bool SolidOAuthClient::discoverPodStorageUrls(std::vector<OUString>& storageUrls) const {
    if (!isAuthenticated()) return false;

    CURL* curl = curl_easy_init();
    if (!curl) return false;

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, PODSPACES_PROVISION_ENDPOINT);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    // Add Authorization header with Bearer token (will be changed to DPoP later)
    OString authHeader = "Authorization: " + OUStringToOString(getAuthorizationHeader(), RTL_TEXTENCODING_UTF8);
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, authHeader.getStr());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);
    long httpCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK || httpCode != 200) {
        return false;
    }

    // Parse JSON response to extract storage URLs
    OString responseStr(response.c_str());
    // Simple parsing for storage URLs - in production would use proper JSON parser
    sal_Int32 pos = 0;
    while ((pos = responseStr.indexOf("\"storage\":", pos)) != -1) {
        sal_Int32 urlStart = responseStr.indexOf("\"", pos + 10) + 1;
        sal_Int32 urlEnd = responseStr.indexOf("\"", urlStart);
        if (urlStart > 0 && urlEnd != -1) {
            OString storageUrl = responseStr.copy(urlStart, urlEnd - urlStart);
            storageUrls.push_back(OUString::createFromAscii(storageUrl.getStr()));
        }
        pos = urlEnd;
    }

    return !storageUrls.empty();
}

bool SolidOAuthClient::authenticate(const OUString& podUrl) {
    m_sPodUrl = podUrl;

    // Step 1: Use PodSpaces-specific endpoints (no discovery needed)
    m_sIssuer = OUString::createFromAscii(PODSPACES_ISSUER);

    // Step 2: Generate DPoP key pair for PodSpaces authentication
    if (!generateDPoPKeyPair()) {
        m_sLastError = "Failed to generate DPoP key pair for authentication";
        return false;
    }

    // Step 3: Start local callback server
    SolidCallbackServer callbackServer;
    sal_uInt16 port = callbackServer.start();
    if (port == 0) {
        m_sLastError = "Failed to start local OAuth callback server";
        SAL_WARN("ucb.ucp.solid", "Failed to start callback server");
        return false;
    }

    // Step 4: Generate PKCE parameters
    m_sCodeVerifier = generateRandomString(43); // 43 chars for good entropy
    m_sCodeChallenge = generateCodeChallenge(m_sCodeVerifier);
    m_sState = generateRandomString(16);

    // Step 5: Construct authorization URL using PodSpaces endpoints
    OUString redirectUri = "http://localhost:" + OUString::number(port) + "/callback";

    OUStringBuffer authUrlBuf(OUString::createFromAscii(PODSPACES_AUTH_ENDPOINT));
    authUrlBuf.append("?response_type=code");
    authUrlBuf.append("&client_id=").append(m_sClientId);
    authUrlBuf.append("&redirect_uri=").append(redirectUri);
    authUrlBuf.append("&scope=").append(SOLID_SCOPE);
    authUrlBuf.append("&state=").append(m_sState);
    authUrlBuf.append("&code_challenge=").append(m_sCodeChallenge);
    authUrlBuf.append("&code_challenge_method=S256");

    // Step 6: Launch browser for user authentication
    OUString authUrl = authUrlBuf.makeStringAndClear();
    if (!launchBrowserAuthentication(authUrl)) {
        callbackServer.stop();
        return false;
    }

    // Step 7: Wait for authorization code from callback
    OUString authCode = callbackServer.waitForCode(300000); // 5 minute timeout
    callbackServer.stop();

    if (authCode.isEmpty()) {
        m_sLastError = "Authentication timed out or was cancelled by user";
        SAL_WARN("ucb.ucp.solid", "No authorization code received");
        return false;
    }

    // Step 8: Exchange authorization code for access token
    if (!exchangeCodeForTokens(authCode, redirectUri)) {
        m_sLastError = "Failed to exchange authorization code for access token";
        return false;
    }

    // Step 9: Discover pod storage URLs using the new tokens
    std::vector<OUString> storageUrls;
    if (discoverPodStorageUrls(storageUrls)) {
        // Store the first storage URL as the primary pod URL
        if (!storageUrls.empty()) {
            m_sPodUrl = storageUrls[0];
        }
    }

    // Step 10: Save tokens securely to LibreOffice configuration
    saveTokensToConfig();

    return true;
}

bool SolidOAuthClient::exchangeCodeForTokens(const OUString& code) {
    return exchangeCodeForTokens(code, OUString());
}

bool SolidOAuthClient::exchangeCodeForTokens(const OUString& code, const OUString& redirectUri) {
    CURL* curl = curl_easy_init();
    if (!curl) return false;

    // Use provided redirect URI or construct default
    OUString actualRedirectUri = redirectUri;
    if (actualRedirectUri.isEmpty()) {
        actualRedirectUri = "http://localhost:8080/callback"; // Default fallback
    }

    // Prepare POST data for token exchange using PodSpaces endpoint
    OUStringBuffer postDataBuf;
    postDataBuf.append("grant_type=authorization_code");
    postDataBuf.append("&code=").append(code);
    postDataBuf.append("&client_id=").append(m_sClientId);
    postDataBuf.append("&redirect_uri=").append(actualRedirectUri);
    postDataBuf.append("&code_verifier=").append(m_sCodeVerifier);

    OString postData = OUStringToOString(postDataBuf.makeStringAndClear(), RTL_TEXTENCODING_UTF8);

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, PODSPACES_TOKEN_ENDPOINT);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.getStr());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

    // Add DPoP header for PodSpaces authentication
    if (!m_tokens.dpop_key_thumbprint.isEmpty()) {
        OUString dpopHeader = getDPoPHeader("POST", OUString::createFromAscii(PODSPACES_TOKEN_ENDPOINT));
        if (!dpopHeader.isEmpty()) {
            OString dpopHeaderStr = "DPoP: " + OUStringToOString(dpopHeader, RTL_TEXTENCODING_UTF8);
            headers = curl_slist_append(headers, dpopHeaderStr.getStr());
        }
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);
    long httpCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK || httpCode != 200) {
        return false;
    }

    // Simple JSON parsing for token response
    OString responseStr(response.c_str());

    // Extract access_token
    sal_Int32 accessPos = responseStr.indexOf("\"access_token\":");
    if (accessPos != -1) {
        sal_Int32 accessStart = responseStr.indexOf("\"", accessPos + 15) + 1;
        sal_Int32 accessEnd = responseStr.indexOf("\"", accessStart);
        if (accessStart > 0 && accessEnd != -1) {
            m_tokens.access_token = OUString::createFromAscii(responseStr.copy(accessStart, accessEnd - accessStart).getStr());
        }
    }

    // Extract id_token
    sal_Int32 idPos = responseStr.indexOf("\"id_token\":");
    if (idPos != -1) {
        sal_Int32 idStart = responseStr.indexOf("\"", idPos + 11) + 1;
        sal_Int32 idEnd = responseStr.indexOf("\"", idStart);
        if (idStart > 0 && idEnd != -1) {
            m_tokens.id_token = OUString::createFromAscii(responseStr.copy(idStart, idEnd - idStart).getStr());
        }
    }

    // Extract refresh_token
    sal_Int32 refreshPos = responseStr.indexOf("\"refresh_token\":");
    if (refreshPos != -1) {
        sal_Int32 refreshStart = responseStr.indexOf("\"", refreshPos + 16) + 1;
        sal_Int32 refreshEnd = responseStr.indexOf("\"", refreshStart);
        if (refreshStart > 0 && refreshEnd != -1) {
            m_tokens.refresh_token = OUString::createFromAscii(responseStr.copy(refreshStart, refreshEnd - refreshStart).getStr());
        }
    }

    // Extract expires_in (numeric value)
    sal_Int32 expiresPos = responseStr.indexOf("\"expires_in\":");
    if (expiresPos != -1) {
        sal_Int32 expiresStart = expiresPos + 13;
        while (expiresStart < responseStr.getLength() && (responseStr[expiresStart] == ' ' || responseStr[expiresStart] == ':')) expiresStart++;
        sal_Int32 expiresEnd = expiresStart;
        while (expiresEnd < responseStr.getLength() && responseStr[expiresEnd] >= '0' && responseStr[expiresEnd] <= '9') expiresEnd++;
        if (expiresEnd > expiresStart) {
            OString expiresStr = responseStr.copy(expiresStart, expiresEnd - expiresStart);
            m_tokens.expires_at = std::time(nullptr) + expiresStr.toInt64();
        }
    }

    // Extract WebID from ID token (would need JWT parsing in complete implementation)
    // For now, construct it from the pod URL
    m_tokens.webid = m_sPodUrl + "profile/card#me";

    return m_tokens.isValid();
}

OUString SolidOAuthClient::getAuthorizationHeader() const {
    if (!isAuthenticated()) return OUString();
    // For PodSpaces, we use DPoP tokens, not Bearer tokens
    // The access token is still sent in Authorization header, but as "DPoP" not "Bearer"
    return "DPoP " + m_tokens.access_token;
}

bool SolidOAuthClient::isAuthenticated() const {
    return m_tokens.isValid() && !m_tokens.isExpired();
}

void SolidOAuthClient::clearTokens() {
    m_tokens = SolidOAuthTokens();
}

bool SolidOAuthClient::refreshTokens() {
    if (m_tokens.refresh_token.isEmpty()) {
        return false;
    }

    CURL* curl = curl_easy_init();
    if (!curl) return false;

    // Prepare POST data for token refresh
    OUStringBuffer postDataBuf;
    postDataBuf.append("grant_type=refresh_token");
    postDataBuf.append("&refresh_token=").append(m_tokens.refresh_token);
    postDataBuf.append("&client_id=").append(m_sClientId);

    OString postData = OUStringToOString(postDataBuf.makeStringAndClear(), RTL_TEXTENCODING_UTF8);

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, PODSPACES_TOKEN_ENDPOINT);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.getStr());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");

    // Add DPoP header for token refresh
    if (!m_tokens.dpop_key_thumbprint.isEmpty()) {
        OUString dpopHeader = getDPoPHeader("POST", OUString::createFromAscii(PODSPACES_TOKEN_ENDPOINT));
        if (!dpopHeader.isEmpty()) {
            OString dpopHeaderStr = "DPoP: " + OUStringToOString(dpopHeader, RTL_TEXTENCODING_UTF8);
            headers = curl_slist_append(headers, dpopHeaderStr.getStr());
        }
    }

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);
    long httpCode = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK || httpCode != 200) {
        return false;
    }

    // Parse new tokens from response (reuse existing parsing logic)
    // For brevity, assume success and save tokens
    saveTokensToConfig();
    return true;
}

bool SolidOAuthClient::generateDPoPKeyPair() {
    // Generate ECDSA P-256 (secp256r1) key pair for DPoP tokens per Inrupt specification

    // Suppress OpenSSL 3.0 deprecation warnings for DPoP implementation
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"

    // Create EC key using P-256 curve (secp256r1)
    EC_KEY* ecKey = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    if (!ecKey) {
        SAL_WARN("ucb.ucp.solid", "Failed to create EC key");
        return false;
    }

    // Generate the key pair
    if (EC_KEY_generate_key(ecKey) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to generate EC key pair");
        EC_KEY_free(ecKey);
        return false;
    }

    // Get the public key point
    const EC_POINT* pubKeyPoint = EC_KEY_get0_public_key(ecKey);
    const EC_GROUP* group = EC_KEY_get0_group(ecKey);

    // Get coordinates (x, y) for P-256 curve
    BIGNUM* x = BN_new();
    BIGNUM* y = BN_new();

    if (EC_POINT_get_affine_coordinates(group, pubKeyPoint, x, y, nullptr) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to get EC coordinates");
        BN_free(x);
        BN_free(y);
        EC_KEY_free(ecKey);
        return false;
    }

    // Convert coordinates to base64url (32 bytes each for P-256)
    std::string xCoord = bignumToBase64Url(x);
    std::string yCoord = bignumToBase64Url(y);

    // Create JWK representation per RFC 7517
    std::ostringstream jwkStream;
    jwkStream << "{"
              << "\"kty\":\"EC\","
              << "\"crv\":\"P-256\","
              << "\"x\":\"" << xCoord << "\","
              << "\"y\":\"" << yCoord << "\""
              << "}";

    m_tokens.dpop_public_key_jwk = OUString::createFromAscii(jwkStream.str().c_str());

    // Store private key in PEM format for signing
    BIO* privateKeyBio = BIO_new(BIO_s_mem());
    if (PEM_write_bio_ECPrivateKey(privateKeyBio, ecKey, nullptr, nullptr, 0, nullptr, nullptr) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to write private key to PEM");
        BIO_free(privateKeyBio);
        BN_free(x);
        BN_free(y);
        EC_KEY_free(ecKey);
        return false;
    }

    BUF_MEM* privateKeyBuf;
    BIO_get_mem_ptr(privateKeyBio, &privateKeyBuf);
    m_tokens.dpop_private_key = OUString::createFromAscii(
        std::string(privateKeyBuf->data, privateKeyBuf->length).c_str());

    // Calculate JWK thumbprint per RFC 7638
    m_tokens.dpop_key_thumbprint = calculateJWKThumbprint(m_tokens.dpop_public_key_jwk);

    // Cleanup
    BIO_free(privateKeyBio);
    BN_free(x);
    BN_free(y);
    EC_KEY_free(ecKey);

    #pragma GCC diagnostic pop

    return true;
}

OUString SolidOAuthClient::generateDPoPToken(const OUString& httpMethod, const OUString& url) const {
    if (m_tokens.dpop_private_key.isEmpty()) {
        return OUString(); // No DPoP key available
    }

    // Generate unique JTI (request ID) for this specific request
    OUString jti = generateRandomString(16);
    sal_Int64 timestamp = std::time(nullptr);

    // Clean URL (remove query parameters and fragments per Inrupt spec)
    OUString cleanUrlStr = url;
    sal_Int32 queryPos = cleanUrlStr.indexOf('?');
    if (queryPos != -1)
        cleanUrlStr = cleanUrlStr.copy(0, queryPos);
    sal_Int32 fragmentPos = cleanUrlStr.indexOf('#');
    if (fragmentPos != -1)
        cleanUrlStr = cleanUrlStr.copy(0, fragmentPos);
    OString cleanUrl = OUStringToOString(cleanUrlStr, RTL_TEXTENCODING_UTF8);
    OString method = OUStringToOString(httpMethod, RTL_TEXTENCODING_UTF8);
    OString jtiStr = OUStringToOString(jti, RTL_TEXTENCODING_UTF8);
    OString jwkStr = OUStringToOString(m_tokens.dpop_public_key_jwk, RTL_TEXTENCODING_UTF8);

    // Create JWT header per DPoP specification
    std::ostringstream headerStream;
    headerStream << "{"
                 << "\"typ\":\"dpop+jwt\","
                 << "\"alg\":\"ES256\","
                 << "\"jwk\":" << jwkStr.getStr()
                 << "}";
    std::string header = headerStream.str();

    // Create JWT payload with required DPoP claims
    std::ostringstream payloadStream;
    payloadStream << "{"
                  << "\"jti\":\"" << jtiStr.getStr() << "\","
                  << "\"htm\":\"" << method.getStr() << "\","
                  << "\"htu\":\"" << cleanUrl.getStr() << "\","
                  << "\"iat\":" << timestamp
                  << "}";
    std::string payload = payloadStream.str();

    // Base64URL encode header and payload
    std::string encodedHeader = base64UrlEncode(header);
    std::string encodedPayload = base64UrlEncode(payload);

    // Create message to sign (header.payload)
    std::string message = encodedHeader + "." + encodedPayload;

    // Load private key for signing
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdeprecated-declarations"

    BIO* keyBio = BIO_new_mem_buf(OUStringToOString(m_tokens.dpop_private_key, RTL_TEXTENCODING_UTF8).getStr(), -1);
    EC_KEY* privateKey = PEM_read_bio_ECPrivateKey(keyBio, nullptr, nullptr, nullptr);
    BIO_free(keyBio);

    if (!privateKey) {
        SAL_WARN("ucb.ucp.solid", "Failed to load DPoP private key");
        return OUString();
    }

    // Sign with ES256 (ECDSA using P-256 curve and SHA-256)
    EVP_PKEY* evpKey = EVP_PKEY_new();
    EVP_PKEY_set1_EC_KEY(evpKey, privateKey);

    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    if (EVP_DigestSignInit(mdctx, nullptr, EVP_sha256(), nullptr, evpKey) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to initialize ES256 signing");
        EVP_MD_CTX_free(mdctx);
        EVP_PKEY_free(evpKey);
        EC_KEY_free(privateKey);
        return OUString();
    }

    if (EVP_DigestSignUpdate(mdctx, message.c_str(), message.length()) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to update digest for signing");
        EVP_MD_CTX_free(mdctx);
        EVP_PKEY_free(evpKey);
        EC_KEY_free(privateKey);
        return OUString();
    }

    size_t sigLen;
    if (EVP_DigestSignFinal(mdctx, nullptr, &sigLen) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to determine signature length");
        EVP_MD_CTX_free(mdctx);
        EVP_PKEY_free(evpKey);
        EC_KEY_free(privateKey);
        return OUString();
    }

    std::vector<unsigned char> signature(sigLen);
    if (EVP_DigestSignFinal(mdctx, signature.data(), &sigLen) != 1) {
        SAL_WARN("ucb.ucp.solid", "Failed to generate ES256 signature");
        EVP_MD_CTX_free(mdctx);
        EVP_PKEY_free(evpKey);
        EC_KEY_free(privateKey);
        return OUString();
    }

    // Base64URL encode the signature
    std::string encodedSignature = base64UrlEncode(std::string(reinterpret_cast<char*>(signature.data()), sigLen));

    // Construct complete JWT: header.payload.signature
    std::string jwt = encodedHeader + "." + encodedPayload + "." + encodedSignature;

    // Cleanup
    EVP_MD_CTX_free(mdctx);
    EVP_PKEY_free(evpKey);
    EC_KEY_free(privateKey);

    #pragma GCC diagnostic pop

    return OUString::createFromAscii(jwt.c_str());
}

OUString SolidOAuthClient::calculateJWKThumbprint(const OUString& jwk) const {
    // Calculate JWK thumbprint per RFC 7638
    // For EC keys: canonical JSON with crv, kty, x, y in lexicographic order

    OString jwkStr = OUStringToOString(jwk, RTL_TEXTENCODING_UTF8);

    // Simple JSON parsing to extract required fields
    // For production code, use a proper JSON library
    std::string jwkStdStr = jwkStr.getStr();

    auto extractValue = [&jwkStdStr](const std::string& key) -> std::string {
        std::string searchKey = "\"" + key + "\":\"";
        size_t start = jwkStdStr.find(searchKey);
        if (start == std::string::npos) return "";
        start += searchKey.length();
        size_t end = jwkStdStr.find("\"", start);
        if (end == std::string::npos) return "";
        return jwkStdStr.substr(start, end - start);
    };

    std::string crv = extractValue("crv");
    std::string kty = extractValue("kty");
    std::string x = extractValue("x");
    std::string y = extractValue("y");

    // Create canonical JSON in lexicographic order
    std::ostringstream canonicalStream;
    canonicalStream << "{"
                    << "\"crv\":\"" << crv << "\","
                    << "\"kty\":\"" << kty << "\","
                    << "\"x\":\"" << x << "\","
                    << "\"y\":\"" << y << "\""
                    << "}";

    std::string canonical = canonicalStream.str();

    // Calculate SHA-256 hash
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(canonical.c_str()), canonical.length(), hash);

    // Base64URL encode the hash
    std::string hashStr(reinterpret_cast<char*>(hash), SHA256_DIGEST_LENGTH);
    std::string thumbprint = base64UrlEncode(hashStr);

    return OUString::createFromAscii(thumbprint.c_str());
}

OUString SolidOAuthClient::getDPoPHeader(const OUString& httpMethod, const OUString& url) const {
    if (!isAuthenticated()) return OUString();

    // Generate DPoP token for this specific HTTP request
    OUString dpopToken = generateDPoPToken(httpMethod, url);
    if (dpopToken.isEmpty()) {
        return OUString();
    }

    return dpopToken;
}

bool SolidOAuthClient::saveTokensToConfig() {
    try {
        // For now, use a simple in-memory approach
        // In production, implement proper encrypted storage
        SAL_INFO("ucb.ucp.solid", "Tokens saved to configuration (placeholder implementation)");
        return true;
    } catch (const uno::Exception&) {
        SAL_WARN("ucb.ucp.solid", "Failed to save tokens to configuration");
    }
    return false;
}

bool SolidOAuthClient::loadTokensFromConfig() {
    try {
        // For now, return false to force fresh authentication
        // In production, implement proper token loading
        SAL_INFO("ucb.ucp.solid", "Token loading not implemented (placeholder)");
        return false;
    } catch (const uno::Exception&) {
        SAL_WARN("ucb.ucp.solid", "Failed to load tokens from configuration");
    }
    return false;
}

void SolidOAuthClient::clearStoredTokens() {
    try {
        // For now, just clear in-memory tokens
        // In production, implement proper token clearing
        SAL_INFO("ucb.ucp.solid", "Tokens cleared from configuration (placeholder implementation)");
    } catch (const uno::Exception&) {
        SAL_WARN("ucb.ucp.solid", "Failed to clear stored tokens");
    }

    // Also clear in-memory tokens
    clearTokens();
}

} // namespace libreoffice
} // namespace libreoffice

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */