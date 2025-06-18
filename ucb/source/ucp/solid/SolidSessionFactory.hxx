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
#include <rtl/ustring.hxx>

using rtl::OUString;
namespace css = com::sun::star;
#include <salhelper/simplereferenceobject.hxx>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/Reference.hxx>

namespace solid { namespace libreoffice
{
    class SolidSession;

    class SolidSessionFactory : public salhelper::SimpleReferenceObject
    {
    public:
        SolidSessionFactory();
        virtual ~SolidSessionFactory() override;

        virtual rtl::Reference<SolidSession> createSession(
            const OUString& rURL,
            const css::uno::Reference<css::uno::XComponentContext>& rxContext);
    };

} // namespace libreoffice
} // namespace solid

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */