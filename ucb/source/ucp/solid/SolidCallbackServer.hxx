/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <rtl/ustring.hxx>
#include <sal/types.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace rtl;

namespace solid { namespace libreoffice
{

/**
 * Local HTTP callback server for OIDC authentication flow.
 * Receives the authorization code from the browser redirect.
 */
class SolidCallbackServer
{
private:
    sal_uInt16 m_nPort;
    OUString m_sAuthCode;
    OUString m_sState;
    std::thread m_serverThread;
    std::mutex m_mutex;
    std::condition_variable m_condition;
    bool m_bCodeReceived;
    bool m_bStopped;
    
public:
    SolidCallbackServer();
    ~SolidCallbackServer();
    
    /**
     * Start the callback server on an available port.
     * @return The port number the server is listening on
     */
    sal_uInt16 start();
    
    /**
     * Wait for the authorization code to be received.
     * @param timeoutMs Maximum time to wait in milliseconds
     * @return The authorization code, or empty string if timeout/error
     */
    OUString waitForCode(sal_uInt32 timeoutMs);
    
    /**
     * Stop the server and clean up resources.
     */
    void stop();
    
    /**
     * Get the port the server is listening on.
     */
    sal_uInt16 getPort() const { return m_nPort; }
    
    /**
     * Generate a random state parameter for CSRF protection.
     */
    static OUString generateState();
    
private:
    void serverLoop();
    void handleRequest(const OString& request, int clientSocket);
    OUString extractParameterValue(const OString& request, const OString& paramName);
    OUString generateSuccessPage();
    OUString generateErrorPage(const OUString& error);
    sal_uInt16 findAvailablePort();
};

} // namespace libreoffice
} // namespace solid