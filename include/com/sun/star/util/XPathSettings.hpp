#ifndef INCLUDED_COM_SUN_STAR_UTIL_XPATHSETTINGS_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_XPATHSETTINGS_HPP

#include "sal/config.h"

#include "com/sun/star/util/XPathSettings.hdl"

#include "com/sun/star/beans/XPropertySet.hpp"
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

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theXPathSettingsType : public rtl::StaticWithInit< ::css::uno::Type *, theXPathSettingsType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.util.XPathSettings" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::beans::XPropertySet > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        ::rtl::OUString sAttributeName0( "com.sun.star.util.XPathSettings::Addin" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName0.pData );
        ::rtl::OUString sAttributeName1( "com.sun.star.util.XPathSettings::AutoCorrect" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName1.pData );
        ::rtl::OUString sAttributeName2( "com.sun.star.util.XPathSettings::AutoText" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName2.pData );
        ::rtl::OUString sAttributeName3( "com.sun.star.util.XPathSettings::Backup" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName3.pData );
        ::rtl::OUString sAttributeName4( "com.sun.star.util.XPathSettings::Basic" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName4.pData );
        ::rtl::OUString sAttributeName5( "com.sun.star.util.XPathSettings::Bitmap" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName5.pData );
        ::rtl::OUString sAttributeName6( "com.sun.star.util.XPathSettings::Config" );
        typelib_typedescriptionreference_new( &pMembers[6],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName6.pData );
        ::rtl::OUString sAttributeName7( "com.sun.star.util.XPathSettings::Dictionary" );
        typelib_typedescriptionreference_new( &pMembers[7],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName7.pData );
        ::rtl::OUString sAttributeName8( "com.sun.star.util.XPathSettings::Favorite" );
        typelib_typedescriptionreference_new( &pMembers[8],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName8.pData );
        ::rtl::OUString sAttributeName9( "com.sun.star.util.XPathSettings::Filter" );
        typelib_typedescriptionreference_new( &pMembers[9],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName9.pData );
        ::rtl::OUString sAttributeName10( "com.sun.star.util.XPathSettings::Gallery" );
        typelib_typedescriptionreference_new( &pMembers[10],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName10.pData );
        ::rtl::OUString sAttributeName11( "com.sun.star.util.XPathSettings::Graphic" );
        typelib_typedescriptionreference_new( &pMembers[11],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName11.pData );
        ::rtl::OUString sAttributeName12( "com.sun.star.util.XPathSettings::Help" );
        typelib_typedescriptionreference_new( &pMembers[12],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName12.pData );
        ::rtl::OUString sAttributeName13( "com.sun.star.util.XPathSettings::Linguistic" );
        typelib_typedescriptionreference_new( &pMembers[13],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName13.pData );
        ::rtl::OUString sAttributeName14( "com.sun.star.util.XPathSettings::Module" );
        typelib_typedescriptionreference_new( &pMembers[14],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName14.pData );
        ::rtl::OUString sAttributeName15( "com.sun.star.util.XPathSettings::Palette" );
        typelib_typedescriptionreference_new( &pMembers[15],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName15.pData );
        ::rtl::OUString sAttributeName16( "com.sun.star.util.XPathSettings::Plugin" );
        typelib_typedescriptionreference_new( &pMembers[16],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName16.pData );
        ::rtl::OUString sAttributeName17( "com.sun.star.util.XPathSettings::Storage" );
        typelib_typedescriptionreference_new( &pMembers[17],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName17.pData );
        ::rtl::OUString sAttributeName18( "com.sun.star.util.XPathSettings::Temp" );
        typelib_typedescriptionreference_new( &pMembers[18],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName18.pData );
        ::rtl::OUString sAttributeName19( "com.sun.star.util.XPathSettings::Template" );
        typelib_typedescriptionreference_new( &pMembers[19],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName19.pData );
        ::rtl::OUString sAttributeName20( "com.sun.star.util.XPathSettings::UIConfig" );
        typelib_typedescriptionreference_new( &pMembers[20],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName20.pData );
        ::rtl::OUString sAttributeName21( "com.sun.star.util.XPathSettings::UserConfig" );
        typelib_typedescriptionreference_new( &pMembers[21],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName21.pData );
        ::rtl::OUString sAttributeName22( "com.sun.star.util.XPathSettings::UserDictionary" );
        typelib_typedescriptionreference_new( &pMembers[22],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName22.pData );
        ::rtl::OUString sAttributeName23( "com.sun.star.util.XPathSettings::Work" );
        typelib_typedescriptionreference_new( &pMembers[23],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName23.pData );
        ::rtl::OUString sAttributeName24( "com.sun.star.util.XPathSettings::BasePathShareLayer" );
        typelib_typedescriptionreference_new( &pMembers[24],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName24.pData );
        ::rtl::OUString sAttributeName25( "com.sun.star.util.XPathSettings::BasePathUserLayer" );
        typelib_typedescriptionreference_new( &pMembers[25],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_ATTRIBUTE,
                                              sAttributeName25.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            26,
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
        typelib_typedescriptionreference_release( pMembers[12] );
        typelib_typedescriptionreference_release( pMembers[13] );
        typelib_typedescriptionreference_release( pMembers[14] );
        typelib_typedescriptionreference_release( pMembers[15] );
        typelib_typedescriptionreference_release( pMembers[16] );
        typelib_typedescriptionreference_release( pMembers[17] );
        typelib_typedescriptionreference_release( pMembers[18] );
        typelib_typedescriptionreference_release( pMembers[19] );
        typelib_typedescriptionreference_release( pMembers[20] );
        typelib_typedescriptionreference_release( pMembers[21] );
        typelib_typedescriptionreference_release( pMembers[22] );
        typelib_typedescriptionreference_release( pMembers[23] );
        typelib_typedescriptionreference_release( pMembers[24] );
        typelib_typedescriptionreference_release( pMembers[25] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::XPathSettings const *) {
    const ::css::uno::Type &rRet = *detail::theXPathSettingsType::get();
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
                ::rtl::OUString sAttributeName0( "com.sun.star.util.XPathSettings::Addin" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    10, sAttributeName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType0.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType1( "string" );
                ::rtl::OUString sAttributeName1( "com.sun.star.util.XPathSettings::AutoCorrect" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    11, sAttributeName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType1.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType2( "string" );
                ::rtl::OUString sAttributeName2( "com.sun.star.util.XPathSettings::AutoText" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    12, sAttributeName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType2.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType3( "string" );
                ::rtl::OUString sAttributeName3( "com.sun.star.util.XPathSettings::Backup" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    13, sAttributeName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType3.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType4( "string" );
                ::rtl::OUString sAttributeName4( "com.sun.star.util.XPathSettings::Basic" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    14, sAttributeName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType4.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType5( "string" );
                ::rtl::OUString sAttributeName5( "com.sun.star.util.XPathSettings::Bitmap" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    15, sAttributeName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType5.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType6( "string" );
                ::rtl::OUString sAttributeName6( "com.sun.star.util.XPathSettings::Config" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    16, sAttributeName6.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType6.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType7( "string" );
                ::rtl::OUString sAttributeName7( "com.sun.star.util.XPathSettings::Dictionary" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    17, sAttributeName7.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType7.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType8( "string" );
                ::rtl::OUString sAttributeName8( "com.sun.star.util.XPathSettings::Favorite" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    18, sAttributeName8.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType8.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType9( "string" );
                ::rtl::OUString sAttributeName9( "com.sun.star.util.XPathSettings::Filter" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    19, sAttributeName9.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType9.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType10( "string" );
                ::rtl::OUString sAttributeName10( "com.sun.star.util.XPathSettings::Gallery" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    20, sAttributeName10.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType10.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType11( "string" );
                ::rtl::OUString sAttributeName11( "com.sun.star.util.XPathSettings::Graphic" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    21, sAttributeName11.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType11.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType12( "string" );
                ::rtl::OUString sAttributeName12( "com.sun.star.util.XPathSettings::Help" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    22, sAttributeName12.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType12.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType13( "string" );
                ::rtl::OUString sAttributeName13( "com.sun.star.util.XPathSettings::Linguistic" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    23, sAttributeName13.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType13.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType14( "string" );
                ::rtl::OUString sAttributeName14( "com.sun.star.util.XPathSettings::Module" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    24, sAttributeName14.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType14.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType15( "string" );
                ::rtl::OUString sAttributeName15( "com.sun.star.util.XPathSettings::Palette" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    25, sAttributeName15.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType15.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType16( "string" );
                ::rtl::OUString sAttributeName16( "com.sun.star.util.XPathSettings::Plugin" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    26, sAttributeName16.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType16.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType17( "string" );
                ::rtl::OUString sAttributeName17( "com.sun.star.util.XPathSettings::Storage" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    27, sAttributeName17.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType17.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType18( "string" );
                ::rtl::OUString sAttributeName18( "com.sun.star.util.XPathSettings::Temp" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    28, sAttributeName18.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType18.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType19( "string" );
                ::rtl::OUString sAttributeName19( "com.sun.star.util.XPathSettings::Template" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    29, sAttributeName19.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType19.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType20( "string" );
                ::rtl::OUString sAttributeName20( "com.sun.star.util.XPathSettings::UIConfig" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    30, sAttributeName20.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType20.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType21( "string" );
                ::rtl::OUString sAttributeName21( "com.sun.star.util.XPathSettings::UserConfig" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    31, sAttributeName21.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType21.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType22( "string" );
                ::rtl::OUString sAttributeName22( "com.sun.star.util.XPathSettings::UserDictionary" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    32, sAttributeName22.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType22.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType23( "string" );
                ::rtl::OUString sAttributeName23( "com.sun.star.util.XPathSettings::Work" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    33, sAttributeName23.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType23.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType24( "string" );
                ::rtl::OUString sAttributeName24( "com.sun.star.util.XPathSettings::BasePathShareLayer" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    34, sAttributeName24.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType24.pData,
                    sal_False, 0, 0, 0, 0 );
                typelib_typedescription_register( (typelib_TypeDescription**)&pAttribute );
            }
            {
                ::rtl::OUString sAttributeType25( "string" );
                ::rtl::OUString sAttributeName25( "com.sun.star.util.XPathSettings::BasePathUserLayer" );
                typelib_typedescription_newExtendedInterfaceAttribute( &pAttribute,
                    35, sAttributeName25.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sAttributeType25.pData,
                    sal_False, 0, 0, 0, 0 );
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::util::XPathSettings > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::util::XPathSettings > >::get();
}

::css::uno::Type const & ::css::util::XPathSettings::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::util::XPathSettings >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::util::XPathSettings>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_UTIL_XPATHSETTINGS_HPP
