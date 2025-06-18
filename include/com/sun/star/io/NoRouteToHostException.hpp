#ifndef INCLUDED_COM_SUN_STAR_IO_NOROUTETOHOSTEXCEPTION_HPP
#define INCLUDED_COM_SUN_STAR_IO_NOROUTETOHOSTEXCEPTION_HPP

#include "sal/config.h"

#include "com/sun/star/io/NoRouteToHostException.hdl"

#include "com/sun/star/io/SocketException.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace io {

inline NoRouteToHostException::NoRouteToHostException(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::io::SocketException(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
{
    ::cppu::UnoType< ::css::io::NoRouteToHostException >::get();
}

inline NoRouteToHostException::NoRouteToHostException(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::io::SocketException(Message_, Context_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
{
    ::cppu::UnoType< ::css::io::NoRouteToHostException >::get();
}

#if !defined LIBO_INTERNAL_ONLY
NoRouteToHostException::NoRouteToHostException(NoRouteToHostException const & the_other): ::css::io::SocketException(the_other) {}

NoRouteToHostException::~NoRouteToHostException() {}

NoRouteToHostException & NoRouteToHostException::operator =(NoRouteToHostException const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::io::SocketException::operator =(the_other);
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace io { namespace detail {

struct theNoRouteToHostExceptionType : public rtl::StaticWithInit< ::css::uno::Type *, theNoRouteToHostExceptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.io.NoRouteToHostException" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::io::SocketException >::get();

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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::NoRouteToHostException const *) {
    return *detail::theNoRouteToHostExceptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::io::NoRouteToHostException const *) {
    return ::cppu::UnoType< ::css::io::NoRouteToHostException >::get();
}

#endif // INCLUDED_COM_SUN_STAR_IO_NOROUTETOHOSTEXCEPTION_HPP
