#ifndef INCLUDED_COM_SUN_STAR_UCB_XINTERACTIONSUPPLYAUTHENTICATION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_XINTERACTIONSUPPLYAUTHENTICATION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/XInteractionSupplyAuthentication.hdl"

#include "com/sun/star/task/XInteractionContinuation.hpp"
#include "com/sun/star/ucb/RememberAuthentication.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "osl/mutex.hxx"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

#if defined LIBO_INTERNAL_ONLY
#include <type_traits>
#endif

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theXInteractionSupplyAuthenticationType : public rtl::StaticWithInit< ::css::uno::Type *, theXInteractionSupplyAuthenticationType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.XInteractionSupplyAuthentication" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::task::XInteractionContinuation > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetRealm" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.ucb.XInteractionSupplyAuthentication::setRealm" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetUserName" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.ucb.XInteractionSupplyAuthentication::setUserName" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );
        ::rtl::OUString sMethodName4( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetPassword" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName4.pData );
        ::rtl::OUString sMethodName5( "com.sun.star.ucb.XInteractionSupplyAuthentication::setPassword" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName5.pData );
        ::rtl::OUString sMethodName6( "com.sun.star.ucb.XInteractionSupplyAuthentication::getRememberPasswordModes" );
        typelib_typedescriptionreference_new( &pMembers[6],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName6.pData );
        ::rtl::OUString sMethodName7( "com.sun.star.ucb.XInteractionSupplyAuthentication::setRememberPassword" );
        typelib_typedescriptionreference_new( &pMembers[7],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName7.pData );
        ::rtl::OUString sMethodName8( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetAccount" );
        typelib_typedescriptionreference_new( &pMembers[8],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName8.pData );
        ::rtl::OUString sMethodName9( "com.sun.star.ucb.XInteractionSupplyAuthentication::setAccount" );
        typelib_typedescriptionreference_new( &pMembers[9],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName9.pData );
        ::rtl::OUString sMethodName10( "com.sun.star.ucb.XInteractionSupplyAuthentication::getRememberAccountModes" );
        typelib_typedescriptionreference_new( &pMembers[10],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName10.pData );
        ::rtl::OUString sMethodName11( "com.sun.star.ucb.XInteractionSupplyAuthentication::setRememberAccount" );
        typelib_typedescriptionreference_new( &pMembers[11],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName11.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            12,
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
        typelib_typedescriptionreference_release( pMembers[8] );
        typelib_typedescriptionreference_release( pMembers[9] );
        typelib_typedescriptionreference_release( pMembers[10] );
        typelib_typedescriptionreference_release( pMembers[11] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::XInteractionSupplyAuthentication const *) {
    const ::css::uno::Type &rRet = *detail::theXInteractionSupplyAuthenticationType::get();
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

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType0( "boolean" );
                ::rtl::OUString sMethodName0( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetRealm" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType0.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Realm" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType1( "void" );
                ::rtl::OUString sMethodName1( "com.sun.star.ucb.XInteractionSupplyAuthentication::setRealm" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    5, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType1.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType2( "boolean" );
                ::rtl::OUString sMethodName2( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetUserName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    6, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType2.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "UserName" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType3( "void" );
                ::rtl::OUString sMethodName3( "com.sun.star.ucb.XInteractionSupplyAuthentication::setUserName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType3.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType4( "boolean" );
                ::rtl::OUString sMethodName4( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetPassword" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType4.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Password" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType5( "void" );
                ::rtl::OUString sMethodName5( "com.sun.star.ucb.XInteractionSupplyAuthentication::setPassword" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    9, sal_False,
                    sMethodName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType5.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Default" );
                ::rtl::OUString sParamType0( "com.sun.star.ucb.RememberAuthentication" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ENUM;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_False;
                aParameters[0].bOut = sal_True;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType6( "[]com.sun.star.ucb.RememberAuthentication" );
                ::rtl::OUString sMethodName6( "com.sun.star.ucb.XInteractionSupplyAuthentication::getRememberPasswordModes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    10, sal_False,
                    sMethodName6.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType6.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Remember" );
                ::rtl::OUString sParamType0( "com.sun.star.ucb.RememberAuthentication" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ENUM;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType7( "void" );
                ::rtl::OUString sMethodName7( "com.sun.star.ucb.XInteractionSupplyAuthentication::setRememberPassword" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    11, sal_False,
                    sMethodName7.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType7.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType8( "boolean" );
                ::rtl::OUString sMethodName8( "com.sun.star.ucb.XInteractionSupplyAuthentication::canSetAccount" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    12, sal_False,
                    sMethodName8.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType8.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Account" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType9( "void" );
                ::rtl::OUString sMethodName9( "com.sun.star.ucb.XInteractionSupplyAuthentication::setAccount" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    13, sal_False,
                    sMethodName9.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType9.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Default" );
                ::rtl::OUString sParamType0( "com.sun.star.ucb.RememberAuthentication" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ENUM;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_False;
                aParameters[0].bOut = sal_True;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType10( "[]com.sun.star.ucb.RememberAuthentication" );
                ::rtl::OUString sMethodName10( "com.sun.star.ucb.XInteractionSupplyAuthentication::getRememberAccountModes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    14, sal_False,
                    sMethodName10.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE, sReturnType10.pData,
                    1, aParameters,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "Remember" );
                ::rtl::OUString sParamType0( "com.sun.star.ucb.RememberAuthentication" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ENUM;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType11( "void" );
                ::rtl::OUString sMethodName11( "com.sun.star.ucb.XInteractionSupplyAuthentication::setRememberAccount" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    15, sal_False,
                    sMethodName11.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_VOID, sReturnType11.pData,
                    1, aParameters,
                    1, the_Exceptions );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::ucb::XInteractionSupplyAuthentication > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XInteractionSupplyAuthentication > >::get();
}

::css::uno::Type const & ::css::ucb::XInteractionSupplyAuthentication::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::ucb::XInteractionSupplyAuthentication >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::ucb::XInteractionSupplyAuthentication>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_UCB_XINTERACTIONSUPPLYAUTHENTICATION_HPP
