#ifndef INCLUDED_COM_SUN_STAR_IO_UNKNOWNHOSTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_IO_UNKNOWNHOSTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/io/UnknownHostException.hdl"

#include "com/sun/star/io/IOException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace io {

inline UnknownHostException::UnknownHostException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::io::IOException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::io::UnknownHostException >::get();
}

inline UnknownHostException::UnknownHostException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::io::IOException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::io::UnknownHostException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
UnknownHostException::UnknownHostException(UnknownHostException const & the_other): ::css::io::IOException(the_other) {}

UnknownHostException::~UnknownHostException() {}

UnknownHostException & UnknownHostException::operator =(UnknownHostException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::io::IOException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace io { namespace detail {

struct theUnknownHostExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theUnknownHostExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.io.UnknownHostException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::io::IOException >::get();

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

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::UnknownHostException const *) {
    return *detail::theUnknownHostExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::io::UnknownHostException const *) {
    return ::cppu::UnoType< ::css::io::UnknownHostException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_UNKNOWNHOSTEXCEPTION_HPP
