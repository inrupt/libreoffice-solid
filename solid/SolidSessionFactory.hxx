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

#include <map>
#include <memory>
#include <mutex>
#include <rtl/ref.hxx>
#include <rtl/ustring.hxx>
#include <salhelper/simplereferenceobject.hxx>

namespace solid_ucp
{
    class SolidSession;

    class SolidSessionFactory : public salhelper::SimpleReferenceObject
    {
    public:
        virtual ~SolidSessionFactory();

        /// @throws css::uno::RuntimeException
        rtl::Reference< SolidSession > createSession( const OUString& inHostName,
                                                       sal_Int32 nPort,
                                                       const css::uno::Reference< css::uno::XComponentContext >& rxContext );

        void releaseSession( rtl::Reference< SolidSession > const & xSession );

    private:
        typedef std::map< OUString, rtl::Reference< SolidSession > > Map;

        Map m_aMap;
        std::mutex m_aMutex;
    };

} // namespace solid_ucp

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */