/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <memory>
#include <vcl/weld.hxx>
#include <tools/urlobj.hxx>
#include <svtools/PlaceEditDialog.hxx>

class SolidDetailsContainer final : public DetailsContainer
{
private:
    std::unique_ptr<weld::Entry> m_xPodUrl;
    std::unique_ptr<weld::Button> m_xAuthButton;
    std::unique_ptr<weld::Label> m_xStatusLabel;
    
    OUString m_sPodUrl;
    OUString m_sAccessToken;
    OUString m_sWebId;
    bool m_bAuthenticated;

public:
    SolidDetailsContainer(PlaceEditDialog* pDialog);

    virtual void set_visible(bool bShow) override;
    virtual INetURLObject getUrl() override;
    virtual bool setUrl(const INetURLObject& rUrl) override;
    virtual void setUsername(const OUString& rUsername) override;
    virtual void setPassword(const OUString& rPassword) override;
    virtual bool enableUserCredentials() override { return false; }

private:
    void authenticate();
    bool discoverOIDCIssuer(const OUString& podUrl, OUString& issuer);
    bool performOIDCFlow(const OUString& issuer);
    void updateAuthStatus();
    
    // Security functions for OAuth 2.0 + PKCE
    OUString generateSecureState();
    OUString generateCodeVerifier();
    OUString generateCodeChallenge(const OUString& codeVerifier);
    bool exchangeCodeForToken(const OUString& issuer, const OUString& authCode,
                             const OUString& codeVerifier, const OUString& state);
    bool parseTokenResponse(const std::string& jsonResponse);
    
    DECL_LINK(AuthClickHdl, weld::Button&, void);
    DECL_LINK(PodUrlChangeHdl, weld::Entry&, void);
};

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */