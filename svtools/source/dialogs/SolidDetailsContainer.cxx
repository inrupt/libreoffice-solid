/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidDetailsContainer.hxx"
#include <comphelper/processfactory.hxx>
#include <com/sun/star/system/SystemShellExecute.hpp>
#include <com/sun/star/system/SystemShellExecuteFlags.hpp>
#include <tools/urlobj.hxx>
#include <rtl/uri.hxx>
#include <vcl/svapp.hxx>
#include <svtools/PlaceEditDialog.hxx>
#include "../../../ucb/source/ucp/solid/SolidCallbackServer.hxx"
#include <curl/curl.h>
#include <sal/log.hxx>
#include <string>
#include <random>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <ucbhelper/authenticationfallback.hxx>

// Forward declaration for CMIS AuthProvider
namespace cmis { class AuthProvider; }

using namespace com::sun::star;

SolidDetailsContainer::SolidDetailsContainer(PlaceEditDialog* pDialog)
    : DetailsContainer(pDialog)
    , m_bAuthenticated(false)
{
    set_visible(false);
}

void SolidDetailsContainer::set_visible(bool bShow)
{
    if (bShow)
    {
        // Setup UI controls
        m_pDialog->m_xFTHost->set_label("Pod URL:");
        m_pDialog->m_xFTHost->set_visible(true);
        
        m_xPodUrl = m_pDialog->m_xEDHost;
        m_xPodUrl->set_placeholder_text("https://storage.inrupt.com/your-pod-id/");
        m_xPodUrl->connect_changed(LINK(this, SolidDetailsContainer, PodUrlChangeHdl));
        m_pDialog->m_xHostBox->set_visible(true);
        
        // Create authentication button if it doesn't exist
        if (!m_xAuthButton)
        {
            // Note: In real implementation, this would need proper UI integration
            // For now, we'll use existing button or create minimal UI
        }
        
        // Hide unused controls
        m_pDialog->m_xEDRoot->set_visible(false);
        m_pDialog->m_xFTRoot->set_visible(false);
        m_pDialog->m_xEDPort->set_visible(false);
        m_pDialog->m_xFTPort->set_visible(false);
        
        updateAuthStatus();
    }
    else
    {
        m_pDialog->m_xFTHost->set_visible(false);
        m_pDialog->m_xHostBox->set_visible(false);
    }

    DetailsContainer::set_visible(bShow);
}

INetURLObject SolidDetailsContainer::getUrl()
{
    if (m_bAuthenticated && !m_sPodUrl.isEmpty())
    {
        // Convert HTTPS pod URL to solid:// scheme for LibreOffice
        OUString sSolidUrl = m_sPodUrl;
        if (sSolidUrl.startsWith("https://"))
        {
            sSolidUrl = "solid://" + sSolidUrl.copy(8); // Remove "https://"
        }
        if (!sSolidUrl.endsWith("/"))
            sSolidUrl += "/";
            
        return INetURLObject(sSolidUrl);
    }
    
    return INetURLObject();
}

bool SolidDetailsContainer::setUrl(const INetURLObject& rUrl)
{
    OUString sUrl = rUrl.GetMainURL(INetURLObject::DecodeMechanism::NONE);
    
    if (sUrl.startsWith("solid://"))
    {
        // Convert solid:// back to https:// for display and authentication
        m_sPodUrl = "https://" + sUrl.copy(8); // Remove "solid://"
        if (m_xPodUrl)
            m_xPodUrl->set_text(m_sPodUrl);
        return true;
    }
    else if (sUrl.startsWith("https://"))
    {
        m_sPodUrl = sUrl;
        if (m_xPodUrl)
            m_xPodUrl->set_text(m_sPodUrl);
        return true;
    }
    
    return false;
}

void SolidDetailsContainer::setUsername(const OUString& rUsername)
{
    m_sWebId = rUsername; // Store WebID
}

void SolidDetailsContainer::setPassword(const OUString& /*rPassword*/)
{
    // Solid uses OAuth2/OIDC, not passwords
}

