#ifndef INCLUDED_COM_SUN_STAR_LANG_NOTINITIALIZEDEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_LANG_NOTINITIALIZEDEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/lang/NotInitializedException.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace lang {

inline NotInitializedException::NotInitializedException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::uno::RuntimeException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::lang::NotInitializedException >::get();
}

inline NotInitializedException::NotInitializedException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::uno::RuntimeException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::lang::NotInitializedException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
NotInitializedException::NotInitializedException(NotInitializedException const & the_other): ::css::uno::RuntimeException(the_other) {}

NotInitializedException::~NotInitializedException() {}

NotInitializedException & NotInitializedException::operator =(NotInitializedException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::uno::RuntimeException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theNotInitializedExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theNotInitializedExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.lang.NotInitializedException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::uno::RuntimeException >::get();

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

namespace com { namespace sun { namespace star { namespace lang {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::NotInitializedException const *) {
    return *detail::theNotInitializedExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::NotInitializedException const *) {
    return ::cppu::UnoType< ::css::lang::NotInitializedException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_NOTINITIALIZEDEXCEPTION_HPP
