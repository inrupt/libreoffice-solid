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
#include <rtl/ref.hxx>
#include <com/sun/star/beans/Property.hpp>
#include <com/sun/star/ucb/XContentProvider.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/lang/XInitialization.hpp>
#include <cppuhelper/implbase3.hxx>
#include "SolidSessionFactory.hxx"

namespace solid { namespace libreoffice {

// UNO service name for the provider. This name will be used by the UCB to
// create instances of the provider.
#define SOLID_CONTENT_PROVIDER_SERVICE_NAME "com.sun.star.ucb.SolidContentProvider"

// URL scheme. This is the scheme the provider will be able to create
// contents for. The UCB will select the provider ( i.e. in order to create
// contents ) according to this scheme.
#define SOLID_URL_SCHEME              "solid"
#define SOLIDS_URL_SCHEME             "solids"

#define SOLID_CONTENT_TYPE            "application/solid-content"
#define SOLID_COLLECTION_TYPE         "application/solid-collection"

class ContentProvider : public cppu::WeakImplHelper3<
    css::ucb::XContentProvider,
    css::lang::XServiceInfo,
    css::lang::XInitialization>
{
    rtl::Reference< SolidSessionFactory > m_xSolidSessionFactory;
    // Property map will be initialized dynamically when needed

    css::uno::Reference<css::uno::XComponentContext> m_xContext;

public:
    explicit ContentProvider( const css::uno::Reference< css::uno::XComponentContext >& rContext );
    virtual ~ContentProvider() override;

    // XInitialization
    virtual void SAL_CALL initialize( const css::uno::Sequence< css::uno::Any >& aArguments ) override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName ) override;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;

    // XContentProvider
    virtual css::uno::Reference< css::ucb::XContent > SAL_CALL
    queryContent( const css::uno::Reference< css::ucb::XContentIdentifier >& Identifier ) override;
    virtual sal_Int32 SAL_CALL compareContentIds( const css::uno::Reference< css::ucb::XContentIdentifier >& Id1,
                                                  const css::uno::Reference< css::ucb::XContentIdentifier >& Id2 ) override;

    // Non-interface methods.
    bool getProperty( const OUString & rPropName,
                      css::beans::Property & rProp );
                      
    rtl::Reference< SolidSessionFactory > getSolidSessionFactory()
        { 
            if (!m_xSolidSessionFactory.is())
                m_xSolidSessionFactory = new SolidSessionFactory();
            return m_xSolidSessionFactory; 
        }
};

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */