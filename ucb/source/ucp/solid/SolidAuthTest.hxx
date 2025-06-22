/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <cppuhelper/implbase1.hxx>
#include <rtl/ustring.hxx>

using rtl::OUString;

namespace libreoffice { namespace solid {

class SolidAuthTest : public cppu::WeakImplHelper1<css::lang::XServiceInfo>
{
private:
    css::uno::Reference<css::uno::XComponentContext> m_xContext;

public:
    explicit SolidAuthTest(const css::uno::Reference<css::uno::XComponentContext>& xContext);
    virtual ~SolidAuthTest();

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual sal_Bool SAL_CALL supportsService(const OUString& ServiceName) override;
    virtual css::uno::Sequence<OUString> SAL_CALL getSupportedServiceNames() override;

    // Test methods
    bool testDPoPAuthentication(const OUString& podUrl);
};

} // namespace libreoffice
} // namespace libreoffice