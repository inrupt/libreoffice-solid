/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidHttpSession.hxx"
#include "SolidInputStream.hxx"
#include <tools/urlobj.hxx>
#include <rtl/uri.hxx>
#include <comphelper/processfactory.hxx>
#include <com/sun/star/system/SystemShellExecute.hpp>
#include <com/sun/star/system/SystemShellExecuteFlags.hpp>
#include <sal/log.hxx>
#include <curl/curl.h>
#include <string>
#include <vector>
#include <memory>

using namespace com::sun::star;

namespace solid_ucp
{

SolidHttpSession::SolidHttpSession(const uno::Reference<uno::XComponentContext>& xContext)
    : m_bAuthenticated(false)
    , m_xContext(xContext)
{
}

SolidHttpSession::SolidHttpSession(const OUString& rPodUrl, const uno::Reference<uno::XComponentContext>& xContext)
    : m_sPodUrl(rPodUrl)
    , m_bAuthenticated(false)
    , m_xContext(xContext)
{
}

SolidHttpSession::~SolidHttpSession()
{
}

// Authentication following NextFM authentication.js patterns
bool SolidHttpSession::authenticate(const OUString& rIssuer)
{
    try
    {
        // Step 1: Discover OIDC issuer from pod (following NextFM)
        OUString sIssuer;
        if (!discoverOIDCIssuer(m_sPodUrl, sIssuer))
        {
            return false;
        }
        
        // Step 2: Perform OIDC authentication flow
        if (performOIDCFlow(sIssuer))
        {
            m_bAuthenticated = true;
            return true;
        }
    }
    catch (const uno::Exception& e)
    {
        SAL_WARN("ucb.ucp.solid", "Solid authentication failed: " << e.Message);
        m_bAuthenticated = false;
    }
    
    return false;
}

bool SolidHttpSession::discoverOIDCIssuer(const OUString& rPodUrl, OUString& rIssuer)
{
    // Basic OIDC discovery implementation following NextFM patterns
    try
    {
        // For storage.inrupt.com pods, use known issuer (NextFM pattern)
        if (rPodUrl.indexOf("storage.inrupt.com") != -1)
        {
            rIssuer = "https://login.inrupt.com/";
            return true;
        }
        
        // For other pods, try standard discovery
        INetURLObject aUrl(rPodUrl);
        OUString sHost = aUrl.GetHost();
        
        // Common patterns for Solid OIDC issuers (following NextFM)
        if (sHost.endsWith(".solidcommunity.net"))
        {
            rIssuer = "https://solidcommunity.net/";
            return true;
        }
        else if (sHost.endsWith(".inrupt.net"))
        {
            rIssuer = "https://broker.pod.inrupt.com/";
            return true;
        }
        
        // Default: assume issuer is at pod domain root
        rIssuer = aUrl.GetURLNoPass(INetURLObject::DecodeMechanism::NONE);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool SolidHttpSession::performOIDCFlow(const OUString& rIssuer)
{
    try
    {
        // Create authorization URL (following NextFM authentication.js)
        OUString sAuthUrl = rIssuer + "auth?"
            "response_type=code&"
            "client_id=http://localhost:3000/&"  // Simple client ID
            "redirect_uri=http://localhost:3000/callback&"
            "scope=openid profile&"
            "state=libreoffice_solid";
            
        // Open browser for authentication (NextFM pattern)
        uno::Reference<css::system::XSystemShellExecute> xSystemShell(
            css::system::SystemShellExecute::create(m_xContext));
            
        xSystemShell->execute(sAuthUrl, "",
            css::system::SystemShellExecuteFlags::URIS_ONLY);
        
        // Note: In a complete implementation, this would:
        // 1. Start a local HTTP server to receive the callback
        // 2. Parse the authorization code
        // 3. Exchange code for access token
        // 4. Store the token securely
        
        // For demo purposes, simulate successful authentication
        m_sAccessToken = "demo_access_token";
        m_sWebId = "https://example.com/profile#me";
        m_sIssuer = rIssuer;
        
        return true;
    }
    catch (const uno::Exception&)
    {
        return false;
    }
}

// HTTP operations following @inrupt/solid-client patterns
uno::Reference<io::XInputStream> SolidHttpSession::httpGET(const OUString& rUrl)
{
    return executeHttpRequest(rUrl, "GET");
}

void SolidHttpSession::httpPUT(const OUString& rUrl, const uno::Reference<io::XInputStream>& rData, const OUString& rContentType)
{
    executeHttpRequest(rUrl, "PUT", rData, rContentType);
}

void SolidHttpSession::httpPOST(const OUString& rUrl, const uno::Reference<io::XInputStream>& rData, const OUString& rContentType)
{
    executeHttpRequest(rUrl, "POST", rData, rContentType);
}

void SolidHttpSession::httpDELETE(const OUString& rUrl)
{
    executeHttpRequest(rUrl, "DELETE");
}

void SolidHttpSession::httpHEAD(const OUString& rUrl, OUString& rContentType, sal_Int64& rSize)
{
    // Execute HEAD request and parse response headers
    executeHttpRequest(rUrl, "HEAD");
    
    // Note: In complete implementation, would parse response headers
    // to extract Content-Type and Content-Length
    rContentType = "application/octet-stream";
    rSize = 0;
}

// Solid-specific operations matching @inrupt/solid-client
uno::Sequence<OUString> SolidHttpSession::getSolidDataset(const OUString& rContainerUrl)
{
    // Implementation would parse Turtle/JSON-LD response from container
    // and extract contained resource URLs (following getSolidDataset pattern)
    
    uno::Sequence<OUString> aResult;
    
    try
    {
        uno::Reference<io::XInputStream> xResponse = httpGET(rContainerUrl);
        
        // Note: Complete implementation would:
        // 1. Parse the container's Turtle/JSON-LD content
        // 2. Extract ldp:contains relationships
        // 3. Return array of contained resource URLs
        
        // For demo, return empty sequence
        aResult.realloc(0);
    }
    catch (const uno::Exception&)
    {
        aResult.realloc(0);
    }
    
    return aResult;
}

bool SolidHttpSession::createContainerAt(const OUString& rContainerUrl)
{
    try
    {
        // Create container using PUT with text/turtle content-type
        // (following createContainerAt pattern from @inrupt/solid-client)
        OUString sEmptyContainer = "";
        
        uno::Reference<io::XInputStream> xData; // Empty stream for container creation
        httpPUT(rContainerUrl, xData, "text/turtle");
        
        return true;
    }
    catch (const uno::Exception&)
    {
        return false;
    }
}

bool SolidHttpSession::getResourceInfo(const OUString& rUrl, OUString& rContentType, sal_Int64& rSize, bool& rIsContainer)
{
    try
    {
        httpHEAD(rUrl, rContentType, rSize);
        
        // Check if it's a container based on Content-Type or Link headers
        // (following getResourceInfo pattern)
        rIsContainer = rContentType.indexOf("text/turtle") != -1;
        
        return true;
    }
    catch (const uno::Exception&)
    {
        return false;
    }
}

bool SolidHttpSession::isContainer(const OUString& rUrl)
{
    OUString sContentType;
    sal_Int64 nSize;
    bool bIsContainer = false;
    
    return getResourceInfo(rUrl, sContentType, nSize, bIsContainer) && bIsContainer;
}

// File operations matching NextFM fileOperations.js patterns
void SolidHttpSession::saveFileInContainer(const OUString& rContainerUrl, const uno::Reference<io::XInputStream>& rData, 
                                         const OUString& rSlug, const OUString& rContentType)
{
    // Following saveFileInContainer pattern from @inrupt/solid-client
    OUString sFileUrl = rContainerUrl;
    if (!sFileUrl.endsWith("/"))
        sFileUrl += "/";
    sFileUrl += rSlug;
    
    httpPUT(sFileUrl, rData, rContentType);
}

void SolidHttpSession::deleteFile(const OUString& rFileUrl)
{
    // Following deleteFile pattern from @inrupt/solid-client
    httpDELETE(rFileUrl);
}

void SolidHttpSession::deleteSolidDataset(const OUString& rContainerUrl)
{
    // Following deleteSolidDataset pattern from @inrupt/solid-client
    httpDELETE(rContainerUrl);
}

// Storage validation following NextFM StorageUtils.js patterns
OUString SolidHttpSession::getValidStorageBaseUrl()
{
    if (!m_sIssuer.isEmpty())
    {
        INetURLObject aUrl(m_sIssuer);
        OUString sDomain = aUrl.GetHost();
        
        // First replace openid. (if it exists) - NextFM pattern
        OUString sStorageDomain = sDomain.replaceAll("openid.", "");
        // Then replace oidc. (if it exists) - NextFM pattern
        sStorageDomain = sStorageDomain.replaceAll("oidc.", "");
        // Finally add storage. - NextFM pattern
        return "https://storage." + sStorageDomain;
    }
    return "https://storage.inrupt.com";
}

bool SolidHttpSession::validateStorageUrl(const OUString& rUrl)
{
    OUString sValidBase = getValidStorageBaseUrl();
    return rUrl.startsWith(sValidBase);
}

OUString SolidHttpSession::getProvisionBaseUrl()
{
    OUString sStorageBaseUrl = getValidStorageBaseUrl();
    return sStorageBaseUrl.replaceAll("storage.", "provision.");
}

// Utility methods
OUString SolidHttpSession::resolveUrl(const OUString& rBaseUrl, const OUString& rPath)
{
    INetURLObject aBase(rBaseUrl);
    aBase.insertName(rPath);
    return aBase.GetMainURL(INetURLObject::DecodeMechanism::NONE);
}

// HTTP response data structure
struct HttpResponse
{
    std::string data;
    long httpCode;
    std::string contentType;
};

// CURL callback function
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t totalSize = size * nmemb;
    static_cast<std::string*>(userp)->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// CURL header callback
static size_t HeaderCallback(char* buffer, size_t size, size_t nitems, void* userdata)
{
    size_t totalSize = size * nitems;
    std::string header(buffer, totalSize);
    
    // Extract Content-Type
    if (header.find("Content-Type:") == 0)
    {
        size_t colonPos = header.find(':');
        if (colonPos != std::string::npos)
        {
            std::string contentType = header.substr(colonPos + 1);
            // Trim whitespace
            size_t start = contentType.find_first_not_of(" \t\r\n");
            size_t end = contentType.find_last_not_of(" \t\r\n");
            if (start != std::string::npos && end != std::string::npos)
            {
                contentType = contentType.substr(start, end - start + 1);
                static_cast<HttpResponse*>(userdata)->contentType = contentType;
            }
        }
    }
    
    return totalSize;
}

// Private implementation methods
uno::Reference<io::XInputStream> SolidHttpSession::executeHttpRequest(
    const OUString& rUrl, 
    const OUString& rMethod,
    const uno::Reference<io::XInputStream>& rData,
    const OUString& rContentType,
    const uno::Reference<ucb::XCommandEnvironment>& rEnv)
{
    SAL_INFO("ucb.ucp.solid", "HTTP " << rMethod << " " << rUrl);
    
    CURL* curl = curl_easy_init();
    if (!curl)
    {
        SAL_WARN("ucb.ucp.solid", "Failed to initialize CURL");
        throw uno::RuntimeException("HTTP client initialization failed");
    }
    
    HttpResponse response;
    
    try
    {
        // Convert URL to UTF-8
        OString sUrl = OUStringToOString(rUrl, RTL_TEXTENCODING_UTF8);
        curl_easy_setopt(curl, CURLOPT_URL, sUrl.getStr());
        
        // Set HTTP method
        if (rMethod == "GET")
        {
            curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
        }
        else if (rMethod == "PUT")
        {
            curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        }
        else if (rMethod == "POST")
        {
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
        }
        else if (rMethod == "DELETE")
        {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        }
        else if (rMethod == "HEAD")
        {
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        }
        
        // Set up headers
        struct curl_slist* headers = nullptr;
        
        // Add authentication header if we have a token
        if (m_bAuthenticated && !m_sAccessToken.isEmpty())
        {
            OString authHeader = "Authorization: Bearer " + 
                OUStringToOString(m_sAccessToken, RTL_TEXTENCODING_UTF8);
            headers = curl_slist_append(headers, authHeader.getStr());
            SAL_INFO("ucb.ucp.solid", "Added auth header");
        }
        
        // Add content type for PUT/POST
        if ((rMethod == "PUT" || rMethod == "POST") && !rContentType.isEmpty())
        {
            OString contentTypeHeader = "Content-Type: " + 
                OUStringToOString(rContentType, RTL_TEXTENCODING_UTF8);
            headers = curl_slist_append(headers, contentTypeHeader.getStr());
        }
        
        // Add Solid-specific headers
        headers = curl_slist_append(headers, "Accept: */*");
        headers = curl_slist_append(headers, "User-Agent: LibreOffice-Solid/1.0");
        
        if (headers)
        {
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        }
        
        // Set up data callbacks
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.data);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, HeaderCallback);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &response);
        
        // Handle request data for PUT/POST
        std::string requestData;
        if ((rMethod == "PUT" || rMethod == "POST") && rData.is())
        {
            // Read all data from input stream
            const sal_Int32 nBufferSize = 8192;
            uno::Sequence<sal_Int8> aBuffer(nBufferSize);
            sal_Int32 nRead;
            
            while ((nRead = rData->readBytes(aBuffer, nBufferSize)) > 0)
            {
                requestData.append(reinterpret_cast<const char*>(aBuffer.getConstArray()), nRead);
            }
            
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, requestData.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, requestData.length());
        }
        
        // SSL options
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);
        
        // Timeout settings
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
        
        // Follow redirects
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 5L);
        
        // Execute the request
        CURLcode res = curl_easy_perform(curl);
        
        // Get response code
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.httpCode);
        
        // Clean up
        if (headers)
        {
            curl_slist_free_all(headers);
        }
        curl_easy_cleanup(curl);
        
        // Check for errors
        if (res != CURLE_OK)
        {
            SAL_WARN("ucb.ucp.solid", "CURL error: " << curl_easy_strerror(res));
            throw uno::RuntimeException("HTTP request failed: " + OUString::createFromAscii(curl_easy_strerror(res)));
        }
        
        if (response.httpCode >= 400)
        {
            SAL_WARN("ucb.ucp.solid", "HTTP error " << response.httpCode << " for " << rUrl);
            throw uno::RuntimeException("HTTP error " + OUString::number(response.httpCode));
        }
        
        SAL_INFO("ucb.ucp.solid", "HTTP " << rMethod << " success: " << response.httpCode 
                 << ", " << response.data.length() << " bytes");
        
        // For methods that return data, create input stream
        if (rMethod == "GET" || rMethod == "POST")
        {
            OString responseData(response.data.c_str(), response.data.length());
            return new SolidInputStream(responseData);
        }
        
        // For PUT/DELETE, return empty stream
        return uno::Reference<io::XInputStream>();
    }
    catch (...)
    {
        curl_easy_cleanup(curl);
        throw;
    }
}

void SolidHttpSession::addAuthHeaders(uno::Sequence<beans::NamedValue>& rHeaders)
{
    if (m_bAuthenticated && !m_sAccessToken.isEmpty())
    {
        // Add Authorization header with Bearer token (Solid pattern)
        sal_Int32 nLen = rHeaders.getLength();
        rHeaders.realloc(nLen + 1);
        rHeaders.getArray()[nLen].Name = "Authorization";
        rHeaders.getArray()[nLen].Value <<= OUString("Bearer " + m_sAccessToken);
    }
}

// Domain validation following NextFM patterns
bool SolidHttpSession::isValidInruptDomain(const OUString& rHostname)
{
    return rHostname.endsWith(".inrupt.com") && 
           rHostname.indexOf('.') != rHostname.lastIndexOf('.');
}

bool SolidHttpSession::isValidEndSessionUrl(const OUString& rUrl)
{
    try
    {
        INetURLObject aUrl(rUrl);
        return aUrl.GetProtocol() == INetProtocol::Https && 
               isValidInruptDomain(aUrl.GetHost());
    }
    catch (...)
    {
        return false;
    }
}

bool SolidHttpSession::isValidDomain(const OUString& rHostname)
{
    // Basic security check - ensure at least one subdomain (NextFM pattern)
    return rHostname.indexOf('.') != -1;
}

} // namespace solid_ucp