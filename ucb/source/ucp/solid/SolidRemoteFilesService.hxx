/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "SolidConfigDialog.hxx"
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/ui/dialogs/XRemoteFilesService.hpp>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/awt/XWindow.hpp>
#include <cppuhelper/implbase2.hxx>

namespace solid { namespace libreoffice {

class SolidRemoteFilesService : public cppu::WeakImplHelper2<
    css::ui::dialogs::XRemoteFilesService,
    css::lang::XServiceInfo>
{
private:
    css::uno::Reference<css::uno::XComponentContext> m_xContext;
    
    void storeServiceConfig(const SolidServiceConfig& config);
    SolidServiceConfig loadServiceConfig(const css::uno::Sequence<css::beans::PropertyValue>& aService);

public:
    explicit SolidRemoteFilesService(const css::uno::Reference<css::uno::XComponentContext>& rxContext);
    virtual ~SolidRemoteFilesService() override;
    
    // XServiceInfo
    virtual rtl::OUString SAL_CALL getImplementationName() override;
    virtual sal_Bool SAL_CALL supportsService(const rtl::OUString& ServiceName) override;
    virtual css::uno::Sequence<rtl::OUString> SAL_CALL getSupportedServiceNames() override;
    
    // XRemoteFilesService
    virtual rtl::OUString SAL_CALL getServiceName() override;
    virtual rtl::OUString SAL_CALL getServiceDisplayName() override;
    virtual rtl::OUString SAL_CALL getServiceIcon() override;
    virtual sal_Bool SAL_CALL canAddService() override;
    virtual sal_Bool SAL_CALL canEditService() override;
    virtual sal_Bool SAL_CALL canRemoveService() override;
    virtual css::uno::Any SAL_CALL showAddServiceDialog(
        const css::uno::Reference<css::awt::XWindow>& xParent) override;
    virtual css::uno::Any SAL_CALL showEditServiceDialog(
        const css::uno::Reference<css::awt::XWindow>& xParent,
        const css::uno::Sequence<css::beans::PropertyValue>& aService) override;
};

} // namespace libreoffice
} // namespace solid

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */