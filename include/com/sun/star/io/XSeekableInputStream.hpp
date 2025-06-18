#ifndef INCLUDED_COM_SUN_STAR_IO_XSEEKABLEINPUTSTREAM_HPP
#define INCLUDED_COM_SUN_STAR_IO_XSEEKABLEINPUTSTREAM_HPP

#include "sal/config.h"

#include "com/sun/star/io/XSeekableInputStream.hdl"

#include "com/sun/star/io/XInputStream.hpp"
#include "com/sun/star/io/XSeekable.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace io { namespace detail {

struct theXSeekableInputStreamType : public rtl::StaticWithInit< ::css::uno::Type *, theXSeekableInputStreamType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.io.XSeekableInputStream" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::io::XInputStream > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< ::css::uno::Reference< ::css::io::XSeekable > >::get().getTypeLibType();

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            2, aSuperTypes,
            0,
            0 );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::XSeekableInputStream const *) {
    const ::css::uno::Type &rRet = *detail::theXSeekableInputStreamType::get();
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::io::XSeekableInputStream > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::io::XSeekableInputStream > >::get();
}

::css::uno::Type const & ::css::io::XSeekableInputStream::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::io::XSeekableInputStream >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::io::XSeekableInputStream>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_IO_XSEEKABLEINPUTSTREAM_HPP
