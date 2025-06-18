#ifndef INCLUDED_COM_SUN_STAR_REGISTRY_XIMPLEMENTATIONREGISTRATION2_HPP
#define INCLUDED_COM_SUN_STAR_REGISTRY_XIMPLEMENTATIONREGISTRATION2_HPP

#include "sal/config.h"

#include "com/sun/star/registry/XImplementationRegistration2.hdl"

#include "com/sun/star/registry/CannotRegisterImplementationException.hpp"
#include "com/sun/star/registry/XImplementationRegistration.hpp"
#include "com/sun/star/registry/XSimpleRegistry.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace registry { namespace detail {

struct theXImplementationRegistration2Type : public rtl::StaticWithInit< ::css::uno::Type *, theXImplementationRegistration2Type >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.registry.XImplementationRegistration2" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::registry::XImplementationRegistration > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[1] = { 0 };
        ::rtl::OUString sMethodName0( "com.sun.star.registry.XImplementationRegistration2::registerImplementationWithLocation" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            1,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace registry {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::registry::XImplementationRegistration2 const *) {
    const ::css::uno::Type &rRet = *detail::theXImplementationRegistration2Type::get();
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
            ::cppu::UnoType< ::css::registry::CannotRegisterImplementationException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "aImplementationLoader" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "aLocation" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "aRegisteredLocation" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "xReg" );
                ::rtl::OUString sParamType3( "com.sun.star.registry.XSimpleRegistry" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_INTERFACE;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.registry.CannotRegisterImplementationException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "void" );
                ::rtl::OUString sMethodName0( "com.sun.star.registry.XImplementationRegistration2::registerImplementationWithLocation" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType0.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            typelib_typedescription_release( (typelib_TypeDescription*)pMethod );
        }
    }
    else
    {
        OSL_DOUBLE_CHECKED_LOCKING_MEMORY_BARRIER();
    }
    return rRet;
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::registry::XImplementationRegistration2 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::registry::XImplementationRegistration2 > >::get();
}

::css::uno::Type const & ::css::registry::XImplementationRegistration2::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::registry::XImplementationRegistration2 >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::registry::XImplementationRegistration2>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_REGISTRY_XIMPLEMENTATIONREGISTRATION2_HPP