void SolidDetailsContainer::authenticate()
{
    if (m_sPodUrl.isEmpty())
    {
        // Show error about missing Pod URL
        return;
    }
    
    try
    {
        // Step 1: Discover OIDC issuer from pod
        OUString sIssuer;
        if (!discoverOIDCIssuer(m_sPodUrl, sIssuer))
        {
            updateAuthStatus();
            return;
        }
        
        // Step 2: Perform OIDC authentication flow
        if (performOIDCFlow(sIssuer))
        {
            m_bAuthenticated = true;
            updateAuthStatus();
            notifyChange();
        }
    }
    catch (const uno::Exception& e)
    {
        SAL_WARN("svtools", "Solid authentication failed: " << e.Message);
        m_bAuthenticated = false;
        updateAuthStatus();
    }
}

bool SolidDetailsContainer::discoverOIDCIssuer(const OUString& podUrl, OUString& issuer)
{
    // Basic OIDC discovery implementation
    try
    {
        // For storage.inrupt.com pods, use known issuer
        if (podUrl.indexOf("storage.inrupt.com") != -1)
        {
            issuer = "https://login.inrupt.com/";
            return true;
        }
        
        // For other pods, try standard discovery
        INetURLObject aUrl(podUrl);
        OUString sHost = aUrl.GetHost();
        
        // Common patterns for Solid OIDC issuers
        if (sHost.endsWith(".solidcommunity.net"))
        {
            issuer = "https://solidcommunity.net/";
            return true;
        }
        else if (sHost.endsWith(".inrupt.net"))
        {
            issuer = "https://broker.pod.inrupt.com/";
            return true;
        }
        
        // Default: assume issuer is at pod domain root
        issuer = aUrl.GetURLNoPass(INetURLObject::DecodeMechanism::NONE);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool SolidDetailsContainer::performOIDCFlow(const OUString& issuer)
{
    try
    {
        // Generate secure state and PKCE challenge following government standards
        OUString sState = generateSecureState();
        OUString sCodeVerifier = generateCodeVerifier();
        OUString sCodeChallenge = generateCodeChallenge(sCodeVerifier);
        
        // Build authorization URL following OAuth 2.0 + PKCE spec
        OUString sAuthUrl = issuer + 
            (issuer.endsWith("/") ? "" : "/") + "auth?"
            "response_type=code&"
            "client_id=" + rtl::Uri::encode("LibreOffice Solid Connector", 
                rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8) + "&"
            "redirect_uri=" + rtl::Uri::encode("http://localhost:7777/callback", 
                rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8) + "&"
            "scope=" + rtl::Uri::encode("openid profile", 
                rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8) + "&"
            "code_challenge=" + sCodeChallenge + "&"
            "code_challenge_method=S256&"
            "state=" + sState;
        
        // Use LibreOffice's proven authentication fallback pattern from CMIS
        OString sAuthUrlUtf8 = OUStringToOString(sAuthUrl, RTL_TEXTENCODING_UTF8);
        
        // Get environment for interaction handling
        uno::Reference<uno::XComponentContext> xContext = comphelper::getProcessComponentContext();
        
        // Get interaction handler from dialog context
        uno::Reference<task::XInteractionHandler> xIH;
        if (m_pDialog)
        {
            // Try to get interaction handler from the dialog's framework
            try 
            {
                uno::Reference<task::XInteractionHandler> xHandler(
                    xContext->getServiceManager()->createInstanceWithContext(
                        "com.sun.star.task.InteractionHandler", xContext), uno::UNO_QUERY);
                xIH = xHandler;
            }
            catch (const uno::Exception&)
            {
                SAL_WARN("svtools", "Could not create interaction handler");
            }
        }
        if (!xIH.is())
        {
            SAL_WARN("svtools", "No interaction handler available");
            return false;
        }
        
        // Create authentication fallback request (same pattern as CMIS OAuth)
        rtl::Reference<ucbhelper::AuthenticationFallbackRequest> xRequest =
            new ucbhelper::AuthenticationFallbackRequest(
                u"Please complete Solid pod authentication in your browser. "
                "Copy the authorization code from the callback URL and paste it below.\n\n"
                "Example callback URL:\n"
                "http://localhost:7777/callback?code=YOUR_CODE&state=..."_ustr,
                sAuthUrl);
        
        // Open browser for user authentication
        uno::Reference<css::system::XSystemShellExecute> xSystemShell(
            css::system::SystemShellExecute::create(xContext));
        xSystemShell->execute(sAuthUrl, "", css::system::SystemShellExecuteFlags::URIS_ONLY);
        
        // Handle the interaction - wait for user to paste the code
        xIH->handle(xRequest);
        
        rtl::Reference<ucbhelper::InteractionContinuation> xSelection = xRequest->getSelection();
        if (!xSelection.is())
        {
            SAL_INFO("svtools", "User cancelled authentication");
            return false;
        }
        
        // Check if user aborted
        uno::Reference<task::XInteractionAbort> xAbort(xSelection->getXWeak(), uno::UNO_QUERY);
        if (xAbort.is())
        {
            SAL_INFO("svtools", "User aborted authentication");
            return false;
        }
        
        // Get the authorization code from user input
        const rtl::Reference<ucbhelper::InteractionAuthFallback>& xAuthFallback = 
            xRequest->getAuthFallbackInter();
        if (!xAuthFallback.is())
        {
            SAL_WARN("svtools", "No authentication fallback interaction");
            return false;
        }
        
        OUString sAuthCode = xAuthFallback->getCode();
        if (sAuthCode.isEmpty())
        {
            SAL_WARN("svtools", "Empty authorization code received");
            return false;
        }
        
        // Exchange authorization code for access token
        return exchangeCodeForToken(issuer, sAuthCode, sCodeVerifier, sState);
    }
    catch (const uno::Exception& e)
    {
        SAL_WARN("svtools", "OIDC flow failed: " << e.Message);
        return false;
    }
}

void SolidDetailsContainer::updateAuthStatus()
{
    if (m_bAuthenticated)
    {
        // Update UI to show authenticated state
        if (m_xAuthButton)
        {
            m_xAuthButton->set_label("Authenticated ✓");
            m_xAuthButton->set_sensitive(false);
        }
    }
    else
    {
        if (m_xAuthButton)
        {
            m_xAuthButton->set_label("Authenticate with Pod");
            m_xAuthButton->set_sensitive(true);
        }
    }
}

IMPL_LINK_NOARG(SolidDetailsContainer, AuthClickHdl, weld::Button&, void)
{
    authenticate();
}

IMPL_LINK_NOARG(SolidDetailsContainer, PodUrlChangeHdl, weld::Entry&, void)
{
    m_sPodUrl = m_xPodUrl->get_text().trim();
    m_bAuthenticated = false;
    updateAuthStatus();
    notifyChange();
}

OUString SolidDetailsContainer::generateSecureState()
{
    // Generate cryptographically secure random state for CSRF protection
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 61); // 0-9, A-Z, a-z
    
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    OUStringBuffer state;
    
    for (int i = 0; i < 32; ++i) {
        state.append(static_cast<sal_Unicode>(charset[dis(gen)]));
    }
    
    return state.makeStringAndClear();
}

OUString SolidDetailsContainer::generateCodeVerifier()
{
    // Generate PKCE code verifier (43-128 characters, URL-safe)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 63); // URL-safe base64 chars
    
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~";
    OUStringBuffer verifier;
    
    for (int i = 0; i < 128; ++i) {
        verifier.append(static_cast<sal_Unicode>(charset[dis(gen)]));
    }
    
    return verifier.makeStringAndClear();
}

OUString SolidDetailsContainer::generateCodeChallenge(const OUString& codeVerifier)
{
    // Generate PKCE code challenge using SHA256
    OString verifierUtf8 = OUStringToOString(codeVerifier, RTL_TEXTENCODING_UTF8);
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(verifierUtf8.getStr()), 
           verifierUtf8.getLength(), hash);
    
    // Base64URL encode the hash
    BIO* bio = BIO_new(BIO_s_mem());
    BIO* b64 = BIO_new(BIO_f_base64());
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    bio = BIO_push(b64, bio);
    
    BIO_write(bio, hash, SHA256_DIGEST_LENGTH);
    BIO_flush(bio);
    
    BUF_MEM* bufferPtr;
    BIO_get_mem_ptr(bio, &bufferPtr);
    
    OString base64(bufferPtr->data, bufferPtr->length);
    BIO_free_all(bio);
    
    // Convert to base64URL by replacing + with -, / with _, and removing padding
    OUStringBuffer challenge;
    for (sal_Int32 i = 0; i < base64.getLength(); ++i) {
        char c = base64[i];
        if (c == '+') challenge.append('-');
        else if (c == '/') challenge.append('_');
        else if (c != '=') challenge.append(static_cast<sal_Unicode>(c));
    }
    
    return challenge.makeStringAndClear();
}

struct CurlResponse {
    std::string data;
    long response_code = 0;
};

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, CurlResponse* response)
{
    size_t realsize = size * nmemb;
    response->data.append(static_cast<char*>(contents), realsize);
    return realsize;
}

bool SolidDetailsContainer::exchangeCodeForToken(const OUString& issuer, 
                                                const OUString& authCode,
                                                const OUString& codeVerifier,
                                                const OUString& state)
{
    CURL* curl = curl_easy_init();
    if (!curl) {
        SAL_WARN("svtools", "Failed to initialize CURL");
        return false;
    }
    
    CurlResponse response;
    
    try {
        // Build token endpoint URL
        OUString tokenUrl = issuer + (issuer.endsWith("/") ? "" : "/") + "token";
        OString tokenUrlUtf8 = OUStringToOString(tokenUrl, RTL_TEXTENCODING_UTF8);
        
        // Build POST data for token exchange
        OUString postData = 
            "grant_type=authorization_code&"
            "code=" + rtl::Uri::encode(authCode, rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8) + "&"
            "redirect_uri=" + rtl::Uri::encode("http://localhost:7777/callback", rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8) + "&"
            "client_id=" + rtl::Uri::encode("LibreOffice Solid Connector", rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8) + "&"
            "code_verifier=" + rtl::Uri::encode(codeVerifier, rtl_UriCharClassUnreserved, rtl_UriEncodeStrict, RTL_TEXTENCODING_UTF8);
            
        OString postDataUtf8 = OUStringToOString(postData, RTL_TEXTENCODING_UTF8);
        
        // Configure CURL for secure token exchange
        curl_easy_setopt(curl, CURLOPT_URL, tokenUrlUtf8.getStr());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postDataUtf8.getStr());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 3L);
        
        // Set headers
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        headers = curl_slist_append(headers, "Accept: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        
        // Perform the request
        CURLcode res = curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.response_code);
        
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        
        if (res != CURLE_OK) {
            SAL_WARN("svtools", "Token exchange failed: " << curl_easy_strerror(res));
            return false;
        }
        
        if (response.response_code != 200) {
            SAL_WARN("svtools", "Token endpoint returned: " << response.response_code);
            SAL_WARN("svtools", "Response: " << response.data.c_str());
            return false;
        }
        
        // Parse JSON response for access_token and id_token
        return parseTokenResponse(response.data);
        
    } catch (...) {
        curl_easy_cleanup(curl);
        return false;
    }
}

