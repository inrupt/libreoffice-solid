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
#include <cppuhelper/factory.hxx>
#include <com/sun/star/registry/XRegistryKey.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>

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
    aSeq.getArray()[0] = OUString("com.sun.star.SolidAuthTest");
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

static css::uno::Reference<css::uno::XInterface> create_SolidAuthTest(
    const css::uno::Reference<css::lang::XMultiServiceFactory>&)
{
    return static_cast<css::lang::XServiceInfo*>(new solid::libreoffice::SolidAuthTest(css::uno::Reference<css::uno::XComponentContext>()));
}

extern "C" SAL_DLLPUBLIC_EXPORT sal_Bool component_writeInfo(
    void*, void* registry)
{
    try
    {
        css::uno::Reference<css::registry::XRegistryKey> key(
            static_cast<css::registry::XRegistryKey*>(registry));
        
        css::uno::Reference<css::registry::XRegistryKey> key1 = key->createKey(
            "/com.sun.star.comp.SolidAuthTest/UNO/SERVICES");
        key1->createKey("com.sun.star.SolidAuthTest");
        
        return sal_True;
    }
    catch (css::registry::InvalidRegistryException &)
    {
        return sal_False;
    }
}

extern "C" SAL_DLLPUBLIC_EXPORT void* component_getFactory(
    const char* implName, void* serviceManager, void*)
{
    void* factory = nullptr;
    
    if (rtl_str_compare(implName, "com.sun.star.comp.SolidAuthTest") == 0)
    {
        css::uno::Reference<css::lang::XMultiServiceFactory> msf(
            static_cast<css::lang::XMultiServiceFactory*>(serviceManager), css::uno::UNO_QUERY);
        
        css::uno::Sequence<rtl::OUString> aSeq(1);
        aSeq.getArray()[0] = rtl::OUString("com.sun.star.SolidAuthTest");
        
        factory = cppu::createSingleFactory(
            msf,
            "com.sun.star.comp.SolidAuthTest",
            create_SolidAuthTest,
            aSeq
        ).get();
        
        if (factory)
        {
            static_cast<css::uno::XInterface*>(factory)->acquire();
        }
    }
    
    return factory;
}