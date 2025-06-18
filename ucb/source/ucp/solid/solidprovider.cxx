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
    SAL_WARN("ucb.ucp.solid", "SolidContentProvider::queryContent called with URL: " 
             << Identifier->getContentIdentifier());
    
    // Check URL scheme...
    const OUString aScheme
        = Identifier->getContentProviderScheme().toAsciiLowerCase();
    
    
    // Accept both solid:// schemes and https:// URLs for Solid pods
    bool bIsSolidScheme = (aScheme == SOLID_URL_SCHEME || aScheme == SOLIDS_URL_SCHEME);
    bool bIsSolidPodUrl = false;
    
    SAL_WARN("ucb.ucp.solid", "URL scheme: " << aScheme << " checking against solid schemes");
    
    if (aScheme == "https" || aScheme == "http")
    {
        // Check if this is a Solid pod URL based on domain
        OUString aURL = Identifier->getContentIdentifier();
        OUString sHost;
        sal_Int32 nSchemeEnd = aURL.indexOf("://");
        if (nSchemeEnd != -1) {
            sal_Int32 nHostStart = nSchemeEnd + 3;
            sal_Int32 nHostEnd = aURL.indexOf("/", nHostStart);
            if (nHostEnd == -1) nHostEnd = aURL.getLength();
            sHost = aURL.copy(nHostStart, nHostEnd - nHostStart);
        }
        
        SAL_WARN("ucb.ucp.solid", "SolidContentProvider::queryContent - URL: " 
                 << Identifier->getContentIdentifier() << " Host: " << sHost);
        
        // Detect known Solid pod domains (following NextFM pattern)
        bIsSolidPodUrl = sHost.indexOf("storage.inrupt.com") != -1 ||
                        sHost.endsWith(".solidcommunity.net") ||
                        sHost.endsWith(".inrupt.net") ||
                        sHost.indexOf("storage.") == 0; // Generic storage. pattern
        
        SAL_WARN("ucb.ucp.solid", "SolidContentProvider - Domain check result: " << (bIsSolidPodUrl ? "MATCH" : "NO MATCH"));
                        
    }
    
    if (!bIsSolidScheme && !bIsSolidPodUrl)
    {
        throw ucb::IllegalIdentifierException();
    }
    

    // Normalize URL and create new identifier.
    OUString aURL = Identifier->getContentIdentifier();

    uno::Reference< ucb::XContentIdentifier > xCanonicId;
    bool bNewId = false;

    if ( aURL != Identifier->getContentIdentifier() )
    {
        xCanonicId = new ContentIdentifier( aURL );
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

extern "C" SAL_DLLPUBLIC_EXPORT css::uno::XInterface*
ucb_solid_ContentProvider_get_implementation(
    css::uno::XComponentContext* context , css::uno::Sequence<css::uno::Any> const&)
{
    css::uno::Reference<css::uno::XComponentContext> xContext(context);
    rtl::Reference<solid::libreoffice::ContentProvider> xProvider = new solid::libreoffice::ContentProvider(xContext);
    return static_cast<css::uno::XInterface*>(xProvider.get());
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */