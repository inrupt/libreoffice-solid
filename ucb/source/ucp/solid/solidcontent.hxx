/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <rtl/ustring.hxx>
#include <com/sun/star/ucb/XContent.hpp>
#include <com/sun/star/ucb/XContentIdentifier.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <cppuhelper/implbase_ex.hxx>
#include <cppuhelper/implbase2.hxx>

using rtl::OUString;

namespace libreoffice { namespace solid {

class ContentProvider;

class Content : public cppu::WeakImplHelper2<css::ucb::XContent, css::lang::XServiceInfo>
{
private:
    ContentProvider* m_pProvider;
    css::uno::Reference<css::uno::XComponentContext> m_xContext;
    css::uno::Reference<css::ucb::XContentIdentifier> m_xIdentifier;

public:
    Content(const css::uno::Reference<css::uno::XComponentContext>& rxContext,
           ContentProvider* pProvider,
           const css::uno::Reference<css::ucb::XContentIdentifier>& Identifier);

    // XInterface
    virtual css::uno::Any SAL_CALL queryInterface(const css::uno::Type& rType) override;
    virtual void SAL_CALL acquire() noexcept override;
    virtual void SAL_CALL release() noexcept override;

    // XTypeProvider
    virtual css::uno::Sequence<sal_Int8> SAL_CALL getImplementationId() override;
    virtual css::uno::Sequence<css::uno::Type> SAL_CALL getTypes() override;

    // XServiceInfo
    virtual OUString SAL_CALL getImplementationName() override;
    virtual css::uno::Sequence<OUString> SAL_CALL getSupportedServiceNames() override;

    // XContent
    virtual css::uno::Reference<css::ucb::XContentIdentifier> SAL_CALL getIdentifier() override;
    virtual OUString SAL_CALL getContentType() override;

    // Non-interface methods
    bool initResourceAccess();
    bool exchangeIdentity(const css::uno::Reference<css::ucb::XContentIdentifier>& xNewId);
};

} // namespace libreoffice
} // namespace libreoffice

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */