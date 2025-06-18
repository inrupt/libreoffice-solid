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
#include <com/sun/star/sdbc/XRow.hpp>
#include <cppuhelper/queryinterface.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <osl/mutex.hxx>
#include "SolidOAuth.hxx"

using namespace css;
using namespace solid::libreoffice;

Content::Content(const uno::Reference<uno::XComponentContext>& rxContext,
                ContentProvider* pProvider,
                const uno::Reference<ucb::XContentIdentifier>& Identifier)
: m_pProvider(pProvider)
, m_xContext(rxContext)
, m_xIdentifier(Identifier)
{
}

// XInterface methods
css::uno::Any SAL_CALL Content::queryInterface(const css::uno::Type& rType)
{
    css::uno::Any aRet = cppu::queryInterface(rType,
                                             static_cast<lang::XTypeProvider*>(this),
                                             static_cast<lang::XServiceInfo*>(this),
                                             static_cast<ucb::XContent*>(this));
    return aRet.hasValue() ? aRet : cppu::WeakImplHelper2<css::ucb::XContent, css::lang::XServiceInfo>::queryInterface(rType);
}

void SAL_CALL Content::acquire() noexcept
{
    cppu::WeakImplHelper2<css::ucb::XContent, css::lang::XServiceInfo>::acquire();
}

void SAL_CALL Content::release() noexcept
{
    cppu::WeakImplHelper2<css::ucb::XContent, css::lang::XServiceInfo>::release();
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
css::uno::Reference<css::ucb::XContentIdentifier> SAL_CALL Content::getIdentifier()
{
    return m_xIdentifier;
}

OUString SAL_CALL Content::getContentType()
{
    return SOLID_CONTENT_TYPE;
}

// Non-interface methods
bool Content::initResourceAccess()
{
    return true; // Simplified for now
}

bool Content::exchangeIdentity(const css::uno::Reference<css::ucb::XContentIdentifier>& xNewId)
{
    m_xIdentifier = xNewId;
    return true;
}