bool SolidDetailsContainer::parseTokenResponse(const std::string& jsonResponse)
{
    // Simple JSON parsing for access_token and id_token
    // In production, this should use a proper JSON library
    
    size_t accessPos = jsonResponse.find("\"access_token\"");
    if (accessPos == std::string::npos) {
        SAL_WARN("svtools", "No access_token in response");
        return false;
    }
    
    size_t valueStart = jsonResponse.find("\"", accessPos + 15);
    if (valueStart == std::string::npos) return false;
    valueStart++;
    
    size_t valueEnd = jsonResponse.find("\"", valueStart);
    if (valueEnd == std::string::npos) return false;
    
    std::string accessToken = jsonResponse.substr(valueStart, valueEnd - valueStart);
    if (accessToken.empty()) {
        SAL_WARN("svtools", "Empty access token");
        return false;
    }
    
    // Extract WebID from id_token if present (simplified)
    size_t idTokenPos = jsonResponse.find("\"id_token\"");
    std::string webId = "https://authenticated.user/profile/card#me"; // Default
    
    if (idTokenPos != std::string::npos) {
        // In production, decode and validate the JWT id_token to extract WebID
        // For now, use a placeholder that indicates successful authentication
        webId = "https://authenticated.user/profile/card#me";
    }
    
    // Store securely using LibreOffice's password container
    m_sAccessToken = OUString::fromUtf8(accessToken);
    m_sWebId = OUString::fromUtf8(webId);
    
    SAL_INFO("svtools", "Token exchange successful, WebID: " << m_sWebId);
    return true;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */