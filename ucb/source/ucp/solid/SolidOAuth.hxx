/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <sal/config.h>
#include <rtl/ustring.hxx>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/task/XInteractionHandler.hpp>
#include <vector>
#include <ctime>

using rtl::OUString;
namespace css = com::sun::star;

namespace solid { namespace libreoffice {

struct SolidOAuthTokens {
    OUString access_token;
    OUString id_token;
    OUString refresh_token;
    OUString webid;
    sal_Int64 expires_at = 0;
    
    // DPoP-specific fields
    OUString dpop_public_key_jwk;  // JWK representation of public key
    OUString dpop_private_key;     // Private key for signing DPoP tokens
    OUString dpop_key_thumbprint;  // SHA-256 thumbprint of public key
    
    bool isValid() const {
        return !access_token.isEmpty() && !webid.isEmpty();
    }
    
    bool isExpired() const {
        // Add 60 second buffer for clock skew
        return expires_at > 0 && (std::time(nullptr) + 60) >= expires_at;
    }
};

class SolidOAuthClient {
private:
    css::uno::Reference<css::uno::XComponentContext> m_xContext;
    OUString m_sPodUrl;
    OUString m_sClientId;
    OUString m_sIssuer;
    SolidOAuthTokens m_tokens;
    
    // OAuth2 + PKCE state
    OUString m_sCodeVerifier;
    OUString m_sCodeChallenge;
    OUString m_sState;
    
    // Error tracking
    OUString m_sLastError;
    
    // Helper methods
    OUString generateRandomString(sal_Int32 length = 32) const;
    OUString generateCodeChallenge(const OUString& verifier) const;
    bool discoverOIDCConfiguration(const OUString& podUrl, OUString& issuer, OUString& authEndpoint, OUString& tokenEndpoint) const;
    bool launchBrowserAuthentication(const OUString& authUrl) const;
    bool exchangeCodeForTokens(const OUString& code);
    bool exchangeCodeForTokens(const OUString& code, const OUString& redirectUri);
    
    // DPoP support methods
    bool generateDPoPKeyPair();
    OUString generateDPoPToken(const OUString& httpMethod, const OUString& url) const;
    OUString calculateJWKThumbprint(const OUString& jwk) const;
    
public:
    explicit SolidOAuthClient(const css::uno::Reference<css::uno::XComponentContext>& xContext);
    ~SolidOAuthClient();
    
    // Main authentication flow
    bool authenticate(const OUString& podUrl);
    
    // PodSpaces-specific functionality
    bool discoverPodStorageUrls(std::vector<OUString>& storageUrls) const;
    
    // Token management
    const SolidOAuthTokens& getTokens() const { return m_tokens; }
    bool refreshTokens();
    void clearTokens();
    
    // Secure token storage
    bool saveTokensToConfig();
    bool loadTokensFromConfig();
    void clearStoredTokens();
    
    // Authentication headers
    OUString getAuthorizationHeader() const;
    OUString getDPoPHeader(const OUString& httpMethod, const OUString& url) const;
    bool isAuthenticated() const;
    
    // Error handling
    OUString getLastError() const { return m_sLastError; }
    void setLastError(const OUString& error) { m_sLastError = error; }
};

} // namespace libreoffice
} // namespace solid

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */