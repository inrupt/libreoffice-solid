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
#include <vcl/weld.hxx>
#include <vcl/svapp.hxx>
#include <tools/urlobj.hxx>

using namespace com::sun::star;
using namespace libreoffice::solid;

SolidConfigDialog::SolidConfigDialog(weld::Window* pParent)
    : weld::GenericDialogController(pParent, "modules/ucb/ui/SolidConfigDialog.ui", "SolidConfigDialog")
    , m_xServiceNameEdit(m_xBuilder->weld_entry("entry_service_name"))
    , m_xPodUrlEdit(m_xBuilder->weld_entry("entry_pod_url"))
    , m_xWebIdEdit(m_xBuilder->weld_entry("entry_webid"))
    , m_xDpopCheck(m_xBuilder->weld_check_button("check_dpop"))
    , m_xRememberCheck(m_xBuilder->weld_check_button("check_remember"))
    , m_xTestButton(m_xBuilder->weld_button("button_test"))
    , m_xOkButton(m_xBuilder->weld_button("button_ok"))
    , m_xCancelButton(m_xBuilder->weld_button("button_cancel"))
{

    // Set up event handlers
    m_xTestButton->connect_clicked(LINK(this, SolidConfigDialog, TestConnectionHdl));
    m_xOkButton->connect_clicked(LINK(this, SolidConfigDialog, OkHdl));
    m_xCancelButton->connect_clicked(LINK(this, SolidConfigDialog, CancelHdl));

    // Validate URL as user types
    m_xPodUrlEdit->connect_changed(LINK(this, SolidConfigDialog, UrlModifyHdl));

    // Set default values
    m_xDpopCheck->set_active(true);
    m_xRememberCheck->set_active(true);
}

SolidConfigDialog::~SolidConfigDialog()
{
}

SolidServiceConfig SolidConfigDialog::getServiceConfig() const
{
    SolidServiceConfig config;
    config.serviceName = m_xServiceNameEdit->get_text();
    config.podUrl = m_xPodUrlEdit->get_text();
    config.webId = m_xWebIdEdit->get_text();
    config.enableDpop = m_xDpopCheck->get_active();
    config.rememberCredentials = m_xRememberCheck->get_active();
    return config;
}

void SolidConfigDialog::setServiceConfig(const SolidServiceConfig& config)
{
    m_xServiceNameEdit->set_text(config.serviceName);
    m_xPodUrlEdit->set_text(config.podUrl);
    m_xWebIdEdit->set_text(config.webId);
    m_xDpopCheck->set_active(config.enableDpop);
    m_xRememberCheck->set_active(config.rememberCredentials);
}

IMPL_LINK_NOARG(SolidConfigDialog, TestConnectionHdl, weld::Button&, void)
{
    OUString sPodUrl = m_xPodUrlEdit->get_text();

    if (sPodUrl.isEmpty())
    {
        std::unique_ptr<weld::MessageDialog> xWarning(
            Application::CreateMessageDialog(m_xDialog.get(), VclMessageType::Warning, VclButtonsType::Ok,
                "Please enter a pod URL first."));
        xWarning->run();
        return;
    }

    if (!SolidServiceDetector::isSolidUrl(sPodUrl))
    {
        std::unique_ptr<weld::MessageDialog> xWarning(
            Application::CreateMessageDialog(m_xDialog.get(), VclMessageType::Warning, VclButtonsType::Ok,
                "Invalid Solid pod URL. Please enter a valid URL like:\nhttps://storage.inrupt.com/YOUR-POD-ID"));
        xWarning->run();
        return;
    }

    std::unique_ptr<weld::MessageDialog> xInfo(
        Application::CreateMessageDialog(m_xDialog.get(), VclMessageType::Info, VclButtonsType::Ok,
            "Connection test functionality available.\nURL format appears valid."));
    xInfo->run();
}

IMPL_LINK_NOARG(SolidConfigDialog, OkHdl, weld::Button&, void)
{
    OUString sPodUrl = m_xPodUrlEdit->get_text();
    OUString sServiceName = m_xServiceNameEdit->get_text();

    if (sServiceName.isEmpty())
    {
        std::unique_ptr<weld::MessageDialog> xWarning(Application::CreateMessageDialog(m_xDialog.get(),
            VclMessageType::Warning, VclButtonsType::Ok, "Please enter a service name."));
        xWarning->run();
        m_xServiceNameEdit->grab_focus();
        return;
    }

    if (sPodUrl.isEmpty())
    {
        std::unique_ptr<weld::MessageDialog> xWarning(Application::CreateMessageDialog(m_xDialog.get(),
            VclMessageType::Warning, VclButtonsType::Ok, "Please enter a pod URL."));
        xWarning->run();
        m_xPodUrlEdit->grab_focus();
        return;
    }

    if (!SolidServiceDetector::isSolidUrl(sPodUrl))
    {
        std::unique_ptr<weld::MessageDialog> xWarning(Application::CreateMessageDialog(m_xDialog.get(),
            VclMessageType::Warning, VclButtonsType::Ok,
            "Invalid Solid pod URL. Please enter a valid URL like:\nhttps://storage.inrupt.com/YOUR-POD-ID"));
        xWarning->run();
        m_xPodUrlEdit->grab_focus();
        return;
    }

    m_xDialog->response(RET_OK);
}

IMPL_LINK_NOARG(SolidConfigDialog, CancelHdl, weld::Button&, void)
{
    m_xDialog->response(RET_CANCEL);
}

IMPL_LINK_NOARG(SolidConfigDialog, UrlModifyHdl, weld::Entry&, void)
{
    OUString sUrl = m_xPodUrlEdit->get_text();

    // Enable/disable OK button based on URL validity
    bool bValidUrl = !sUrl.isEmpty() && SolidServiceDetector::isSolidUrl(sUrl);
    m_xOkButton->set_sensitive(bValidUrl && !m_xServiceNameEdit->get_text().isEmpty());
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */