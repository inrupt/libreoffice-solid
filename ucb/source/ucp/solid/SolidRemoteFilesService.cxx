/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidRemoteFilesService.hxx"
#include "SolidConfigDialog.hxx"
#include "SolidServiceDetector.hxx"
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/configuration/theDefaultProvider.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <comphelper/processfactory.hxx>

using namespace com::sun::star;
using namespace solid::libreoffice;

SolidRemoteFilesService::SolidRemoteFilesService(
    const uno::Reference<uno::XComponentContext>& rxContext)
    : m_xContext(rxContext)
{
}

SolidRemoteFilesService::~SolidRemoteFilesService()
{
}

// XServiceInfo
rtl::OUString SAL_CALL SolidRemoteFilesService::getImplementationName()
{
    return rtl::OUString("com.sun.star.comp.SolidRemoteFilesService");
}

sal_Bool SAL_CALL SolidRemoteFilesService::supportsService(const rtl::OUString& ServiceName)
{
    return ServiceName == "com.sun.star.ui.dialogs.RemoteFilesService";
}

uno::Sequence<rtl::OUString> SAL_CALL SolidRemoteFilesService::getSupportedServiceNames()
{
    uno::Sequence<rtl::OUString> aSeq(1);
    aSeq[0] = rtl::OUString("com.sun.star.ui.dialogs.RemoteFilesService");
    return aSeq;
}

// XRemoteFilesService
rtl::OUString SAL_CALL SolidRemoteFilesService::getServiceName()
{
    return rtl::OUString("Solid");
}

rtl::OUString SAL_CALL SolidRemoteFilesService::getServiceDisplayName()
{
    return rtl::OUString("Solid Pod Storage");
}

rtl::OUString SAL_CALL SolidRemoteFilesService::getServiceIcon()
{
    // Return path to Solid icon if we have one
    return rtl::OUString();
}

sal_Bool SAL_CALL SolidRemoteFilesService::canAddService()
{
    return sal_True;
}

sal_Bool SAL_CALL SolidRemoteFilesService::canEditService()
{
    return sal_True;
}

sal_Bool SAL_CALL SolidRemoteFilesService::canRemoveService()
{
    return sal_True;
}

uno::Any SAL_CALL SolidRemoteFilesService::showAddServiceDialog(
    const uno::Reference<awt::XWindow>& xParent)
{
    vcl::Window* pParent = VCLUnoHelper::GetWindow(xParent);
    ScopedVclPtr<SolidConfigDialog> xDialog(VclPtr<SolidConfigDialog>::Create(pParent));
    
    if (xDialog->Execute() == RET_OK)
    {
        SolidServiceConfig config = xDialog->getServiceConfig();
        
        // Store service configuration
        storeServiceConfig(config);
        
        // Return service information
        uno::Sequence<beans::PropertyValue> aResult(4);
        aResult[0].Name = "ServiceName";
        aResult[0].Value <<= config.serviceName;
        aResult[1].Name = "Url";
        aResult[1].Value <<= config.podUrl;
        aResult[2].Name = "Type";
        aResult[2].Value <<= rtl::OUString("Solid");
        aResult[3].Name = "Username";
        aResult[3].Value <<= config.webId;
        
        return uno::Any(aResult);
    }
    
    return uno::Any();
}

uno::Any SAL_CALL SolidRemoteFilesService::showEditServiceDialog(
    const uno::Reference<awt::XWindow>& xParent,
    const uno::Sequence<beans::PropertyValue>& aService)
{
    vcl::Window* pParent = VCLUnoHelper::GetWindow(xParent);
    ScopedVclPtr<SolidConfigDialog> xDialog(VclPtr<SolidConfigDialog>::Create(pParent));
    
    // Load existing configuration
    SolidServiceConfig config = loadServiceConfig(aService);
    xDialog->setServiceConfig(config);
    
    if (xDialog->Execute() == RET_OK)
    {
        config = xDialog->getServiceConfig();
        storeServiceConfig(config);
        
        // Return updated service information
        uno::Sequence<beans::PropertyValue> aResult(4);
        aResult[0].Name = "ServiceName";
        aResult[0].Value <<= config.serviceName;
        aResult[1].Name = "Url";
        aResult[1].Value <<= config.podUrl;
        aResult[2].Name = "Type";
        aResult[2].Value <<= rtl::OUString("Solid");
        aResult[3].Name = "Username";
        aResult[3].Value <<= config.webId;
        
        return uno::Any(aResult);
    }
    
    return uno::Any();
}

void SolidRemoteFilesService::storeServiceConfig(const SolidServiceConfig& config)
{
    try
    {
        // Store configuration in LibreOffice's configuration system
        uno::Reference<lang::XMultiServiceFactory> xConfigProvider =
            configuration::theDefaultProvider::get(m_xContext);
        
        // TODO: Implement actual configuration storage
        // This would store the service configuration in the registry
        // so it appears in the Remote Files dropdown
    }
    catch (const uno::Exception&)
    {
        // Handle configuration errors
    }
}

SolidServiceConfig SolidRemoteFilesService::loadServiceConfig(
    const uno::Sequence<beans::PropertyValue>& aService)
{
    SolidServiceConfig config;
    
    for (const auto& prop : aService)
    {
        if (prop.Name == "ServiceName")
            prop.Value >>= config.serviceName;
        else if (prop.Name == "Url")
            prop.Value >>= config.podUrl;
        else if (prop.Name == "Username")
            prop.Value >>= config.webId;
    }
    
    return config;
}

// Component registration
extern "C" SAL_DLLPUBLIC_EXPORT void* SAL_CALL component_getFactory(
    const char* pImplName, void* pServiceManager, void*)
{
    void* pRet = nullptr;
    
    if (rtl_str_compare(pImplName, "com.sun.star.comp.SolidRemoteFilesService") == 0)
    {
        uno::Reference<lang::XMultiServiceFactory> xSMgr(
            static_cast<lang::XMultiServiceFactory*>(pServiceManager),
            uno::UNO_QUERY);
        
        uno::Reference<lang::XSingleServiceFactory> xFactory(
            cppu::createSingleFactory(
                xSMgr,
                "com.sun.star.comp.SolidRemoteFilesService",
                [](const uno::Reference<uno::XComponentContext>& xContext) -> uno::Reference<uno::XInterface>
                {
                    return static_cast<cppu::OWeakObject*>(new SolidRemoteFilesService(xContext));
                },
                uno::Sequence<rtl::OUString>{"com.sun.star.ui.dialogs.RemoteFilesService"}));
        
        if (xFactory.is())
        {
            xFactory->acquire();
            pRet = xFactory.get();
        }
    }
    
    return pRet;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */