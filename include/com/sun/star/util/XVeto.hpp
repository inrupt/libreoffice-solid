#ifndef INCLUDED_COM_SUN_STAR_UTIL_XVETO_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XVETO_HPP

#include "sal/config.h"

#include "com/sun/star/util/XVeto.hdl"

#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theXVetoType : public rtl::StaticWithInit< ::css::uno::Type *, theXVetoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.util.XVeto" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[2] = { 0,0 };
        ::rtl::OUString sAttributeName0( "com.sun.star.util.XVeto::Reason" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName0.pData );
        ::rtl::OUString sAttributeName1( "com.sun.star.util.XVeto::Details" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName1.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            2,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XVeto const *) {
    const ::css::uno::Type &rRet = *detail::theXVetoType::get();
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
                ::rtl::OUString sAttributeType0( "string" );
                ::rtl::OUString sAttributeName0( "com.sun.star.util.XVeto::Reason" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    3, sAttributeName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType0.pData,
                    sal_True, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType1( "any" );
                ::rtl::OUString sAttributeName1( "com.sun.star.util.XVeto::Details" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    4, sAttributeName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ANY, sAttributeType1.pData,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XVeto > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XVeto > >::get();
}

::css::uno::Type const & ::css::util::XVeto::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XVeto >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::util::XVeto>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_UTIL_XVETO_HPP
