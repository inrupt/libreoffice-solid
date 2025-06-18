#ifndef INCLUDED_COM_SUN_STAR_IO_XTEMPFILE_HPP
#define INCLUDED_COM_SUN_STAR_IO_XTEMPFILE_HPP

#include "sal/config.h"

#include "com/sun/star/io/XTempFile.hdl"

#include "com/sun/star/io/XSeekable.hpp"
#include "com/sun/star/io/XStream.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace io { namespace detail {

struct theXTempFileType : public rtl::StaticWithInit< ::css::uno::Type *, theXTempFileType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.io.XTempFile" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[2];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::io::XStream > >::get().getTypeLibType();
        aSuperTypes[1] = ::cppu::UnoType< ::css::uno::Reference< ::css::io::XSeekable > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[3] = { 0,0,0 };
        ::rtl::OUString sAttributeName0( "com.sun.star.io.XTempFile::RemoveFile" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName0.pData );
        ::rtl::OUString sAttributeName1( "com.sun.star.io.XTempFile::Uri" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName1.pData );
        ::rtl::OUString sAttributeName2( "com.sun.star.io.XTempFile::ResourceName" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName2.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            2, aSuperTypes,
            3,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescriptionreference_release( pMembers[2] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace io {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::io::XTempFile const *) {
    const ::css::uno::Type &rRet = *detail::theXTempFileType::get();
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

            typelib_InterfaceAttributeTypeDescription * pAttribute = 0;
            {
                ::rtl::OUString sAttributeType0( "boolean" );
                ::rtl::OUString sAttributeName0( "com.sun.star.io.XTempFile::RemoveFile" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    8, sAttributeName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sAttributeType0.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType1( "string" );
                ::rtl::OUString sAttributeName1( "com.sun.star.io.XTempFile::Uri" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    9, sAttributeName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType1.pData,
                    sal_True, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType2( "string" );
                ::rtl::OUString sAttributeName2( "com.sun.star.io.XTempFile::ResourceName" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    10, sAttributeName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType2.pData,
                    sal_True, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            typelib_typedescription_release( (typelib_TypeDescription*)pAttribute );
        }
    }
    else
    {
        OSL_DOUBLE_CHECKED_LOCKING_MEMORY_BARRIER();
    }
    return rRet;
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::io::XTempFile > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::io::XTempFile > >::get();
}

::css::uno::Type const & ::css::io::XTempFile::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::io::XTempFile >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::io::XTempFile>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_IO_XTEMPFILE_HPP
