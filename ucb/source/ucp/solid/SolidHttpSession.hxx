/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <rtl/ref.hxx>
#include <rtl/ustring.hxx>
#include <sal/log.hxx>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/io/XOutputStream.hpp>
#include <com/sun/star/ucb/XCommandEnvironment.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/beans/NamedValue.hpp>
#include "SolidOAuth.hxx"
#include <memory>

namespace solid_ucp
{

/**
 * HTTP session implementation following NextFM's Solid patterns.
 * Maps JavaScript @inrupt/solid-client operations to LibreOffice C++.
 */
class SolidHttpSession
{
private:
    OUString m_sPodUrl;
    OUString m_sAccessToken;
    OUString m_sWebId;
    OUString m_sIssuer;
    bool m_bAuthenticated;
    css::uno::Reference<css::uno::XComponentContext> m_xContext;
    std::unique_ptr<SolidOAuthClient> m_oauthClient;
    
public:
    SolidHttpSession(const css::uno::Reference<css::uno::XComponentContext>& xContext);
    SolidHttpSession(const OUString& rPodUrl, const css::uno::Reference<css::uno::XComponentContext>& xContext);
    virtual ~SolidHttpSession();

    // Authentication methods following NextFM authentication.js patterns
    bool authenticate(const OUString& rIssuer);
    bool discoverOIDCIssuer(const OUString& rPodUrl, OUString& rIssuer);
    bool performOIDCFlow(const OUString& rIssuer);
    bool isAuthenticated() const { return m_bAuthenticated; }
    void setAccessToken(const OUString& rToken) { m_sAccessToken = rToken; }
    void setWebId(const OUString& rWebId) { m_sWebId = rWebId; }
    
    // HTTP operations following @inrupt/solid-client patterns
    css::uno::Reference<css::io::XInputStream> httpGET(const OUString& rUrl);
    void httpPUT(const OUString& rUrl, const css::uno::Reference<css::io::XInputStream>& rData, const OUString& rContentType);
    void httpPOST(const OUString& rUrl, const css::uno::Reference<css::io::XInputStream>& rData, const OUString& rContentType);
    void httpDELETE(const OUString& rUrl);
    void httpHEAD(const OUString& rUrl, OUString& rContentType, sal_Int64& rSize);
    
    // Solid-specific operations matching getSolidDataset, saveFileInContainer, etc.
    css::uno::Sequence<OUString> getSolidDataset(const OUString& rContainerUrl);
    bool createContainerAt(const OUString& rContainerUrl);
    bool getResourceInfo(const OUString& rUrl, OUString& rContentType, sal_Int64& rSize, bool& rIsContainer);
    bool isContainer(const OUString& rUrl);
    
    // File operations matching NextFM fileOperations.js patterns
    void saveFileInContainer(const OUString& rContainerUrl, const css::uno::Reference<css::io::XInputStream>& rData, 
                           const OUString& rSlug, const OUString& rContentType);
    void deleteFile(const OUString& rFileUrl);
    void deleteSolidDataset(const OUString& rContainerUrl);
    
    // Storage validation following NextFM StorageUtils.js patterns
    OUString getValidStorageBaseUrl();
    bool validateStorageUrl(const OUString& rUrl);
    OUString getProvisionBaseUrl();
    
    // Utility methods
    OUString resolveUrl(const OUString& rBaseUrl, const OUString& rPath);
    
private:
    css::uno::Reference<css::io::XInputStream> executeHttpRequest(
        const OUString& rUrl, 
        const OUString& rMethod,
        const css::uno::Reference<css::io::XInputStream>& rData = nullptr,
        const OUString& rContentType = OUString(),
        const css::uno::Reference<css::ucb::XCommandEnvironment>& rEnv = nullptr);
        
    void addAuthHeaders(css::uno::Sequence<css::beans::NamedValue>& rHeaders);
    bool isValidInruptDomain(const OUString& rHostname);
    bool isValidEndSessionUrl(const OUString& rUrl);
    bool isValidDomain(const OUString& rHostname);
};

} // namespace solid_ucp