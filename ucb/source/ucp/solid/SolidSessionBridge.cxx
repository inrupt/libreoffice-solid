/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidSession.hxx"
#include "SolidHttpSession.hxx"
#include <com/sun/star/io/XSeekable.hpp>
#include <comphelper/seqstream.hxx>
#include <tools/stream.hxx>

using namespace com::sun::star;

namespace solid_ucp
{

// Bridge implementation: Connect SolidSession methods to SolidHttpSession

void SolidSession::GET(SolidRequestEnvironment& rEnv)
{
    try
    {
        // Create HTTP session and set authentication
        SolidHttpSession httpSession(m_xContext);
        httpSession.setAccessToken(m_aAccessToken);
        httpSession.setWebId(m_aWebId);
        
        // Perform authenticated GET request
        uno::Reference<io::XInputStream> xResponse = httpSession.httpGET(rEnv.m_aRequestURI);
        
        // Store response in environment for caller
        rEnv.m_xInputStream = xResponse;
        
    }
    catch (const uno::Exception& e)
    {
        throw SolidRequestException("GET request failed: " + e.Message, SC_INTERNAL_SERVER_ERROR);
    }
}

void SolidSession::PUT(const uno::Reference<io::XInputStream>& xInputStream,
                       SolidRequestEnvironment& rEnv)
{
    try
    {
        // Create HTTP session and set authentication
        SolidHttpSession httpSession(m_xContext);
        httpSession.setAccessToken(m_aAccessToken);
        httpSession.setWebId(m_aWebId);
        
        // Detect content type based on URL extension
        OUString sContentType = detectContentType(rEnv.m_aRequestURI);
        
        // Perform authenticated PUT request
        httpSession.httpPUT(rEnv.m_aRequestURI, xInputStream, sContentType);
        
    }
    catch (const uno::Exception& e)
    {
        throw SolidRequestException("PUT request failed: " + e.Message, SC_INTERNAL_SERVER_ERROR);
    }
}

void SolidSession::POST(const uno::Reference<io::XInputStream>& xInputStream,
                        const OUString& rContentType,
                        const OUString& rReferer,
                        SolidRequestEnvironment& rEnv)
{
    try
    {
        // Create HTTP session and set authentication
        SolidHttpSession httpSession(m_xContext);
        httpSession.setAccessToken(m_aAccessToken);
        httpSession.setWebId(m_aWebId);
        
        // Use provided content type or detect it
        OUString sContentType = rContentType.isEmpty() ? detectContentType(rEnv.m_aRequestURI) : rContentType;
        
        // Perform authenticated POST request
        httpSession.httpPOST(rEnv.m_aRequestURI, xInputStream, sContentType);
        
    }
    catch (const uno::Exception& e)
    {
        throw SolidRequestException("POST request failed: " + e.Message, SC_INTERNAL_SERVER_ERROR);
    }
}

void SolidSession::DELETE(SolidRequestEnvironment& rEnv)
{
    try
    {
        // Create HTTP session and set authentication
        SolidHttpSession httpSession(m_xContext);
        httpSession.setAccessToken(m_aAccessToken);
        httpSession.setWebId(m_aWebId);
        
        // Perform authenticated DELETE request
        httpSession.httpDELETE(rEnv.m_aRequestURI);
        
    }
    catch (const uno::Exception& e)
    {
        throw SolidRequestException("DELETE request failed: " + e.Message, SC_INTERNAL_SERVER_ERROR);
    }
}

void SolidSession::MKCOL(SolidRequestEnvironment& rEnv)
{
    try
    {
        // Create HTTP session and set authentication
        SolidHttpSession httpSession(m_xContext);
        httpSession.setAccessToken(m_aAccessToken);
        httpSession.setWebId(m_aWebId);
        
        // Create container using Solid protocol
        bool bSuccess = httpSession.createContainerAt(rEnv.m_aRequestURI);
        if (!bSuccess)
        {
            throw SolidRequestException("Failed to create container", SC_INTERNAL_SERVER_ERROR);
        }
        
    }
    catch (const uno::Exception& e)
    {
        throw SolidRequestException("MKCOL request failed: " + e.Message, SC_INTERNAL_SERVER_ERROR);
    }
}

void SolidSession::HEAD(SolidRequestEnvironment& rEnv)
{
    try
    {
        // Create HTTP session and set authentication
        SolidHttpSession httpSession(m_xContext);
        httpSession.setAccessToken(m_aAccessToken);
        httpSession.setWebId(m_aWebId);
        
        // Perform HEAD request to get resource metadata
        OUString sContentType;
        sal_Int64 nSize;
        httpSession.httpHEAD(rEnv.m_aRequestURI, sContentType, nSize);
        
        // Store metadata for caller (would typically be in response headers)
        // Note: In complete implementation, would populate rEnv with metadata
        
    }
    catch (const uno::Exception& e)
    {
        throw SolidRequestException("HEAD request failed: " + e.Message, SC_INTERNAL_SERVER_ERROR);
    }
}

// Utility method to detect content type from URL
OUString SolidSession::detectContentType(const OUString& rUrl)
{
    // Extract file extension and map to MIME type
    sal_Int32 nDotPos = rUrl.lastIndexOf('.');
    if (nDotPos == -1)
        return "application/octet-stream";
        
    OUString sExtension = rUrl.copy(nDotPos + 1).toAsciiLowerCase();
    
    // Common MIME types for document formats
    if (sExtension == "odt")
        return "application/vnd.oasis.opendocument.text";
    else if (sExtension == "ods")
        return "application/vnd.oasis.opendocument.spreadsheet";
    else if (sExtension == "odp")
        return "application/vnd.oasis.opendocument.presentation";
    else if (sExtension == "pdf")
        return "application/pdf";
    else if (sExtension == "docx")
        return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
    else if (sExtension == "xlsx")
        return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
    else if (sExtension == "pptx")
        return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
    else if (sExtension == "txt")
        return "text/plain";
    else if (sExtension == "html" || sExtension == "htm")
        return "text/html";
    else if (sExtension == "xml")
        return "text/xml";
    else if (sExtension == "json")
        return "application/json";
    else if (sExtension == "ttl")
        return "text/turtle";  // Solid containers
    else
        return "application/octet-stream";
}

} // namespace solid_ucp