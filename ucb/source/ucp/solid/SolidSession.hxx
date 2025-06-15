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
#include <vector>
#include <rtl/ustring.hxx>
#include <rtl/ref.hxx>
#include <salhelper/simplereferenceobject.hxx>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/io/XOutputStream.hpp>
#include <com/sun/star/ucb/Lock.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/task/XInteractionHandler.hpp>

namespace com::sun::star::beans {
    struct NamedValue;
}

namespace com::sun::star::ucb {
    struct Lock;
}

namespace solid_ucp {

class SolidSession; // Forward declaration

struct SolidRequestEnvironment
{
    OUString m_aRequestURI;
    rtl::Reference< SolidSession > m_xSession;
    css::uno::Reference< css::uno::XComponentContext > m_xContext;
    css::uno::Reference< css::task::XInteractionHandler > m_xAuthListener;
    css::uno::Reference< css::io::XInputStream > m_xInputStream;

    SolidRequestEnvironment( const OUString & rRequestURI,
                             const rtl::Reference< SolidSession > & xSession,
                             const css::uno::Reference< css::uno::XComponentContext > & xContext )
    : m_aRequestURI( rRequestURI ),
      m_xSession( xSession ),
      m_xContext( xContext ) {}

    SolidRequestEnvironment( const OUString & rRequestURI,
                             const rtl::Reference< SolidSession > & xSession,
                             const css::uno::Reference< css::uno::XComponentContext > & xContext,
                             const css::uno::Reference< css::task::XInteractionHandler > & xAuthListener )
    : m_aRequestURI( rRequestURI ),
      m_xSession( xSession ),
      m_xContext( xContext ),
      m_xAuthListener( xAuthListener ) {}
};

struct SolidResource
{
    OUString uri;
    OUString properties;
    std::vector< OUString > contents; // child contents for collections

    SolidResource() {}
    explicit SolidResource( const OUString & inUri ) : uri( inUri ) {}
};

class SolidSession : public salhelper::SimpleReferenceObject
{
private:
    rtl::Reference< SolidSession > m_xSession;
    OUString m_aScheme;
    OUString m_aHostName;
    sal_Int32 m_nPort;
    css::uno::Reference< css::uno::XComponentContext > m_xContext;
    OUString m_aAccessToken;  // Solid-OIDC access token
    OUString m_aWebId;        // WebID of authenticated user

public:
    explicit SolidSession( const rtl::Reference< SolidSession >& inSessionFactory,
                           const OUString& inUri,
                           const css::uno::Reference< css::uno::XComponentContext >& rxContext );

    virtual ~SolidSession();

    // Error codes:
    enum
    {
        SC_NONE                            = 0,
        SC_OK                              = 200,
        SC_CREATED                         = 201,
        SC_ACCEPTED                        = 202,
        SC_NO_CONTENT                      = 204,
        SC_MOVED_PERMANENTLY               = 301,
        SC_MOVED_TEMPORARILY               = 302,
        SC_NOT_MODIFIED                    = 304,
        SC_BAD_REQUEST                     = 400,
        SC_UNAUTHORIZED                    = 401,
        SC_PAYMENT_REQUIRED                = 402,
        SC_FORBIDDEN                       = 403,
        SC_NOT_FOUND                       = 404,
        SC_METHOD_NOT_ALLOWED              = 405,
        SC_CONFLICT                        = 409,
        SC_LENGTH_REQUIRED                 = 411,
        SC_PRECONDITION_FAILED             = 412,
        SC_REQUEST_ENTITY_TOO_LARGE        = 413,
        SC_REQUEST_URI_TOO_LONG            = 414,
        SC_UNSUPPORTED_MEDIA_TYPE          = 415,
        SC_LOCKED                          = 423,
        SC_FAILED_DEPENDENCY               = 424,
        SC_INTERNAL_SERVER_ERROR           = 500,
        SC_NOT_IMPLEMENTED                 = 501,
        SC_BAD_GATEWAY                     = 502,
        SC_SERVICE_UNAVAILABLE             = 503,
        SC_INSUFFICIENT_STORAGE            = 507
    };

    class SolidRequestException : public css::uno::Exception
    {
    public:
        sal_uInt16 mStatusCode;
        SolidRequestException( OUString const & rMessage,
                               sal_uInt16 nStatusCode )
        : css::uno::Exception( rMessage, css::uno::Reference< css::uno::XInterface >() ),
          mStatusCode( nStatusCode ) {}
    };

    // Solid-specific methods
    
    /// @throws SolidRequestException
    void authenticate( const css::uno::Reference< css::task::XInteractionHandler >& xIH );

    /// @throws SolidRequestException
    void GET( SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    void PUT( const css::uno::Reference< css::io::XInputStream > & xInputStream,
              SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    void POST( const css::uno::Reference< css::io::XInputStream > & xInputStream,
               const OUString & rContentType,
               const OUString & rReferer,
               SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    void DELETE( SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    void MKCOL( SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    void COPY( const OUString & rSourcePath,
               const OUString & rDestinationURI,
               SolidRequestEnvironment & rEnv,
               bool bOverwrite );

    /// @throws SolidRequestException
    void MOVE( const OUString & rSourcePath,
               const OUString & rDestinationURI,
               SolidRequestEnvironment & rEnv,
               bool bOverwrite );

    /// @throws SolidRequestException
    void HEAD( SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    css::uno::Reference< css::io::XInputStream >
    GET( const OUString & inPath,
         const std::vector< OUString > & inHeaderNames,
         SolidRequestEnvironment & rEnv );

    /// @throws SolidRequestException
    void
    abort();

    const OUString & getHostName() const { return m_aHostName; }

    const css::uno::Reference< css::uno::XComponentContext >& getXComponentContext() const
        { return m_xContext; }

    sal_Int32 getPort() const { return m_nPort; }

    const OUString& getAccessToken() const { return m_aAccessToken; }
    const OUString& getWebId() const { return m_aWebId; }

    bool isSecure() const { return m_aScheme == "solids"; }

private:
    friend class SolidSessionFactory;
    friend class ContentProperties;

    void Init();
};

} // namespace solid_ucp

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */