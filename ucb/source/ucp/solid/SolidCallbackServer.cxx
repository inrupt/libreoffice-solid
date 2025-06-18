/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidCallbackServer.hxx"
#include <sal/log.hxx>
#include <rtl/random.h>
#include <rtl/strbuf.hxx>
#include <chrono>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#endif

using namespace std::chrono_literals;

namespace solid { namespace libreoffice
{

SolidCallbackServer::SolidCallbackServer()
    : m_nPort(0)
    , m_bCodeReceived(false)
    , m_bStopped(false)
{
#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
}

SolidCallbackServer::~SolidCallbackServer()
{
    stop();
#ifdef _WIN32
    WSACleanup();
#endif
}

sal_uInt16 SolidCallbackServer::start()
{
    if (m_serverThread.joinable())
        return m_nPort;
        
    m_nPort = findAvailablePort();
    if (m_nPort == 0)
    {
        SAL_WARN("ucb.ucp.solid", "Failed to find available port for callback server");
        return 0;
    }
    
    m_bStopped = false;
    m_bCodeReceived = false;
    m_sState = generateState();
    
    m_serverThread = std::thread(&SolidCallbackServer::serverLoop, this);
    
    return m_nPort;
}

OUString SolidCallbackServer::waitForCode(sal_uInt32 timeoutMs)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    
    bool success = m_condition.wait_for(lock, std::chrono::milliseconds(timeoutMs),
                                       [this] { return m_bCodeReceived || m_bStopped; });
    
    if (success && m_bCodeReceived)
    {
        return m_sAuthCode;
    }
    
    return OUString(); // Timeout or stopped
}

void SolidCallbackServer::stop()
{
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_bStopped = true;
    }
    m_condition.notify_all();
    
    if (m_serverThread.joinable())
    {
        m_serverThread.join();
    }
}

void SolidCallbackServer::serverLoop()
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        SAL_WARN("ucb.ucp.solid", "Failed to create socket");
        return;
    }
    
    // Set socket options
    int opt = 1;
#ifdef _WIN32
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
#else
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
#endif
    
    // Bind to localhost on the specified port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = htons(m_nPort);
    
    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        SAL_WARN("ucb.ucp.solid", "Failed to bind to port " << m_nPort);
#ifdef _WIN32
        closesocket(serverSocket);
#else
        close(serverSocket);
#endif
        return;
    }
    
    if (listen(serverSocket, 1) < 0)
    {
        SAL_WARN("ucb.ucp.solid", "Failed to listen on socket");
#ifdef _WIN32
        closesocket(serverSocket);
#else
        close(serverSocket);
#endif
        return;
    }
    
    // Set socket to non-blocking for timeout handling
#ifdef _WIN32
    u_long mode = 1;
    ioctlsocket(serverSocket, FIONBIO, &mode);
#else
    fcntl(serverSocket, F_SETFL, O_NONBLOCK);
#endif
    
    // Wait for connection with timeout
    while (!m_bStopped)
    {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(serverSocket, &readfds);
        
        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000; // 100ms
        
        int activity = select(serverSocket + 1, &readfds, nullptr, nullptr, &timeout);
        
        if (activity > 0 && FD_ISSET(serverSocket, &readfds))
        {
            struct sockaddr_in clientAddr;
            socklen_t clientLen = sizeof(clientAddr);
            int clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientLen);
            
            if (clientSocket >= 0)
            {
                char buffer[4096] = {0};
                int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
                
                if (bytesRead > 0)
                {
                    OString request(buffer, bytesRead);
                    handleRequest(request);
                }
                
#ifdef _WIN32
                closesocket(clientSocket);
#else
                close(clientSocket);
#endif
                break; // Only handle one request
            }
        }
    }
    
#ifdef _WIN32
    closesocket(serverSocket);
#else
    close(serverSocket);
#endif
}

void SolidCallbackServer::handleRequest(const OString& request)
{
    
    // Extract authorization code and state from query parameters
    OUString sCode = extractParameterValue(request, "code");
    OUString sState = extractParameterValue(request, "state");
    OUString sError = extractParameterValue(request, "error");
    
    OUString sResponse;
    
    if (!sError.isEmpty())
    {
        SAL_WARN("ucb.ucp.solid", "OIDC error: " << sError);
        sResponse = generateErrorPage("Authentication failed: " + sError);
    }
    else if (sCode.isEmpty())
    {
        SAL_WARN("ucb.ucp.solid", "No authorization code received");
        sResponse = generateErrorPage("No authorization code received");
    }
    else if (sState != m_sState)
    {
        SAL_WARN("ucb.ucp.solid", "State parameter mismatch - possible CSRF attack");
        sResponse = generateErrorPage("Invalid state parameter");
    }
    else
    {
        // Success!
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_sAuthCode = sCode;
            m_bCodeReceived = true;
        }
        m_condition.notify_all();
        
        sResponse = generateSuccessPage();
    }
    
    // Send HTTP response (simplified)
    OString sHttpResponse = "HTTP/1.1 200 OK\r\n"
                           "Content-Type: text/html; charset=utf-8\r\n"
                           "Connection: close\r\n\r\n" +
                           OUStringToOString(sResponse, RTL_TEXTENCODING_UTF8);
    
    // Note: In complete implementation, would send this response back to client
    // For now, just log it
}

OUString SolidCallbackServer::extractParameterValue(const OString& request, const OString& paramName)
{
    OString searchFor = paramName + "=";
    sal_Int32 pos = request.indexOf(searchFor);
    if (pos == -1)
        return OUString();
        
    pos += searchFor.getLength();
    sal_Int32 endPos = request.indexOf("&", pos);
    if (endPos == -1)
        endPos = request.indexOf(" ", pos); // End of query string
    if (endPos == -1)
        endPos = request.getLength();
        
    OString value = request.copy(pos, endPos - pos);
    
    // URL decode the value (simplified)
    value = value.replaceAll("%20", " ");
    value = value.replaceAll("%3D", "=");
    
    return OStringToOUString(value, RTL_TEXTENCODING_UTF8);
}

OUString SolidCallbackServer::generateSuccessPage()
{
    return OUString::createFromAscii("<!DOCTYPE html>"
           "<html><head><title>Authentication Successful</title>"
           "<style>body{font-family:Arial,sans-serif;text-align:center;padding:50px;}"
           ".success{color:green;font-size:24px;margin-bottom:20px;}</style></head>"
           "<body><div class='success'>Authentication Successful!</div>"
           "<p>You have successfully authenticated with your Solid pod.</p>"
           "<p>You can now close this window and return to LibreOffice.</p>"
           "</body></html>");
}

OUString SolidCallbackServer::generateErrorPage(const OUString& error)
{
    return OUString::createFromAscii("<!DOCTYPE html>"
           "<html><head><title>Authentication Error</title>"
           "<style>body{font-family:Arial,sans-serif;text-align:center;padding:50px;}"
           ".error{color:red;font-size:24px;margin-bottom:20px;}</style></head>"
           "<body><div class='error'>Authentication Failed</div>"
           "<p>") + error + OUString::createFromAscii("</p>"
           "<p>Please try again or contact support if the problem persists.</p>"
           "</body></html>");
}

sal_uInt16 SolidCallbackServer::findAvailablePort()
{
    // Try ports starting from 8080
    for (sal_uInt16 port = 8080; port < 8090; ++port)
    {
        int testSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (testSocket < 0)
            continue;
            
        struct sockaddr_in address;
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        address.sin_port = htons(port);
        
        int result = bind(testSocket, (struct sockaddr*)&address, sizeof(address));
        
#ifdef _WIN32
        closesocket(testSocket);
#else
        close(testSocket);
#endif
        
        if (result == 0)
        {
            return port; // Port is available
        }
    }
    
    return 0; // No available port found
}

OUString SolidCallbackServer::generateState()
{
    // Generate a random state parameter for CSRF protection
    rtlRandomPool pool = rtl_random_createPool();
    
    sal_uInt8 randomBytes[16];
    rtl_random_getBytes(pool, randomBytes, sizeof(randomBytes));
    
    rtl_random_destroyPool(pool);
    
    // Convert to hex string
    OStringBuffer stateBuffer;
    for (sal_uInt8 byte : randomBytes)
    {
        stateBuffer.append(static_cast<sal_Int32>(byte), 16);
    }
    
    return OStringToOUString(stateBuffer.makeStringAndClear(), RTL_TEXTENCODING_ASCII_US);
}

} // namespace libreoffice
} // namespace solid