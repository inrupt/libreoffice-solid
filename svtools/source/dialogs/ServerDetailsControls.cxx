/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <com/sun/star/task/InteractionHandler.hpp>
#include <com/sun/star/task/PasswordContainer.hpp>
#include <com/sun/star/task/XPasswordContainer2.hpp>
#include <com/sun/star/ucb/XContentAccess.hpp>
#include <com/sun/star/sdbc/XResultSet.hpp>
#include <com/sun/star/sdbc/XRow.hpp>

#include <comphelper/processfactory.hxx>
#include <o3tl/safeint.hxx>
#include <rtl/uri.hxx>
#include <ucbhelper/content.hxx>
#include <ucbhelper/commandenvironment.hxx>
#include <comphelper/diagnose_ex.hxx>

#include <svtools/PlaceEditDialog.hxx>
#include <utility>
#include <config_oauth2.h>

#include "ServerDetailsControls.hxx"

using namespace com::sun::star::sdbc;
using namespace com::sun::star::task;
using namespace com::sun::star::ucb;
using namespace com::sun::star::uno;

DetailsContainer::DetailsContainer(PlaceEditDialog* pDialog)
    : m_pDialog(pDialog)
{
    m_pDialog->m_xEDPort->connect_output(LINK(this, DetailsContainer, FormatPortHdl));
}

//format without thousand separator
IMPL_STATIC_LINK(DetailsContainer, FormatPortHdl, weld::SpinButton&, rSpinButton, void)
{
    rSpinButton.set_text(OUString::number(rSpinButton.get_value()));
}

DetailsContainer::~DetailsContainer( )
{
}

void DetailsContainer::set_visible( bool )
{
    m_pDialog->m_xDetailsGrid->set_sensitive(true);

    m_pDialog->m_xEDHost->connect_changed( LINK( this, DetailsContainer, ValueChangeHdl ) );
    m_pDialog->m_xEDPort->connect_changed( LINK( this, DetailsContainer, ValueChangeHdl ) );
    m_pDialog->m_xEDRoot->connect_changed( LINK( this, DetailsContainer, ValueChangeHdl ) );
}

INetURLObject DetailsContainer::getUrl( )
{
    // Don't use that class directly: make it smarter by subclassing it.
    return INetURLObject( );
}

bool DetailsContainer::setUrl( const INetURLObject& )
{
    // That class doesn't contain any logic... it defers the dirty work
    // to the sub classes.
    return false;
}

void DetailsContainer::notifyChange( )
{
    m_aChangeHdl.Call( this );
}

IMPL_LINK_NOARG( DetailsContainer, ValueChangeHdl, weld::Entry&, void )
{
    notifyChange( );
}

HostDetailsContainer::HostDetailsContainer(PlaceEditDialog* pDialog, sal_uInt16 nPort, OUString sScheme) :
    DetailsContainer( pDialog ),
    m_nDefaultPort( nPort ),
    m_sScheme(std::move( sScheme ))
{
    set_visible( false );
}

void HostDetailsContainer::set_visible( bool bShow )
{
    m_pDialog->m_xFTHost->set_visible( bShow );
    m_pDialog->m_xHostBox->set_visible( bShow );
    m_pDialog->m_xEDRoot->set_visible( bShow );
    m_pDialog->m_xFTRoot->set_visible( bShow );

    DetailsContainer::set_visible( bShow );

    if ( bShow )
    {
        if (m_pDialog->m_xEDPort->get_value() == 0)
            m_pDialog->m_xEDPort->set_value( m_nDefaultPort );
        m_pDialog->m_xEDHost->set_text( m_sHost );
    }
    else
        m_pDialog->m_xEDPort->set_value( 0 );
}

INetURLObject HostDetailsContainer::getUrl( )
{
    OUString sHost = m_pDialog->m_xEDHost->get_text().trim();
    sal_Int64 nPort = m_pDialog->m_xEDPort->get_value();
    OUString sPath = m_pDialog->m_xEDRoot->get_text().trim();

    OUString sUrl;
    if ( !sHost.isEmpty( ) )
    {
        sUrl = m_sScheme + "://" + sHost;
        if ( nPort != m_nDefaultPort )
            sUrl += ":" + OUString::number( nPort );
        if ( !sPath.isEmpty( ) )
            if ( sPath.indexOf( '/' ) != 0 )
                sUrl += "/";
        sUrl += sPath;
    }

    return INetURLObject( sUrl );
}

bool HostDetailsContainer::setUrl( const INetURLObject& rUrl )
{
    bool bSuccess = verifyScheme( INetURLObject::GetScheme( rUrl.GetProtocol( ) ) );

    if ( bSuccess )
    {
        m_sHost = rUrl.GetHost( );
        m_pDialog->m_xEDHost->set_text( rUrl.GetHost( ) );
        m_pDialog->m_xEDPort->set_value( rUrl.GetPort( ) );
        m_pDialog->m_xEDRoot->set_text( rUrl.GetURLPath() );
    }

    return bSuccess;
}

bool HostDetailsContainer::verifyScheme( const OUString& sScheme )
{
    return sScheme == Concat2View( m_sScheme + "://" );
}

DavDetailsContainer::DavDetailsContainer(PlaceEditDialog* pBuilder)
    : HostDetailsContainer(pBuilder, 80, u"http"_ustr)
{
    m_pDialog->m_xCBDavs->connect_toggled(LINK(this, DavDetailsContainer, ToggledDavsHdl));

    set_visible( false );
}

void DavDetailsContainer::set_visible( bool bShow )
{
    HostDetailsContainer::set_visible( bShow );

    if ( !bShow )
        m_pDialog->m_xCBDavs->set_active(false);

    m_pDialog->m_xCBDavs->set_visible(bShow);
}

bool DavDetailsContainer::verifyScheme( const OUString& rScheme )
{
    bool bValid = false;
    if ( rScheme == "http://" )
    {
        bValid = true;
        m_pDialog->m_xCBDavs->set_active(false);
        ToggledDavsHdl(*m_pDialog->m_xCBDavs);
    }
    else if ( rScheme == "https://" )
    {
        bValid = true;
        m_pDialog->m_xCBDavs->set_active(true);
        ToggledDavsHdl(*m_pDialog->m_xCBDavs);
    }
    return bValid;
}

IMPL_LINK( DavDetailsContainer, ToggledDavsHdl, weld::Toggleable&, rCheckBox, void )
{
    // Change default port if needed
    bool bCheckedDavs = rCheckBox.get_active();
    if ( m_pDialog->m_xEDPort->get_value() == 80 && bCheckedDavs )
        m_pDialog->m_xEDPort->set_value( 443 );
    else if ( m_pDialog->m_xEDPort->get_value() == 443 && !bCheckedDavs )
        m_pDialog->m_xEDPort->set_value( 80 );

    OUString sScheme( u"http"_ustr );
    if ( bCheckedDavs )
        sScheme = "https";
    setScheme( sScheme );

    notifyChange( );
}

SolidDetailsContainer::SolidDetailsContainer(PlaceEditDialog* pDialog)
    : HostDetailsContainer(pDialog, 443, u"https"_ustr)
{
    m_pDialog->m_xEDHost->set_text(u"storage.inrupt.com"_ustr);
    m_pDialog->m_xEDServerName->set_text(u"PodSpaces"_ustr);
    set_visible( false );
}

void SolidDetailsContainer::set_visible( bool bShow )
{
    HostDetailsContainer::set_visible( bShow );

    if (bShow) {
        m_pDialog->m_xEDServerName->set_text(u"PodSpaces"_ustr);
        m_pDialog->SetLabelChanged();
        m_pDialog->m_xFTRoot->set_label(u"Client ID Document URL"_ustr);
        m_pDialog->m_xEDRoot->set_text(u"https://inrupt.github.io/libreoffice-solid/libreoffice-solid-client.json"_ustr);
        m_pDialog->m_xEDHost->set_placeholder_text(u"Paste your full pod URL here"_ustr);
    }

    m_pDialog->m_xFTUsernameLabel->set_visible(!bShow);
    m_pDialog->m_xEDUsername->set_visible(!bShow);
    m_pDialog->m_xFTPasswordLabel->set_visible(!bShow);
    m_pDialog->m_xEDPassword->set_visible(!bShow);
    m_pDialog->m_xCBPassword->set_visible(!bShow);
    m_pDialog->m_xFTPort->set_visible(!bShow);
    m_pDialog->m_xEDPort->set_visible(!bShow);
    m_pDialog->m_xCBDavs->set_visible(false);
}

INetURLObject SolidDetailsContainer::getUrl( )
{
    // Get the pod URL from the host field (user pastes full URL)
    OUString sPodUrl = m_pDialog->m_xEDHost->get_text().trim();

    if (sPodUrl.isEmpty())
        return INetURLObject();

    // Parse the pod URL to extract host and pod ID
    // Expected format: https://storage.inrupt.com/78d2ff57-2563-412f-836e-49d686118dd8/
    INetURLObject aPodUrl(sPodUrl);
    if (aPodUrl.GetProtocol() != INetProtocol::Https && aPodUrl.GetProtocol() != INetProtocol::Http)
        return INetURLObject();

    // Extract host (e.g., "storage.inrupt.com")
    OUString sHost = aPodUrl.GetHost();

    // Extract pod ID from the path (first path segment)
    OUString sPath = aPodUrl.GetURLPath();
    OUString sPodId;
    if (sPath.startsWith("/") && sPath.getLength() > 1)
    {
        sal_Int32 nSlashPos = sPath.indexOf('/', 1);
        if (nSlashPos == -1)
            sPodId = sPath.copy(1); // Remove leading slash
        else
            sPodId = sPath.copy(1, nSlashPos - 1); // Extract between slashes
    }

    // Construct vnd-solid URL: vnd-solid://host/podId
    OUString sVndSolidUrl = "vnd-solid://" + sHost;
    if (!sPodId.isEmpty())
        sVndSolidUrl += "/" + sPodId;

    return INetURLObject(sVndSolidUrl);
}

bool SolidDetailsContainer::setUrl( const INetURLObject& rUrl )
{
    OUString sUrl = rUrl.GetMainURL(INetURLObject::DecodeMechanism::NONE);

    // Check directly against the URL string since INetURLObject may not recognize vnd-solid scheme
    if (!sUrl.startsWith("vnd-solid://") && !sUrl.startsWith("vnd-solids://"))
        return false;

    // Handle vnd-solid:// URLs
    if (sUrl.startsWith("vnd-solid://"))
    {
        // Parse vnd-solid://host/podId format
        OUString sRemainder = sUrl.copy(12); // Remove "vnd-solid://"

        // Extract host and pod ID
        sal_Int32 nSlashPos = sRemainder.indexOf('/');
        OUString sHost, sPodId;

        if (nSlashPos != -1)
        {
            sHost = sRemainder.copy(0, nSlashPos);
            sPodId = sRemainder.copy(nSlashPos + 1);
        }
        else
        {
            sHost = sRemainder;
        }

        // Reconstruct the https:// pod URL for display in the host field
        OUString sPodUrl = "https://" + sHost;
        if (!sPodId.isEmpty())
            sPodUrl += "/" + sPodId;

        // Set the host field with the full pod URL (this is where user enters pod URL)
        m_pDialog->m_xEDHost->set_text(sPodUrl);

        // Keep the existing Client ID Document URL if already set, otherwise use default
        if (m_pDialog->m_xEDRoot->get_text().trim().isEmpty())
            m_pDialog->m_xEDRoot->set_text(u"https://inrupt.github.io/libreoffice-solid/libreoffice-solid-client.json"_ustr);

        return true;
    }

    // Handle vnd-solids:// URLs (secure variant)
    if (sUrl.startsWith("vnd-solids://"))
    {
        // Parse vnd-solids://host/podId format
        OUString sRemainder = sUrl.copy(13); // Remove "vnd-solids://"

        // Extract host and pod ID
        sal_Int32 nSlashPos = sRemainder.indexOf('/');
        OUString sHost, sPodId;

        if (nSlashPos != -1)
        {
            sHost = sRemainder.copy(0, nSlashPos);
            sPodId = sRemainder.copy(nSlashPos + 1);
        }
        else
        {
            sHost = sRemainder;
        }

        // Reconstruct the https:// pod URL for display in the host field
        OUString sPodUrl = "https://" + sHost;
        if (!sPodId.isEmpty())
            sPodUrl += "/" + sPodId;

        // Set the host field with the full pod URL
        m_pDialog->m_xEDHost->set_text(sPodUrl);

        // Keep the existing Client ID Document URL if already set, otherwise use default
        if (m_pDialog->m_xEDRoot->get_text().trim().isEmpty())
            m_pDialog->m_xEDRoot->set_text(u"https://inrupt.github.io/libreoffice-solid/libreoffice-solid-client.json"_ustr);

        return true;
    }

    return false;
}

bool SolidDetailsContainer::verifyScheme( const OUString& rScheme )
{
    // Solid pods use HTTPS URLs in user input, but we convert to vnd-solid internally
    return rScheme == "https://" || rScheme == "vnd-solid://" || rScheme == "vnd-solids://";
}

SmbDetailsContainer::SmbDetailsContainer(PlaceEditDialog* pDialog)
    : DetailsContainer(pDialog)
{
    m_pDialog->m_xEDShare->connect_changed( LINK( this, DetailsContainer, ValueChangeHdl ) );

    set_visible( false );
}

INetURLObject SmbDetailsContainer::getUrl( )
{
    OUString sHost = m_pDialog->m_xEDHost->get_text().trim( );
    OUString sShare = m_pDialog->m_xEDShare->get_text().trim( );
    OUString sPath = m_pDialog->m_xEDRoot->get_text().trim( );

    OUString sUrl;
    if ( !sHost.isEmpty( ) )
    {
        sUrl = "smb://" + sHost + "/";
        if ( !sShare.isEmpty( ) )
            sUrl += sShare;
        if ( !sPath.isEmpty( ) )
            if ( sPath.indexOf( '/' ) != 0 )
                sUrl += "/";
        sUrl += sPath;
    }

    return INetURLObject( sUrl );
}

bool SmbDetailsContainer::setUrl( const INetURLObject& rUrl )
{
    bool bSuccess =  rUrl.GetProtocol() == INetProtocol::Smb;

    if ( bSuccess )
    {
        OUString sShare = rUrl.getName( 0 );
        OUString sFullPath = rUrl.GetURLPath( );
        OUString sPath;
        if ( sFullPath.getLength( ) > sShare.getLength( ) )
        {
            sal_Int32 nPos = sShare.getLength( );
            if ( nPos != 0 )
                ++nPos;
            sPath = sFullPath.copy( nPos );
        }

        m_sHost = rUrl.GetHost( );
        m_pDialog->m_xEDHost->set_text( m_sHost );
        m_pDialog->m_xEDShare->set_text( sShare );
        m_pDialog->m_xEDRoot->set_text( sPath );
    }

    return bSuccess;
}

void SmbDetailsContainer::set_visible( bool bShow )
{
    m_pDialog->m_xEDShare->set_visible( bShow );
    m_pDialog->m_xFTShare->set_visible( bShow );
    m_pDialog->m_xEDRoot->set_visible( bShow );
    m_pDialog->m_xFTRoot->set_visible( bShow );

    m_pDialog->m_xFTHost->set_visible( bShow );
    m_pDialog->m_xHostBox->set_visible( bShow );
    m_pDialog->m_xEDPort->set_sensitive( !bShow );
    m_pDialog->m_xFTPort->set_sensitive( !bShow );

    if ( bShow )
        m_pDialog->m_xEDHost->set_text( m_sHost );
}

CmisDetailsContainer::CmisDetailsContainer(PlaceEditDialog* pParentDialog, OUString sBinding) :
    DetailsContainer( pParentDialog ),
    m_sUsername( ),
    m_xCmdEnv( ),
    m_aRepoIds( ),
    m_sRepoId( ),
    m_sBinding(std::move( sBinding )),
    m_xParentDialog(pParentDialog->getDialog()->GetXWindow())
{
    const Reference< XComponentContext >& xContext = ::comphelper::getProcessComponentContext();
    Reference< XInteractionHandler > xGlobalInteractionHandler =
        InteractionHandler::createWithParent(xContext, m_xParentDialog);
    m_xCmdEnv = new ucbhelper::CommandEnvironment( xGlobalInteractionHandler, Reference< XProgressHandler >() );

    set_visible( false );
}

void CmisDetailsContainer::set_visible( bool bShow )
{
    m_pDialog->m_xLBRepository->connect_changed( LINK( this, CmisDetailsContainer, SelectRepoHdl ) );
    m_pDialog->m_xBTRepoRefresh->connect_clicked( LINK( this, CmisDetailsContainer, RefreshReposHdl ) );

    m_pDialog->m_xEDHost->set_text( m_sBinding );

    if( ( m_sBinding == GDRIVE_BASE_URL )
            || m_sBinding.startsWith( ALFRESCO_CLOUD_BASE_URL )
            || ( m_sBinding == ONEDRIVE_BASE_URL ) )
    {
        m_pDialog->m_xFTHost->hide();
        m_pDialog->m_xHostBox->hide();
        m_pDialog->m_xFTRepository->hide();
        m_pDialog->m_xRepositoryBox->hide();
        m_pDialog->m_xEDRoot->hide();
        m_pDialog->m_xFTRoot->hide();
    }
    else
    {
        m_pDialog->m_xFTHost->set_visible( bShow );
        m_pDialog->m_xHostBox->set_visible( bShow );
        m_pDialog->m_xFTRepository->set_visible( bShow );
        m_pDialog->m_xRepositoryBox->set_visible( bShow );
        m_pDialog->m_xEDRoot->set_visible( bShow );
        m_pDialog->m_xFTRoot->set_visible( bShow );
    }

    DetailsContainer::set_visible( bShow );
    m_pDialog->m_xEDPort->set_sensitive( !bShow );
    m_pDialog->m_xFTPort->set_sensitive( !bShow );
}

INetURLObject CmisDetailsContainer::getUrl( )
{
    OUString sBindingUrl = m_pDialog->m_xEDHost->get_text().trim();
    OUString sPath = m_pDialog->m_xEDRoot->get_text().trim();

    bool bSkip = true;
    if( ( m_sBinding == GDRIVE_BASE_URL )
            || m_sBinding.startsWith( ALFRESCO_CLOUD_BASE_URL )
            || ( m_sBinding == ONEDRIVE_BASE_URL ) )
    {
        bSkip = m_sUsername.isEmpty();
    }
    else
    {
        bSkip = m_sRepoId.isEmpty();
    }

    OUString sUrl;
    if ( !sBindingUrl.isEmpty( ) && !bSkip )
    {
        OUString sEncodedBinding = rtl::Uri::encode(
                sBindingUrl + "#" + m_sRepoId,
                rtl_UriCharClassRelSegment,
                rtl_UriEncodeKeepEscapes,
                RTL_TEXTENCODING_UTF8 );
        sUrl = "vnd.libreoffice.cmis://" + sEncodedBinding;
    }
    sUrl += sPath;

    return INetURLObject( sUrl );
}

bool CmisDetailsContainer::setUrl( const INetURLObject& rUrl )
{
    bool bSuccess =  rUrl.GetProtocol() == INetProtocol::Cmis;

    if ( bSuccess )
    {
        OUString sDecodedHost = rUrl.GetHost( INetURLObject::DecodeMechanism::WithCharset );
        INetURLObject aHostUrl( sDecodedHost );
        m_sBinding = aHostUrl.GetURLNoMark( );
        m_sRepoId = aHostUrl.GetMark( );

        m_pDialog->m_xEDHost->set_text( m_sBinding );
        m_pDialog->m_xEDRoot->set_text( rUrl.GetURLPath() );
    }
    return bSuccess;
}

void CmisDetailsContainer::setUsername( const OUString& rUsername )
{
    m_sUsername = rUsername;
}

void CmisDetailsContainer::setPassword( const OUString& rPass )
{
    m_sPassword = rPass;
}

void CmisDetailsContainer::selectRepository( )
{
    // Get the repo ID and call the Change listener
    const int nPos = m_pDialog->m_xLBRepository->get_active();
    if( o3tl::make_unsigned(nPos) < m_aRepoIds.size() )
    {
        m_sRepoId = m_aRepoIds[nPos];
        notifyChange( );
    }
}

IMPL_LINK_NOARG( CmisDetailsContainer, RefreshReposHdl, weld::Button&, void  )
{
    const Reference< XComponentContext >& xContext = ::comphelper::getProcessComponentContext();
    Reference< XPasswordContainer2 > xMasterPasswd = PasswordContainer::create( xContext );


    OUString sBindingUrl = m_pDialog->m_xEDHost->get_text().trim( );

    OUString sEncodedUsername = u""_ustr;

    if ( !m_sUsername.isEmpty( ) )
    {
        sEncodedUsername = rtl::Uri::encode(m_sUsername,
                                            rtl_UriCharClassUserinfo,
                                            rtl_UriEncodeKeepEscapes,
                                            RTL_TEXTENCODING_UTF8 )
            + "@";
    }

    // Clean the listbox
    m_pDialog->m_xLBRepository->clear();
    m_aRepoIds.clear();

    // Compute the URL
    OUString sUrl;
    if ( !sBindingUrl.isEmpty( ) )
    {
        OUString sEncodedBinding = rtl::Uri::encode(
                sBindingUrl,
                rtl_UriCharClassRelSegment,
                rtl_UriEncodeKeepEscapes,
                RTL_TEXTENCODING_UTF8 );
        sUrl = "vnd.libreoffice.cmis://" + sEncodedUsername + sEncodedBinding;
    }

    // temporary remember the password
    try
    {
        if( !sUrl.isEmpty() && !m_sUsername.isEmpty() && !m_sPassword.isEmpty() )
        {
            Reference< XInteractionHandler > xInteractionHandler =
                InteractionHandler::createWithParent(xContext, m_xParentDialog);

            Sequence<OUString> aPasswd { m_sPassword };

            xMasterPasswd->add(
                sUrl, m_sUsername, aPasswd, xInteractionHandler );
        }
    }
    catch( const Exception& )
    {}

    try
    {
        // Get the Content
        ::ucbhelper::Content aCnt( sUrl, m_xCmdEnv, comphelper::getProcessComponentContext() );
        Sequence<OUString> aProps { u"Title"_ustr };
        Reference< XResultSet > xResultSet( aCnt.createCursor( aProps ), UNO_SET_THROW );
        Reference< XContentAccess > xAccess( xResultSet, UNO_QUERY_THROW );
        while ( xResultSet->next() )
        {
            OUString sURL = xAccess->queryContentIdentifierString( );
            INetURLObject aURL( sURL );
            OUString sId = aURL.GetURLPath( INetURLObject::DecodeMechanism::WithCharset );
            sId = sId.copy( 1 );
            m_aRepoIds.push_back( sId );

            Reference< XRow > xRow( xResultSet, UNO_QUERY );
            OUString sName = xRow->getString( 1 );
            m_pDialog->m_xLBRepository->append_text(sName);
        }
    }
    catch ( const Exception&)
    {
        TOOLS_WARN_EXCEPTION( "svtools.dialogs", "RefreshReposHdl" );
    }

    // Auto-select the first one
    if (m_pDialog->m_xLBRepository->get_count() > 0)
    {
        m_pDialog->m_xLBRepository->set_active(0);
        selectRepository( );
    }

    // remove temporary password
    try
    {
        xMasterPasswd->remove( sUrl, m_sUsername );
    }
    catch( const Exception& )
    {}
}

IMPL_LINK_NOARG( CmisDetailsContainer, SelectRepoHdl, weld::ComboBox&, void )
{
    selectRepository( );
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
