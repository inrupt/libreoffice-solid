#ifndef INCLUDED_COM_SUN_STAR_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/lang/ArrayIndexOutOfBoundsException.hdl"

#include "com/sun/star/lang/IndexOutOfBoundsException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace lang {

inline ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::lang::IndexOutOfBoundsException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::lang::ArrayIndexOutOfBoundsException >::get();
}

inline ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::lang::IndexOutOfBoundsException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::lang::ArrayIndexOutOfBoundsException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(ArrayIndexOutOfBoundsException const & the_other): ::css::lang::IndexOutOfBoundsException(the_other) {}

ArrayIndexOutOfBoundsException::~ArrayIndexOutOfBoundsException() {}

ArrayIndexOutOfBoundsException & ArrayIndexOutOfBoundsException::operator =(ArrayIndexOutOfBoundsException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::lang::IndexOutOfBoundsException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace lang { namespace detail {

struct theArrayIndexOutOfBoundsExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theArrayIndexOutOfBoundsExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.lang.ArrayIndexOutOfBoundsException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::lang::IndexOutOfBoundsException >::get();

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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::lang::ArrayIndexOutOfBoundsException const *) {
    return *detail::theArrayIndexOutOfBoundsExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::lang::ArrayIndexOutOfBoundsException const *) {
    return ::cppu::UnoType< ::css::lang::ArrayIndexOutOfBoundsException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_LANG_ARRAYINDEXOUTOFBOUNDSEXCEPTION_HPP
