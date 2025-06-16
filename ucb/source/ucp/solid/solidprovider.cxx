/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <memory>
#include <comphelper/processfactory.hxx>
#include <ucbhelper/contentidentifier.hxx>
#include <ucbhelper/macros.hxx>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <com/sun/star/ucb/IllegalIdentifierException.hpp>
#include <rtl/ref.hxx>
#include <rtl/ustrbuf.hxx>
#include <salhelper/simplereferenceobject.hxx>

#include "solidprovider.hxx"
#include "solidcontent.hxx"
#include "SolidSession.hxx"

using namespace com::sun::star;
using namespace solid_ucp;

// SolidSessionFactory Implementation
class SolidSessionFactory : public salhelper::SimpleReferenceObject
{
public:
    virtual ~SolidSessionFactory() override {}
    
    rtl::Reference<SolidSession> createSolidSession(
        const OUString& rURL,
        const uno::Reference<uno::XComponentContext>& rxContext)
    {
        // Create a null reference for the session factory parameter
        rtl::Reference<SolidSession> nullSession;
        return new SolidSession(nullSession, rURL, rxContext);
    }
};

// ContentProvider Implementation.

ContentProvider::ContentProvider(
    const uno::Reference< uno::XComponentContext >& rContext )
: ::ucbhelper::ContentProviderImplHelper( rContext ),
  m_xSolidSessionFactory( new SolidSessionFactory() )
{
}

ContentProvider::~ContentProvider()
{
}

// XInterface methods.
void SAL_CALL ContentProvider::acquire()
    noexcept
{
    OWeakObject::acquire();
}

void SAL_CALL ContentProvider::release()
    noexcept
{
    OWeakObject::release();
}

css::uno::Any SAL_CALL ContentProvider::queryInterface( const css::uno::Type & rType )
{
    css::uno::Any aRet = cppu::queryInterface( rType,
                                               static_cast< lang::XTypeProvider* >(this),
                                               static_cast< lang::XServiceInfo* >(this),
                                               static_cast< ucb::XContentProvider* >(this)
                                               );
    return aRet.hasValue() ? aRet : OWeakObject::queryInterface( rType );
}

// XTypeProvider methods.
uno::Sequence< sal_Int8 > SAL_CALL ContentProvider::getImplementationId()
{
    return css::uno::Sequence<sal_Int8>();
}

uno::Sequence< uno::Type > SAL_CALL ContentProvider::getTypes()
{
    static cppu::OTypeCollection s_aCollection(
                    cppu::UnoType<lang::XTypeProvider>::get(),
                    cppu::UnoType<lang::XServiceInfo>::get(),
                    cppu::UnoType<ucb::XContentProvider>::get()
                );

    return s_aCollection.getTypes();
}

// XServiceInfo methods.
OUString SAL_CALL ContentProvider::getImplementationName()
{
    return u"com.sun.star.comp.SolidContentProvider"_ustr;
}

sal_Bool SAL_CALL ContentProvider::supportsService( const OUString& ServiceName )
{
    return cppu::supportsService( this, ServiceName );
}

uno::Sequence< OUString > SAL_CALL ContentProvider::getSupportedServiceNames()
{
    return { SOLID_CONTENT_PROVIDER_SERVICE_NAME };
}

// XContentProvider methods.
uno::Reference< ucb::XContent > SAL_CALL
ContentProvider::queryContent(
        const uno::Reference< ucb::XContentIdentifier >& Identifier )
{
    // Check URL scheme...
    const OUString aScheme
        = Identifier->getContentProviderScheme().toAsciiLowerCase();
    if ( aScheme != SOLID_URL_SCHEME && aScheme != SOLIDS_URL_SCHEME )
        throw ucb::IllegalIdentifierException();

    // Normalize URL and create new identifier.
    OUString aURL = Identifier->getContentIdentifier();

    uno::Reference< ucb::XContentIdentifier > xCanonicId;
    bool bNewId = false;

    if ( aURL != Identifier->getContentIdentifier() )
    {
        xCanonicId = new ::ucbhelper::ContentIdentifier( aURL );
        bNewId = true;
    }
    else
        xCanonicId = Identifier;

    rtl::Reference< Content > xContent;
    xContent = new Content( m_xContext, this, xCanonicId );
    // No need to call setIdentifier - it's handled in the constructor

    if ( !xContent->initResourceAccess() )
    {
        throw ucb::IllegalIdentifierException();
    }

    if ( bNewId && !xContent->exchangeIdentity( xCanonicId ) )
        throw ucb::IllegalIdentifierException();

    return xContent;
}

bool ContentProvider::getProperty( const OUString & rPropName, beans::Property & rProp )
{
    // TODO: Implement property mapping for Solid-specific properties
    (void)rPropName;
    (void)rProp;
    return false;
}

extern "C" SAL_DLLPUBLIC_EXPORT css::uno::XInterface*
ucb_solid_ContentProvider_get_implementation(
    css::uno::XComponentContext* context , css::uno::Sequence<css::uno::Any> const&)
{
    return cppu::acquire(new solid_ucp::ContentProvider(context));
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */