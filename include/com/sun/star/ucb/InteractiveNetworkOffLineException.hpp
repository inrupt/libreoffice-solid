#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKOFFLINEEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKOFFLINEEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveNetworkOffLineException.hdl"

#include "com/sun/star/ucb/InteractiveNetworkException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveNetworkOffLineException::InteractiveNetworkOffLineException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::ucb::InteractiveNetworkOffLineException >::get();
}

inline InteractiveNetworkOffLineException::InteractiveNetworkOffLineException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveNetworkException(Message_, Context_, Classification_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::ucb::InteractiveNetworkOffLineException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveNetworkOffLineException::InteractiveNetworkOffLineException(InteractiveNetworkOffLineException const & the_other): ::css::ucb::InteractiveNetworkException(the_other) {}

InteractiveNetworkOffLineException::~InteractiveNetworkOffLineException() {}

InteractiveNetworkOffLineException & InteractiveNetworkOffLineException::operator =(InteractiveNetworkOffLineException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveNetworkException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveNetworkOffLineExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveNetworkOffLineExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveNetworkOffLineException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::InteractiveNetworkException >::get();

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            0,
            0 );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkOffLineException const *) {
    return *detail::theInteractiveNetworkOffLineExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveNetworkOffLineException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveNetworkOffLineException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVENETWORKOFFLINEEXCEPTION_HPP
