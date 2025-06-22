/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <com/sun/star/ucb/XContentIdentifier.hpp>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/weak.hxx>
#include <cppuhelper/supportsservice.hxx>
#include <cppuhelper/implbase1.hxx>
#include <com/sun/star/ucb/IllegalIdentifierException.hpp>
#include <rtl/ref.hxx>
#include <rtl/ustrbuf.hxx>
#include <rtl/ustring.hxx>
#include <salhelper/simplereferenceobject.hxx>
#include <sal/log.hxx>

#include "solidprovider.hxx"
#include "solidcontent.hxx"
#include "SolidSession.hxx"
#include "SolidSessionFactory.hxx"

using namespace com::sun::star;
using namespace solid::libreoffice;
using rtl::OUString;

// Simple ContentIdentifier implementation
class ContentIdentifier : public cppu::WeakImplHelper1<ucb::XContentIdentifier>
{
private:
    OUString m_sContentId;
    OUString m_sScheme;

public:
    ContentIdentifier(const OUString& ContentId) : m_sContentId(ContentId)
    {
        sal_Int32 nSchemeEnd = ContentId.indexOf(':');
        if (nSchemeEnd != -1)
            m_sScheme = ContentId.copy(0, nSchemeEnd);
    }

    virtual OUString SAL_CALL getContentIdentifier() override { return m_sContentId; }
    virtual OUString SAL_CALL getContentProviderScheme() override { return m_sScheme; }
};

// ContentProvider Implementation.

ContentProvider::ContentProvider(
    const uno::Reference< uno::XComponentContext >& rContext )
: m_xContext(rContext)
{
    SAL_WARN("ucb.ucp.solid", "=== SolidContentProvider CONSTRUCTOR START ===");
    // Initialize session factory later in queryContent to avoid constructor issues
    SAL_WARN("ucb.ucp.solid", "=== SolidContentProvider CONSTRUCTED SUCCESSFULLY ===");
}

ContentProvider::~ContentProvider()
{
}

// XInitialization methods.
void SAL_CALL ContentProvider::initialize( const uno::Sequence< uno::Any >& aArguments )
{
    // For now, we don't need any initialization arguments
    // This method is required by the XInitialization interface
    (void)aArguments;
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
    return OUString("com.sun.star.comp.SolidContentProvider");
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
    SAL_WARN("ucb.ucp.solid", "SolidContentProvider::queryContent called with URL: " 
             << Identifier->getContentIdentifier());
    
    // Check URL scheme...
    const OUString aScheme
        = Identifier->getContentProviderScheme().toAsciiLowerCase();
    
    
    // Only accept vnd-solid and vnd-solids schemes
    bool bIsSolidScheme = (aScheme == SOLID_URL_SCHEME || aScheme == SOLIDS_URL_SCHEME);
    
    SAL_WARN("ucb.ucp.solid", "URL scheme: " << aScheme << " checking against vnd-solid schemes");
    
    if (!bIsSolidScheme)
    {
        SAL_WARN("ucb.ucp.solid", "Unsupported scheme: " << aScheme << " - only vnd-solid and vnd-solids are supported");
        throw ucb::IllegalIdentifierException();
    }
    

    // Convert vnd-solid:// URL to canonical form and create new identifier
    OUString aURL = Identifier->getContentIdentifier();
    OUString aCanonicalURL = convertVndSolidToHttps(aURL);

    uno::Reference< ucb::XContentIdentifier > xCanonicId;
    bool bNewId = false;

    if ( aCanonicalURL != aURL )
    {
        xCanonicId = new ContentIdentifier( aCanonicalURL );
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

    return static_cast<ucb::XContent*>(xContent.get());
}

sal_Int32 SAL_CALL ContentProvider::compareContentIds( const uno::Reference< ucb::XContentIdentifier >& Id1,
                                                       const uno::Reference< ucb::XContentIdentifier >& Id2 )
{
    OUString aURL1 = Id1->getContentIdentifier();
    OUString aURL2 = Id2->getContentIdentifier();
    return aURL1.compareTo(aURL2);
}

bool ContentProvider::getProperty( const OUString & rPropName, beans::Property & rProp )
{
    // TODO: Implement property mapping for Solid-specific properties
    (void)rPropName;
    (void)rProp;
    return false;
}

OUString ContentProvider::convertVndSolidToHttps( const OUString & rVndSolidUrl ) const
{
    // Convert vnd-solid://host/path to https://host/path
    // Convert vnd-solids://host/path to https://host/path (both use HTTPS)
    
    if (rVndSolidUrl.startsWithIgnoreAsciiCase("vnd-solid://"))
    {
        return "https://" + rVndSolidUrl.copy(12); // Remove "vnd-solid://"
    }
    else if (rVndSolidUrl.startsWithIgnoreAsciiCase("vnd-solids://"))
    {
        return "https://" + rVndSolidUrl.copy(13); // Remove "vnd-solids://"
    }
    
    // Return unchanged if not a vnd-solid URL
    return rVndSolidUrl;
}

extern "C" SAL_DLLPUBLIC_EXPORT css::uno::XInterface*
ucb_solid_ContentProvider_get_implementation(
    css::uno::XComponentContext* context , css::uno::Sequence<css::uno::Any> const&)
{
    css::uno::Reference<css::uno::XComponentContext> xContext(context);
    rtl::Reference<solid::libreoffice::ContentProvider> xProvider = new solid::libreoffice::ContentProvider(xContext);
    return static_cast<css::uno::XInterface*>(xProvider.get());
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */