/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidSessionFactory.hxx"
#include "SolidSession.hxx"

using namespace com::sun::star;

namespace libreoffice { namespace solid {

SolidSessionFactory::SolidSessionFactory() {}

SolidSessionFactory::~SolidSessionFactory() {}

rtl::Reference<SolidSession> SolidSessionFactory::createSession(
    const OUString& rURL,
    const uno::Reference<uno::XComponentContext>& rxContext)
{
    // Create a null reference for the session factory parameter
    rtl::Reference<SolidSession> nullSession;
    return new SolidSession(nullSession, rURL, rxContext);
}

} // namespace solid
} // namespace libreoffice

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */