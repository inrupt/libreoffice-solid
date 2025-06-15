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

#include <memory>

#include <rtl/ref.hxx>
#include <com/sun/star/beans/Property.hpp>
#include <ucbhelper/providerhelper.hxx>
#include "SolidSessionFactory.hxx"

namespace solid_ucp {

// UNO service name for the provider. This name will be used by the UCB to
// create instances of the provider.
inline constexpr OUString SOLID_CONTENT_PROVIDER_SERVICE_NAME = u"com.sun.star.ucb.SolidContentProvider"_ustr;

// URL scheme. This is the scheme the provider will be able to create
// contents for. The UCB will select the provider ( i.e. in order to create
// contents ) according to this scheme.
#define SOLID_URL_SCHEME              u"solid"
#define SOLIDS_URL_SCHEME             u"solids"

inline constexpr OUString SOLID_CONTENT_TYPE = u"application/" SOLID_URL_SCHEME "-content"_ustr;
inline constexpr OUString SOLID_COLLECTION_TYPE = u"application/" SOLID_URL_SCHEME "-collection"_ustr;

class ContentProvider : public ::ucbhelper::ContentProviderImplHelper
{
    rtl::Reference< SolidSessionFactory > m_xSolidSessionFactory;
    // Property map will be initialized dynamically when needed

public:
    explicit ContentProvider( const css::uno::Reference< css::uno::XComponentContext >& rContext );
    virtual ~ContentProvider() override;

    // XInterface
    virtual css::uno::Any SAL_CALL queryInterface( const css::uno::Type & rType ) override;
    virtual void SAL_CALL acquire()
        noexcept override;
    virtual void SAL_CALL release()
        noexcept override;

    // XTypeProvider
    virtual css::uno::Sequence< sal_Int8 > SAL_CALL getImplementationId() override;
    virtual css::uno::Sequence< css::uno::Type > SAL_CALL getTypes() override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual sal_Bool SAL_CALL supportsService( const OUString& ServiceName ) override;
    virtual css::uno::Sequence< OUString > SAL_CALL getSupportedServiceNames() override;

    // XContentProvider
    virtual css::uno::Reference< css::ucb::XContent > SAL_CALL
    queryContent( const css::uno::Reference< css::ucb::XContentIdentifier >& Identifier ) override;

    // Non-interface methods.
    bool getProperty( const OUString & rPropName,
                      css::beans::Property & rProp );
                      
    rtl::Reference< SolidSessionFactory > getSolidSessionFactory()
        { return m_xSolidSessionFactory; }
};

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */