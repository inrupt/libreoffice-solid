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
#include <tools/urlobj.hxx>
#include <sal/log.hxx>

using namespace com::sun::star;

namespace solid_ucp
{

// Content type detection helper
OUString detectContentType(const OUString& rURL) {
    if (rURL.endsWithIgnoreAsciiCase(".odt")) return "application/vnd.oasis.opendocument.text";
    if (rURL.endsWithIgnoreAsciiCase(".ods")) return "application/vnd.oasis.opendocument.spreadsheet";
    if (rURL.endsWithIgnoreAsciiCase(".odp")) return "application/vnd.oasis.opendocument.presentation";
    if (rURL.endsWithIgnoreAsciiCase(".odg")) return "application/vnd.oasis.opendocument.graphics";
    if (rURL.endsWithIgnoreAsciiCase(".pdf")) return "application/pdf";
    if (rURL.endsWithIgnoreAsciiCase(".txt")) return "text/plain";
    if (rURL.endsWithIgnoreAsciiCase(".html")) return "text/html";
    if (rURL.endsWithIgnoreAsciiCase(".jpg") || rURL.endsWithIgnoreAsciiCase(".jpeg")) return "image/jpeg";
    if (rURL.endsWithIgnoreAsciiCase(".png")) return "image/png";
    return "application/octet-stream";
}

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

} // namespace solid_ucp