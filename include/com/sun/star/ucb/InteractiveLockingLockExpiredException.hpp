#ifndef INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGLOCKEXPIREDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGLOCKEXPIREDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InteractiveLockingLockExpiredException.hdl"

#include "com/sun/star/ucb/InteractiveLockingException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb {

inline InteractiveLockingLockExpiredException::InteractiveLockingLockExpiredException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveLockingException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::ucb::InteractiveLockingLockExpiredException >::get();
}

inline InteractiveLockingLockExpiredException::InteractiveLockingLockExpiredException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::css::task::InteractionClassification& Classification_, const ::rtl::OUString& Url_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::ucb::InteractiveLockingException(Message_, Context_, Classification_, Url_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::ucb::InteractiveLockingLockExpiredException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
InteractiveLockingLockExpiredException::InteractiveLockingLockExpiredException(InteractiveLockingLockExpiredException const & the_other): ::css::ucb::InteractiveLockingException(the_other) {}

InteractiveLockingLockExpiredException::~InteractiveLockingLockExpiredException() {}

InteractiveLockingLockExpiredException & InteractiveLockingLockExpiredException::operator =(InteractiveLockingLockExpiredException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::ucb::InteractiveLockingException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInteractiveLockingLockExpiredExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theInteractiveLockingLockExpiredExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.InteractiveLockingLockExpiredException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::ucb::InteractiveLockingException >::get();

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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveLockingLockExpiredException const *) {
    return *detail::theInteractiveLockingLockExpiredExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InteractiveLockingLockExpiredException const *) {
    return ::cppu::UnoType< ::css::ucb::InteractiveLockingLockExpiredException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INTERACTIVELOCKINGLOCKEXPIREDEXCEPTION_HPP
