#ifndef INCLUDED_COM_SUN_STAR_CONTAINER_XMAP_HPP
#define INCLUDED_COM_SUN_STAR_CONTAINER_XMAP_HPP

#include "sal/config.h"

#include "com/sun/star/container/XMap.hdl"

#include "com/sun/star/beans/IllegalTypeException.hpp"
#include "com/sun/star/container/NoSuchElementException.hpp"
#include "com/sun/star/container/XElementAccess.hpp"
#include "com/sun/star/lang/IllegalArgumentException.hpp"
#include "com/sun/star/lang/NoSupportException.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace container { namespace detail {

struct theXMapType : public rtl::StaticWithInit< ::css::uno::Type *, theXMapType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.container.XMap" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::container::XElementAccess > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[8] = { 0,0,0,0,0,0,0,0 };
        ::rtl::OUString sAttributeName0( "com.sun.star.container.XMap::KeyType" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName0.pData );
        ::rtl::OUString sAttributeName1( "com.sun.star.container.XMap::ValueType" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName1.pData );
        ::rtl::OUString sMethodName0( "com.sun.star.container.XMap::clear" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.container.XMap::containsKey" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.container.XMap::containsValue" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.container.XMap::get" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );
        ::rtl::OUString sMethodName4( "com.sun.star.container.XMap::put" );
        typelib_typedescriptionreference_new( &pMembers[6],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName4.pData );
        ::rtl::OUString sMethodName5( "com.sun.star.container.XMap::remove" );
        typelib_typedescriptionreference_new( &pMembers[7],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName5.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            8,
            pMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescriptionreference_release( pMembers[0] );
        typelib_typedescriptionreference_release( pMembers[1] );
        typelib_typedescriptionreference_release( pMembers[2] );
        typelib_typedescriptionreference_release( pMembers[3] );
        typelib_typedescriptionreference_release( pMembers[4] );
        typelib_typedescriptionreference_release( pMembers[5] );
        typelib_typedescriptionreference_release( pMembers[6] );
        typelib_typedescriptionreference_release( pMembers[7] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace container {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::container::XMap const *) {
    const ::css::uno::Type &rRet = *detail::theXMapType::get();
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
            ::cppu::UnoType< ::css::lang::NoSupportException >::get();
            ::cppu::UnoType< ::css::beans::IllegalTypeException >::get();
            ::cppu::UnoType< ::css::lang::IllegalArgumentException >::get();
            ::cppu::UnoType< ::css::container::NoSuchElementException >::get();

            typelib_InterfaceAttributeTypeDescription * pAttribute = 0;
            {
                ::rtl::OUString sAttributeType0( "type" );
                ::rtl::OUString sAttributeName0( "com.sun.star.container.XMap::KeyType" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    5, sAttributeName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_TYPE, sAttributeType0.pData,
                    sal_True, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType1( "type" );
                ::rtl::OUString sAttributeName1( "com.sun.star.container.XMap::ValueType" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    6, sAttributeName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_TYPE, sAttributeType1.pData,
                    sal_True, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            typelib_typedescription_release( (typelib_TypeDescription*)pAttribute );

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.NoSupportException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "void" );
                ::rtl::OUString sMethodName0( "com.sun.star.container.XMap::clear" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType0.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Key" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.beans.IllegalTypeException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType1( "boolean" );
                ::rtl::OUString sMethodName1( "com.sun.star.container.XMap::containsKey" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType1.pData,
                    1, aParameters,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Value" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.beans.IllegalTypeException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData };
                ::rtl::OUString sReturnType2( "boolean" );
                ::rtl::OUString sMethodName2( "com.sun.star.container.XMap::containsValue" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    9, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType2.pData,
                    1, aParameters,
                    3, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Key" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.beans.IllegalTypeException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.container.NoSuchElementException" );
                ::rtl::OUString the_ExceptionName3( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData, the_ExceptionName3.pData };
                ::rtl::OUString sReturnType3( "any" );
                ::rtl::OUString sMethodName3( "com.sun.star.container.XMap::get" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    10, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ANY, sReturnType3.pData,
                    1, aParameters,
                    4, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "Key" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "Value" );
                ::rtl::OUString sParamType1( "any" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.NoSupportException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.beans.IllegalTypeException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName3( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData, the_ExceptionName3.pData };
                ::rtl::OUString sReturnType4( "any" );
                ::rtl::OUString sMethodName4( "com.sun.star.container.XMap::put" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    11, sal_False,
                    sMethodName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ANY, sReturnType4.pData,
                    2, aParameters,
                    4, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Key" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.lang.NoSupportException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.beans.IllegalTypeException" );
                ::rtl::OUString the_ExceptionName2( "com.sun.star.lang.IllegalArgumentException" );
                ::rtl::OUString the_ExceptionName3( "com.sun.star.container.NoSuchElementException" );
                ::rtl::OUString the_ExceptionName4( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData, the_ExceptionName2.pData, the_ExceptionName3.pData, the_ExceptionName4.pData };
                ::rtl::OUString sReturnType5( "any" );
                ::rtl::OUString sMethodName5( "com.sun.star.container.XMap::remove" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    12, sal_False,
                    sMethodName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_ANY, sReturnType5.pData,
                    1, aParameters,
                    5, the_Exceptions );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::container::XMap > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::container::XMap > >::get();
}

::css::uno::Type const & ::css::container::XMap::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::container::XMap >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::container::XMap>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_CONTAINER_XMAP_HPP
