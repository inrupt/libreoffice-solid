#ifndef INCLUDED_COM_SUN_STAR_UTIL_XNUMBERFORMATPREVIEWER_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XNUMBERFORMATPREVIEWER_HPP

#include "sal/config.h"

#include "com/sun/star/util/XNumberFormatPreviewer.hdl"

#include "com/sun/star/lang/Locale.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/util/Color.hpp"
#include "com/sun/star/util/MalformedNumberFormatException.hpp"
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

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theXNumberFormatPreviewerType : public rtl::StaticWithInit< ::css::uno::Type *, theXNumberFormatPreviewerType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.util.XNumberFormatPreviewer" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[2] = { 0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.util.XNumberFormatPreviewer::convertNumberToPreviewString" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.util.XNumberFormatPreviewer::queryPreviewColorForNumber" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );

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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XNumberFormatPreviewer const *) {
    const ::css::uno::Type &rRet = *detail::theXNumberFormatPreviewerType::get();
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
            ::cppu::UnoType< ::css::util::MalformedNumberFormatException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "aFormat" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "fValue" );
                ::rtl::OUString sParamType1( "double" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_DOUBLE;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "nLocale" );
                ::rtl::OUString sParamType2( "com.sun.star.lang.Locale" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRUCT;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "bAllowEnglish" );
                ::rtl::OUString sParamType3( "boolean" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.util.MalformedNumberFormatException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "string" );
                ::rtl::OUString sMethodName0( "com.sun.star.util.XNumberFormatPreviewer::convertNumberToPreviewString" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    3, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType0.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[5];
                ::rtl::OUString sParamName0( "aFormat" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "fValue" );
                ::rtl::OUString sParamType1( "double" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_DOUBLE;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "nLocale" );
                ::rtl::OUString sParamType2( "com.sun.star.lang.Locale" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRUCT;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "bAllowEnglish" );
                ::rtl::OUString sParamType3( "boolean" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString sParamName4( "aDefaultColor" );
                ::rtl::OUString sParamType4( "long" );
                aParameters[4].pParamName = sParamName4.pData;
                aParameters[4].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[4].pTypeName = sParamType4.pData;
                aParameters[4].bIn = sal_True;
                aParameters[4].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.util.MalformedNumberFormatException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType1( "long" );
                ::rtl::OUString sMethodName1( "com.sun.star.util.XNumberFormatPreviewer::queryPreviewColorForNumber" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType1.pData,
                    5, aParameters,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XNumberFormatPreviewer > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XNumberFormatPreviewer > >::get();
}

::css::uno::Type const & ::css::util::XNumberFormatPreviewer::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XNumberFormatPreviewer >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::util::XNumberFormatPreviewer>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_UTIL_XNUMBERFORMATPREVIEWER_HPP
