/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include <ucbhelper/contenthelper.hxx>
#include <com/sun/star/io/XInputStream.hpp>

namespace solid_ucp {

class ContentProvider;

class Content : public ::ucbhelper::ContentImplHelper
{
private:
    rtl::Reference<ContentProvider> m_xProvider;

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
    virtual OUString SAL_CALL getContentType() override;

    // XCommandProcessor
    virtual css::uno::Any SAL_CALL execute(
        const css::ucb::Command& aCommand,
        sal_Int32 CommandId,
        const css::uno::Reference<css::ucb::XCommandEnvironment>& Environment) override;
    virtual void SAL_CALL abort(sal_Int32 CommandId) override;

    // Pure virtual methods from ContentImplHelper
    virtual css::uno::Sequence<css::beans::Property> getProperties(
        const css::uno::Reference<css::ucb::XCommandEnvironment>& xEnv) override;
    virtual css::uno::Sequence<css::ucb::CommandInfo> getCommands(
        const css::uno::Reference<css::ucb::XCommandEnvironment>& xEnv) override;
    virtual OUString getParentURL() override;

    // Non-interface methods
    bool initResourceAccess();
    bool exchangeIdentity(const css::uno::Reference<css::ucb::XContentIdentifier>& xNewId);
};

}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */