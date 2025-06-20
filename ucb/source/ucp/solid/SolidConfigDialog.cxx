/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "SolidConfigDialog.hxx"
#include "SolidServiceDetector.hxx"
#include <vcl/msgbox.hxx>
#include <tools/urlobj.hxx>

using namespace com::sun::star;
using namespace solid::libreoffice;

SolidConfigDialog::SolidConfigDialog(vcl::Window* pParent)
    : ModalDialog(pParent, "SolidConfigDialog", "ui/SolidConfigDialog.ui")
{
    get(m_pServiceNameEdit, "entry_service_name");
    get(m_pPodUrlEdit, "entry_pod_url");
    get(m_pWebIdEdit, "entry_webid");
    get(m_pDpopCheck, "check_dpop");
    get(m_pRememberCheck, "check_remember");
    get(m_pTestButton, "button_test");
    get(m_pOkButton, "button_ok");
    get(m_pCancelButton, "button_cancel");
    
    // Set up event handlers
    m_pTestButton->SetClickHdl(LINK(this, SolidConfigDialog, TestConnectionHdl));
    m_pOkButton->SetClickHdl(LINK(this, SolidConfigDialog, OkHdl));
    m_pCancelButton->SetClickHdl(LINK(this, SolidConfigDialog, CancelHdl));
    
    // Validate URL as user types
    m_pPodUrlEdit->SetModifyHdl(LINK(this, SolidConfigDialog, UrlModifyHdl));
    
    // Set default values
    m_pDpopCheck->Check(true);
    m_pRememberCheck->Check(true);
}

SolidConfigDialog::~SolidConfigDialog()
{
    disposeOnce();
}

void SolidConfigDialog::dispose()
{
    m_pServiceNameEdit.clear();
    m_pPodUrlEdit.clear();
    m_pWebIdEdit.clear();
    m_pDpopCheck.clear();
    m_pRememberCheck.clear();
    m_pTestButton.clear();
    m_pOkButton.clear();
    m_pCancelButton.clear();
    ModalDialog::dispose();
}

SolidServiceConfig SolidConfigDialog::getServiceConfig() const
{
    SolidServiceConfig config;
    config.serviceName = m_pServiceNameEdit->GetText();
    config.podUrl = m_pPodUrlEdit->GetText();
    config.webId = m_pWebIdEdit->GetText();
    config.enableDpop = m_pDpopCheck->IsChecked();
    config.rememberCredentials = m_pRememberCheck->IsChecked();
    return config;
}

void SolidConfigDialog::setServiceConfig(const SolidServiceConfig& config)
{
    m_pServiceNameEdit->SetText(config.serviceName);
    m_pPodUrlEdit->SetText(config.podUrl);
    m_pWebIdEdit->SetText(config.webId);
    m_pDpopCheck->Check(config.enableDpop);
    m_pRememberCheck->Check(config.rememberCredentials);
}

IMPL_LINK_NOARG(SolidConfigDialog, TestConnectionHdl, Button*, void)
{
    rtl::OUString sPodUrl = m_pPodUrlEdit->GetText();
    
    if (sPodUrl.isEmpty())
    {
        ScopedVclPtr<MessageDialog> xWarning(
            VclPtr<MessageDialog>::Create(this, "Please enter a pod URL first.", VCL_MESSAGE_WARNING));
        xWarning->Execute();
        return;
    }
    
    if (!SolidServiceDetector::isSolidUrl(sPodUrl))
    {
        ScopedVclPtr<MessageDialog> xWarning(
            VclPtr<MessageDialog>::Create(this, "Invalid Solid pod URL. Please enter a valid URL like:\nhttps://storage.inrupt.com/YOUR-POD-ID", VCL_MESSAGE_WARNING));
        xWarning->Execute();
        return;
    }
    
    // TODO: Implement actual connection test using existing OAuth code
    ScopedVclPtr<MessageDialog> xInfo(
        VclPtr<MessageDialog>::Create(this, "Connection test will be implemented.\nURL format appears valid.", VCL_MESSAGE_INFO));
    xInfo->Execute();
}

IMPL_LINK_NOARG(SolidConfigDialog, OkHdl, Button*, void)
{
    rtl::OUString sPodUrl = m_pPodUrlEdit->GetText();
    rtl::OUString sServiceName = m_pServiceNameEdit->GetText();
    
    if (sServiceName.isEmpty())
    {
        ScopedVclPtr<MessageDialog> xWarning(
            VclPtr<MessageDialog>::Create(this, "Please enter a service name.", VCL_MESSAGE_WARNING));
        xWarning->Execute();
        m_pServiceNameEdit->GrabFocus();
        return;
    }
    
    if (sPodUrl.isEmpty())
    {
        ScopedVclPtr<MessageDialog> xWarning(
            VclPtr<MessageDialog>::Create(this, "Please enter a pod URL.", VCL_MESSAGE_WARNING));
        xWarning->Execute();
        m_pPodUrlEdit->GrabFocus();
        return;
    }
    
    if (!SolidServiceDetector::isSolidUrl(sPodUrl))
    {
        ScopedVclPtr<MessageDialog> xWarning(
            VclPtr<MessageDialog>::Create(this, "Invalid Solid pod URL. Please enter a valid URL like:\nhttps://storage.inrupt.com/YOUR-POD-ID", VCL_MESSAGE_WARNING));
        xWarning->Execute();
        m_pPodUrlEdit->GrabFocus();
        return;
    }
    
    EndDialog(RET_OK);
}

IMPL_LINK_NOARG(SolidConfigDialog, CancelHdl, Button*, void)
{
    EndDialog(RET_CANCEL);
}

IMPL_LINK_NOARG(SolidConfigDialog, UrlModifyHdl, Edit&, void)
{
    rtl::OUString sUrl = m_pPodUrlEdit->GetText();
    
    // Enable/disable OK button based on URL validity
    bool bValidUrl = !sUrl.isEmpty() && SolidServiceDetector::isSolidUrl(sUrl);
    m_pOkButton->Enable(bValidUrl && !m_pServiceNameEdit->GetText().isEmpty());
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */