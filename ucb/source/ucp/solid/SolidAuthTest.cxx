/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidAuthTest.hxx"
#include "SolidOAuth.hxx"
#include <sal/log.hxx>
#include <cppuhelper/supportsservice.hxx>

using namespace css;

namespace solid { namespace libreoffice {

SolidAuthTest::SolidAuthTest(const uno::Reference<uno::XComponentContext>& xContext)
: m_xContext(xContext)
{
    SAL_WARN("solid.test", "SolidAuthTest created");
}

SolidAuthTest::~SolidAuthTest()
{
    SAL_WARN("solid.test", "SolidAuthTest destroyed");
}

// XServiceInfo
OUString SAL_CALL SolidAuthTest::getImplementationName()
{
    return OUString("com.sun.star.comp.SolidAuthTest");
}

sal_Bool SAL_CALL SolidAuthTest::supportsService(const OUString& ServiceName)
{
    return cppu::supportsService(this, ServiceName);
}

uno::Sequence<OUString> SAL_CALL SolidAuthTest::getSupportedServiceNames()
{
    uno::Sequence<OUString> aSeq(1);
    aSeq[0] = OUString("com.sun.star.SolidAuthTest");
    return aSeq;
}

// Test methods
bool SolidAuthTest::testDPoPAuthentication(const OUString& podUrl)
{
    SAL_WARN("solid.test", "Testing DPoP authentication for: " << podUrl);
    
    try {
        SolidOAuthClient client(m_xContext);
        bool result = client.authenticate(podUrl);
        
        if (result) {
            SAL_WARN("solid.test", "DPoP authentication SUCCESS for: " << podUrl);
            
            // Test getting tokens
            const SolidOAuthTokens& tokens = client.getTokens();
            if (tokens.isValid()) {
                SAL_WARN("solid.test", "Got valid tokens - WebID: " << tokens.webid);
                SAL_WARN("solid.test", "DPoP thumbprint: " << tokens.dpop_key_thumbprint);
                return true;
            } else {
                SAL_WARN("solid.test", "Authentication succeeded but tokens are invalid");
                return false;
            }
        } else {
            SAL_WARN("solid.test", "DPoP authentication FAILED for: " << podUrl);
            SAL_WARN("solid.test", "Error: " << client.getLastError());
            return false;
        }
    } catch (const std::exception& e) {
        SAL_WARN("solid.test", "Exception during DPoP test: " << e.what());
        return false;
    } catch (...) {
        SAL_WARN("solid.test", "Unknown exception during DPoP test");
        return false;
    }
}

} // namespace libreoffice
} // namespace solid

extern "C" SAL_DLLPUBLIC_EXPORT css::uno::XInterface*
solid_SolidAuthTest_get_implementation(
    css::uno::XComponentContext* context, css::uno::Sequence<css::uno::Any> const&)
{
    return cppu::acquire(new solid::libreoffice::SolidAuthTest(context));
}