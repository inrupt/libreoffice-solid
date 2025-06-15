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
#include <list>
#include <rtl/ref.hxx>
#include <com/sun/star/ucb/ContentCreationException.hpp>
#include <com/sun/star/ucb/XContentCreator.hpp>
#include <ucbhelper/contenthelper.hxx>
#include "SolidResourceAccess.hxx"
#include "PropertyMap.hxx"

namespace com::sun::star::beans {
    struct Property;
    struct PropertyValue;
}

namespace com::sun::star::io {
    class XInputStream;
}

namespace com::sun::star::sdbc {
    class XRow;
}

namespace com::sun::star::ucb {
    struct OpenCommandArgument3;
    struct PropertyCommandArgument;
    struct PostCommandArgument2;
    struct TransferInfo;
}

namespace solid_ucp
{

// UNO service name for the content.
inline constexpr OUString SOLID_CONTENT_SERVICE_NAME = u"com.sun.star.ucb.SolidContent"_ustr;

class ContentProvider;
class ContentProperties;
class CachableContentProperties;

class Content : public ::ucbhelper::ContentImplHelper,
                public css::ucb::XContentCreator
{
    enum ResourceType
    {
        UNKNOWN,        // the type of the Solid resource is unknown
        NOT_FOUND,      // the Solid resource does not exist
        NON_SOLID,      // the resource exists but it's not a valid Solid resource
        SOLID,          // the type of the Solid resource is valid with read/write available
        SOLID_READONLY  // the type of the Solid resource is valid but read-only
    };

    std::unique_ptr< SolidResourceAccess > m_xResAccess;
    std::unique_ptr< CachableContentProperties > m_xCachedProps; // locally cached props
    OUString     m_aEscapedTitle;
    // resource type for general Solid methods
    ResourceType      m_eResourceType;
    ContentProvider*  m_pProvider; // No need for a ref, base class holds object
    bool              m_bTransient;
    bool const        m_bCollection;
    bool              m_bDidGetOrHead;
    std::vector< OUString > m_aFailedPropNames;

    virtual css::uno::Sequence< css::beans::Property >
    getProperties( const css::uno::Reference< css::uno::XComponentContext >& rxContext ) override;
    virtual css::uno::Sequence< css::ucb::CommandInfo >
    getCommands( const css::uno::Reference< css::uno::XComponentContext >& rxContext ) override;
    virtual OUString getParentURL() override;

    /// @throws css::uno::Exception
    static bool shouldAccessNetworkAfterException( const css::uno::Exception & e );

    bool supportsExclusiveWriteLock( const Content & rContent );

    void addProperty( const css::ucb::PropertyCommandArgument &aCmdArg,
                      const css::uno::Reference< css::uno::XComponentContext >& xContext );

    void removeProperty( const OUString& Name,
                         const css::uno::Reference< css::uno::XComponentContext >& xContext );

    const OUString & getRequestURI() const;

    /// @throws css::uno::Exception
    void handleError( const SolidSession::SolidRequestException & e,
                      const css::uno::Reference< css::task::XInteractionHandler >& xIH,
                      const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    static void cancelCommandExecution(
                    const SolidSession::SolidRequestException & e,
                    const css::uno::Reference< css::task::XInteractionHandler > & xIH );

    static bool shouldUseVersioning( const css::uno::Sequence< css::ucb::PropertyValue >& rArgs );

    /// @throws css::uno::Exception
    bool exchangeIdentity( const css::uno::Reference< css::ucb::XContentIdentifier >& xNewId );

    /// @throws css::uno::Exception
    css::uno::Reference< css::sdbc::XRow >
    getPropertyValues( const css::uno::Sequence< css::beans::Property >& rProperties,
                       const css::uno::Reference< css::uno::XComponentContext >& xContext );

    /// @throws css::uno::Exception
    css::uno::Reference< css::sdbc::XRow >
    getPropertyValuesWireFormat( const css::uno::Sequence< css::beans::Property >& rProperties,
                                const css::uno::Reference< css::uno::XComponentContext >& xContext );

    /// @throws css::uno::Exception
    css::uno::Sequence< css::uno::Any >
    setPropertyValues( const css::uno::Sequence< css::beans::PropertyValue >& rValues,
                       const css::uno::Reference< css::uno::XComponentContext >& xContext );

    typedef rtl::Reference< Content > ContentRef;
    typedef std::vector< ContentRef > ContentRefList;
    void queryChildren( ContentRefList& rChildren);

    bool
    isFolder( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    css::uno::Reference< css::io::XInputStream >
    getInputStream( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    void insert( const css::uno::Reference< css::io::XInputStream > & xInputStream,
                 bool bReplaceExisting,
                 const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    void transfer( const css::ucb::TransferInfo & rArgs,
                   const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    void destroy( bool bDeletePhysical,
                  const css::uno::Reference< css::uno::XComponentContext >& xContext );

    bool supportsExclusiveWriteLock();

    void lock( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    void unlock( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    css::uno::Reference< css::ucb::XContent >
    queryContent();

    /// @throws css::uno::Exception
    OUString
    getBaseURI( const std::unique_ptr< SolidResourceAccess > & rResAccess );

    /// @throws css::uno::Exception
    ResourceType
    getResourceType( const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    /// @throws css::uno::Exception
    ResourceType
    getResourceType( const css::uno::Reference< css::uno::XComponentContext >& rxContext,
                     const std::unique_ptr< SolidResourceAccess > & rResAccess,
                     bool * networkAccessAllowed = nullptr);

public:
    /// @throws css::ucb::ContentCreationException
    Content( const css::uno::Reference< css::uno::XComponentContext >& rxContext,
             ContentProvider* pProvider,
             const css::uno::Reference< css::ucb::XContentIdentifier >& Identifier,
             rtl::Reference< SolidResourceAccess > const & rSolidResourceAccess);

    /// @throws css::ucb::ContentCreationException
    Content( const css::uno::Reference< css::uno::XComponentContext >& rxContext,
             ContentProvider* pProvider,
             const css::uno::Reference< css::ucb::XContentIdentifier >& Identifier );

    virtual ~Content() override;

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
    virtual OUString SAL_CALL
    getImplementationName() override;

    virtual css::uno::Sequence< OUString > SAL_CALL
    getSupportedServiceNames() override;

    // XContent
    virtual OUString SAL_CALL
    getContentType() override;

    // XCommandProcessor
    virtual css::uno::Any SAL_CALL
    execute( const css::ucb::Command& aCommand,
             sal_Int32 CommandId,
             const css::uno::Reference< css::ucb::XCommandEnvironment >& Environment ) override;
    virtual void SAL_CALL
    abort( sal_Int32 CommandId ) override;

    // XPropertyContainer
    virtual void SAL_CALL
    addProperty( const OUString& Name,
                 sal_Int16 Attributes,
                 const css::uno::Any& DefaultValue ) override;

    virtual void SAL_CALL
    removeProperty( const OUString& Name ) override;

    // Additional interfaces

    // XContentCreator
    virtual css::uno::Sequence< css::ucb::ContentInfo > SAL_CALL
    queryCreatableContentsInfo() override;
    virtual css::uno::Reference< css::ucb::XContent > SAL_CALL
    createNewContent( const css::ucb::ContentInfo& Info ) override;

    // Non-interface methods.

    SolidResourceAccess & getSolidResourceAccess()
                          { return *m_xResAccess; }

    // Called from resultset data supplier.
    static css::uno::Reference< css::sdbc::XRow >
    getPropertyValues( const css::uno::Reference< css::uno::XComponentContext >& rxContext,
                       const css::uno::Sequence< css::beans::Property >& rProperties,
                       const ContentProperties& rData,
                       const rtl::Reference< ::ucbhelper::ContentProviderImplHelper >& rProvider,
                       const OUString& rContentId );

    static OUString
    encodeIdentifier( const OUString& rURL );
    static OUString
    decodeIdentifier( const OUString& rURL );

    ::com::sun::star::uno::Reference< ::com::sun::star::ucb::XContentIdentifier >
    makeNewIdentifier( const OUString& rURL );

    void setPropertyValues(
        const css::uno::Sequence< css::beans::PropertyValue >& rValues );

    bool initResourceAccess();
};

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */