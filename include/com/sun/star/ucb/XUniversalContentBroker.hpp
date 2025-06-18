#ifndef INCLUDED_COM_SUN_STAR_UCB_XUNIVERSALCONTENTBROKER_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XUNIVERSALCONTENTBROKER_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XUniversalContentBroker.hdl"

#include "com/sun/star/lang/XComponent.hpp"
#include "com/sun/star/ucb/XCommandProcessor2.hpp"
#include "com/sun/star/ucb/XContentIdentifierFactory.hpp"
#include "com/sun/star/ucb/XContentProvider.hpp"
#include "com/sun/star/ucb/XContentProviderManager.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theXUniversalContentBrokerType : public rtl::StaticWithInit< ::css::uno::Type *, theXUniversalContentBrokerType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.XUniversalContentBroker" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[5];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::lang::XComponent > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentProvider > >::get().getTypeLibType();
        aSuperTypes[2] = ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentProviderManager > >::get().getTypeLibType();
        aSuperTypes[3] = ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentIdentifierFactory > >::get().getTypeLibType();
        aSuperTypes[4] = ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XCommandProcessor2 > >::get().getTypeLibType();

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            5, aSuperTypes,
            0,
            0 );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::XUniversalContentBroker const *) {
    const ::css::uno::Type &rRet = *detail::theXUniversalContentBrokerType::get();
    // End inline typedescription generation
    static bool bInitStarted = false;
    if (!bInitStarted)
    {
        ::osl::MutexGuard aGuard( ::osl::Mutex::getGlobalMutex() );
        if (!bInitStarted)
        {
            OSL_DOUBLE_CHECKED_LOCKING_MEMORY_BARRIER();
            bInitStarted = true;
            ::cppu::UnoType< ::css::uno::RuntimeException >::get();
        }
    }
    else
    {
        OSL_DOUBLE_CHECKED_LOCKING_MEMORY_BARRIER();
    }
    return rRet;
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ucb::XUniversalContentBroker > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XUniversalContentBroker > >::get();
}

::css::uno::Type const & ::css::ucb::XUniversalContentBroker::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ucb::XUniversalContentBroker >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::ucb::XUniversalContentBroker>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_UCB_XUNIVERSALCONTENTBROKER_HPP
