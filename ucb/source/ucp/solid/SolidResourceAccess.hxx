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
#include <rtl/ustring.hxx>
#include <rtl/ref.hxx>
#include <salhelper/simplereferenceobject.hxx>
#include <com/sun/star/io/XInputStream.hpp>
#include <com/sun/star/ucb/Lock.hpp>
#include "SolidRequestEnvironment.hxx"
#include "SolidTypes.hxx"

namespace com::sun::star::beans {
    struct NamedValue;
}

namespace com::sun::star::io {
    class XOutputStream;
}

namespace com::sun::star::ucb {
    struct Lock;
}

namespace solid { namespace libreoffice
{
    class SolidSession;
    class SolidSessionFactory;

    class SolidResourceAccess
    {
        std::unique_ptr< SolidRequestEnvironment > m_pEnv;
        rtl::Reference< SolidSession > m_xSession;
        rtl::Reference< SolidSessionFactory > m_xSessionFactory;
        OUString m_aURL;
        OUString m_aPath;
        OUString m_aRedirectedURL;
        css::uno::Reference< css::uno::XComponentContext > m_xContext;

    public:
        /// @throws css::uno::RuntimeException
        SolidResourceAccess( const css::uno::Reference< css::uno::XComponentContext > & rxContext,
                             rtl::Reference< SolidSessionFactory > const & rSessionFactory,
                             const OUString & rURL );

        SolidResourceAccess( const SolidResourceAccess & rOther );

        SolidResourceAccess & operator=( const SolidResourceAccess & rOther );

        ~SolidResourceAccess();

        /// @throws css::uno::Exception
        void setURL( const OUString& rNewURL );

        void resetUri();

        const OUString & getURL() const { return m_aURL; }

        const OUString & getPath() const { return m_aPath; }

        css::uno::Reference< css::uno::XComponentContext > const & getComponentContext() const
        { return m_xContext; }

        // Solid protocol operations

        /// @throws SolidSession::SolidRequestException
        css::uno::Reference< css::io::XInputStream >
        GET( SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void GET( SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        css::uno::Reference< css::io::XInputStream >
        GET( const std::vector< OUString > & rHeaderNames,
             SolidResourceAccess & rDAVResourceAccess,
             SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void GET( std::vector< OUString > & rResources,
                  SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void HEAD( const std::vector< OUString > & rHeaderNames,
                   SolidResourceAccess & rResource,
                   SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        css::uno::Reference< css::io::XInputStream >
        POST( const OUString & rContentType,
              const OUString & rReferer,
              const css::uno::Reference< css::io::XInputStream > & rInputStream,
              SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void POST( const OUString & rContentType,
                   const OUString & rReferer,
                   const css::uno::Reference< css::io::XInputStream > & rInputStream,
                   SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void PUT( const css::uno::Reference< css::io::XInputStream > & rInputStream,
                  SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        css::uno::Reference< css::io::XInputStream >
        PUT( const css::uno::Reference< css::io::XInputStream > & rInputStream,
             SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void MKCOL( SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void COPY( const OUString & rDestinationURI,
                   bool bOverwrite,
                   SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void MOVE( const OUString & rDestinationURI,
                   bool bOverwrite,
                   SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void DESTROY( SolidRequestEnvironment & rEnv );

        // set new lock.
        /// @throws SolidSession::SolidRequestException
        void LOCK( css::ucb::Lock & inLock,
                   SolidRequestEnvironment & rEnv );

        // refresh existing lock.
        /// @throws SolidSession::SolidRequestException
        sal_Int64 LOCK( SolidRequestEnvironment & rEnv,
                        sal_Int32 nTimeout = -1 );

        /// @throws SolidSession::SolidRequestException
        void UNLOCK( SolidRequestEnvironment & rEnv );

        /// @throws SolidSession::SolidRequestException
        void abort();

        // helper
        static void getUserRequestHeaders(
            const css::uno::Reference< css::uno::XComponentContext > & xContext,
            const OUString & rURI,
            const OUString & rMethod,
            css::uno::Sequence< css::beans::NamedValue > & rRequestHeaders );

    private:
        const OUString & getRequestURI() const;
        bool detectRedirectCycle( const OUString& rRedirectURL );
        bool handleException( const SolidSession::SolidRequestException & e, int errorCount );
        void initialize();
    };

} // namespace libreoffice
} // namespace solid

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */