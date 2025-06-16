/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "solidcontent.hxx"
#include "solidprovider.hxx"
#include <com/sun/star/ucb/IllegalIdentifierException.hpp>
#include <com/sun/star/ucb/ContentInfoAttribute.hpp>
#include <com/sun/star/ucb/OpenCommandArgument3.hpp>
#include <com/sun/star/ucb/TransferInfo.hpp>
#include <com/sun/star/beans/PropertyAttribute.hpp>
#include <com/sun/star/beans/PropertyValue.hpp>
#include <com/sun/star/beans/PropertySetInfoChange.hpp>
#include <com/sun/star/beans/PropertySetInfoChangeEvent.hpp>
#include <com/sun/star/ucb/CommandInfo.hpp>
#include <com/sun/star/ucb/InsertCommandArgument.hpp>
#include <com/sun/star/ucb/UnsupportedCommandException.hpp>
#include <ucbhelper/propertyvalueset.hxx>
#include <ucbhelper/contentidentifier.hxx>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <osl/mutex.hxx>

using namespace css;
using namespace solid_ucp;

Content::Content(const uno::Reference<uno::XComponentContext>& rxContext,
                ContentProvider* pProvider,
                const uno::Reference<ucb::XContentIdentifier>& Identifier)
: ContentImplHelper(rxContext, pProvider, Identifier)
, m_xProvider(pProvider)
{
}

// XInterface methods
css::uno::Any SAL_CALL Content::queryInterface(const css::uno::Type& rType)
{
    css::uno::Any aRet = cppu::queryInterface(rType,
                                             static_cast<lang::XTypeProvider*>(this),
                                             static_cast<lang::XServiceInfo*>(this),
                                             static_cast<ucb::XContent*>(this));
    return aRet.hasValue() ? aRet : ContentImplHelper::queryInterface(rType);
}

void SAL_CALL Content::acquire() noexcept
{
    ContentImplHelper::acquire();
}

void SAL_CALL Content::release() noexcept
{
    ContentImplHelper::release();
}

// XTypeProvider methods
css::uno::Sequence<sal_Int8> SAL_CALL Content::getImplementationId()
{
    return css::uno::Sequence<sal_Int8>();
}

css::uno::Sequence<css::uno::Type> SAL_CALL Content::getTypes()
{
    static cppu::OTypeCollection s_aCollection(
                    cppu::UnoType<lang::XTypeProvider>::get(),
                    cppu::UnoType<lang::XServiceInfo>::get(),
                    cppu::UnoType<ucb::XContent>::get());

    return s_aCollection.getTypes();
}

// XServiceInfo methods
OUString SAL_CALL Content::getImplementationName()
{
    return u"com.sun.star.comp.ucb.SolidContent"_ustr;
}

css::uno::Sequence<OUString> SAL_CALL Content::getSupportedServiceNames()
{
    return { u"com.sun.star.ucb.SolidContent"_ustr };
}

// XContent methods
OUString SAL_CALL Content::getContentType()
{
    // TODO: Determine if this is a collection or document
    return SOLID_CONTENT_TYPE;
}

// XCommandProcessor methods
css::uno::Any SAL_CALL Content::execute(
    const css::ucb::Command& aCommand,
    sal_Int32 CommandId,
    const css::uno::Reference<css::ucb::XCommandEnvironment>& Environment)
{
    (void)CommandId;
    (void)Environment;
    
    css::uno::Any aRet;
    
    if (aCommand.Name == "getPropertyValues")
    {
        // Return empty property set for now
        aRet <<= css::uno::Sequence<css::beans::PropertyValue>();
    }
    else if (aCommand.Name == "setPropertyValues")
    {
        // Return empty sequence for now
        aRet <<= css::uno::Sequence<css::uno::Any>();
    }
    else if (aCommand.Name == "getCommandInfo")
    {
        // Return our command info
        aRet <<= getCommands(Environment);
    }
    else if (aCommand.Name == "getPropertySetInfo")
    {
        // Return our property info
        aRet <<= getProperties(Environment);
    }
    else
    {
        // Unsupported command
        throw css::ucb::UnsupportedCommandException(aCommand.Name, static_cast<css::ucb::XContent*>(this));
    }
    
    return aRet;
}

void SAL_CALL Content::abort(sal_Int32 CommandId)
{
    (void)CommandId;
    // TODO: Implement command abortion for Solid operations
}

// Non-interface methods
bool Content::initResourceAccess()
{
    // TODO: Initialize Solid resource access
    return true;
}

bool Content::exchangeIdentity(const css::uno::Reference<css::ucb::XContentIdentifier>& xNewId)
{
    if (!xNewId.is())
        return false;

    osl::MutexGuard aGuard(m_aMutex);
    
    // Update our internal state - the identifier is managed by base class
    // Following WebDAV pattern for identity exchange
    
    return true;
}

// Pure virtual methods from ContentImplHelper
css::uno::Sequence<css::beans::Property> Content::getProperties(
    const css::uno::Reference<css::ucb::XCommandEnvironment>& xEnv)
{
    (void)xEnv;
    // TODO: Return Solid-specific properties
    static css::beans::Property aProperties[] = {
        css::beans::Property("Title", -1, cppu::UnoType<OUString>::get(), 
                            css::beans::PropertyAttribute::BOUND),
        css::beans::Property("ContentType", -1, cppu::UnoType<OUString>::get(), 
                            css::beans::PropertyAttribute::BOUND | css::beans::PropertyAttribute::READONLY),
        css::beans::Property("IsDocument", -1, cppu::UnoType<bool>::get(), 
                            css::beans::PropertyAttribute::BOUND | css::beans::PropertyAttribute::READONLY),
        css::beans::Property("IsFolder", -1, cppu::UnoType<bool>::get(), 
                            css::beans::PropertyAttribute::BOUND | css::beans::PropertyAttribute::READONLY)
    };
    return css::uno::Sequence<css::beans::Property>(aProperties, SAL_N_ELEMENTS(aProperties));
}

css::uno::Sequence<css::ucb::CommandInfo> Content::getCommands(
    const css::uno::Reference<css::ucb::XCommandEnvironment>& xEnv)
{
    (void)xEnv;
    // TODO: Return Solid-specific commands
    static css::ucb::CommandInfo aCommands[] = {
        css::ucb::CommandInfo("getPropertyValues", -1, cppu::UnoType<css::uno::Sequence<css::beans::Property>>::get()),
        css::ucb::CommandInfo("setPropertyValues", -1, cppu::UnoType<css::uno::Sequence<css::beans::PropertyValue>>::get()),
        css::ucb::CommandInfo("getPropertySetInfo", -1, cppu::UnoType<void>::get()),
        css::ucb::CommandInfo("open", -1, cppu::UnoType<css::ucb::OpenCommandArgument3>::get()),
        css::ucb::CommandInfo("insert", -1, cppu::UnoType<css::ucb::InsertCommandArgument>::get()),
        css::ucb::CommandInfo("delete", -1, cppu::UnoType<bool>::get())
    };
    return css::uno::Sequence<css::ucb::CommandInfo>(aCommands, SAL_N_ELEMENTS(aCommands));
}

OUString Content::getParentURL()
{
    // TODO: Extract parent URL from current identifier
    OUString aURL = getIdentifier()->getContentIdentifier();
    sal_Int32 nPos = aURL.lastIndexOf('/');
    if (nPos > 0)
        return aURL.copy(0, nPos);
    return OUString();
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */