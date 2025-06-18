#ifndef INCLUDED_COM_SUN_STAR_UTIL_NOTLOCKEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_NOTLOCKEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/util/NotLockedException.hdl"

#include "com/sun/star/util/InvalidStateException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace util {

inline NotLockedException::NotLockedException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::util::InvalidStateException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::util::NotLockedException >::get();
}

inline NotLockedException::NotLockedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::util::InvalidStateException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::util::NotLockedException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
NotLockedException::NotLockedException(NotLockedException const & the_other): ::css::util::InvalidStateException(the_other) {}

NotLockedException::~NotLockedException() {}

NotLockedException & NotLockedException::operator =(NotLockedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::util::InvalidStateException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theNotLockedExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theNotLockedExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.util.NotLockedException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::util::InvalidStateException >::get();

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

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::NotLockedException const *) {
    return *detail::theNotLockedExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::NotLockedException const *) {
    return ::cppu::UnoType< ::css::util::NotLockedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_NOTLOCKEDEXCEPTION_HPP
