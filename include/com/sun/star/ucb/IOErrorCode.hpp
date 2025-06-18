#ifndef INCLUDED_COM_SUN_STAR_UCB_IOERRORCODE_HPP
#define INCLUDED_COM_SUN_STAR_UCB_IOERRORCODE_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/IOErrorCode.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theIOErrorCodeType : public rtl::StaticWithInit< ::css::uno::Type *, theIOErrorCodeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.ucb.IOErrorCode" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;

        rtl_uString* enumValueNames[36];
        ::rtl::OUString sEnumValue0( "ABORT" );
        enumValueNames[0] = sEnumValue0.pData;
        ::rtl::OUString sEnumValue1( "ACCESS_DENIED" );
        enumValueNames[1] = sEnumValue1.pData;
        ::rtl::OUString sEnumValue2( "ALREADY_EXISTING" );
        enumValueNames[2] = sEnumValue2.pData;
        ::rtl::OUString sEnumValue3( "BAD_CRC" );
        enumValueNames[3] = sEnumValue3.pData;
        ::rtl::OUString sEnumValue4( "CANT_CREATE" );
        enumValueNames[4] = sEnumValue4.pData;
        ::rtl::OUString sEnumValue5( "CANT_READ" );
        enumValueNames[5] = sEnumValue5.pData;
        ::rtl::OUString sEnumValue6( "CANT_SEEK" );
        enumValueNames[6] = sEnumValue6.pData;
        ::rtl::OUString sEnumValue7( "CANT_TELL" );
        enumValueNames[7] = sEnumValue7.pData;
        ::rtl::OUString sEnumValue8( "CANT_WRITE" );
        enumValueNames[8] = sEnumValue8.pData;
        ::rtl::OUString sEnumValue9( "CURRENT_DIRECTORY" );
        enumValueNames[9] = sEnumValue9.pData;
        ::rtl::OUString sEnumValue10( "DEVICE_NOT_READY" );
        enumValueNames[10] = sEnumValue10.pData;
        ::rtl::OUString sEnumValue11( "DIFFERENT_DEVICES" );
        enumValueNames[11] = sEnumValue11.pData;
        ::rtl::OUString sEnumValue12( "GENERAL" );
        enumValueNames[12] = sEnumValue12.pData;
        ::rtl::OUString sEnumValue13( "INVALID_ACCESS" );
        enumValueNames[13] = sEnumValue13.pData;
        ::rtl::OUString sEnumValue14( "INVALID_CHARACTER" );
        enumValueNames[14] = sEnumValue14.pData;
        ::rtl::OUString sEnumValue15( "INVALID_DEVICE" );
        enumValueNames[15] = sEnumValue15.pData;
        ::rtl::OUString sEnumValue16( "INVALID_LENGTH" );
        enumValueNames[16] = sEnumValue16.pData;
        ::rtl::OUString sEnumValue17( "INVALID_PARAMETER" );
        enumValueNames[17] = sEnumValue17.pData;
        ::rtl::OUString sEnumValue18( "IS_WILDCARD" );
        enumValueNames[18] = sEnumValue18.pData;
        ::rtl::OUString sEnumValue19( "LOCKING_VIOLATION" );
        enumValueNames[19] = sEnumValue19.pData;
        ::rtl::OUString sEnumValue20( "MISPLACED_CHARACTER" );
        enumValueNames[20] = sEnumValue20.pData;
        ::rtl::OUString sEnumValue21( "NAME_TOO_LONG" );
        enumValueNames[21] = sEnumValue21.pData;
        ::rtl::OUString sEnumValue22( "NOT_EXISTING" );
        enumValueNames[22] = sEnumValue22.pData;
        ::rtl::OUString sEnumValue23( "NOT_EXISTING_PATH" );
        enumValueNames[23] = sEnumValue23.pData;
        ::rtl::OUString sEnumValue24( "NOT_SUPPORTED" );
        enumValueNames[24] = sEnumValue24.pData;
        ::rtl::OUString sEnumValue25( "NO_DIRECTORY" );
        enumValueNames[25] = sEnumValue25.pData;
        ::rtl::OUString sEnumValue26( "NO_FILE" );
        enumValueNames[26] = sEnumValue26.pData;
        ::rtl::OUString sEnumValue27( "OUT_OF_DISK_SPACE" );
        enumValueNames[27] = sEnumValue27.pData;
        ::rtl::OUString sEnumValue28( "OUT_OF_FILE_HANDLES" );
        enumValueNames[28] = sEnumValue28.pData;
        ::rtl::OUString sEnumValue29( "OUT_OF_MEMORY" );
        enumValueNames[29] = sEnumValue29.pData;
        ::rtl::OUString sEnumValue30( "PENDING" );
        enumValueNames[30] = sEnumValue30.pData;
        ::rtl::OUString sEnumValue31( "RECURSIVE" );
        enumValueNames[31] = sEnumValue31.pData;
        ::rtl::OUString sEnumValue32( "UNKNOWN" );
        enumValueNames[32] = sEnumValue32.pData;
        ::rtl::OUString sEnumValue33( "WRITE_PROTECTED" );
        enumValueNames[33] = sEnumValue33.pData;
        ::rtl::OUString sEnumValue34( "WRONG_FORMAT" );
        enumValueNames[34] = sEnumValue34.pData;
        ::rtl::OUString sEnumValue35( "WRONG_VERSION" );
        enumValueNames[35] = sEnumValue35.pData;

        sal_Int32 enumValues[36];
        enumValues[0] = 0;
        enumValues[1] = 1;
        enumValues[2] = 2;
        enumValues[3] = 3;
        enumValues[4] = 4;
        enumValues[5] = 5;
        enumValues[6] = 6;
        enumValues[7] = 7;
        enumValues[8] = 8;
        enumValues[9] = 9;
        enumValues[10] = 10;
        enumValues[11] = 11;
        enumValues[12] = 12;
        enumValues[13] = 13;
        enumValues[14] = 14;
        enumValues[15] = 15;
        enumValues[16] = 16;
        enumValues[17] = 17;
        enumValues[18] = 18;
        enumValues[19] = 19;
        enumValues[20] = 20;
        enumValues[21] = 21;
        enumValues[22] = 22;
        enumValues[23] = 23;
        enumValues[24] = 24;
        enumValues[25] = 25;
        enumValues[26] = 26;
        enumValues[27] = 27;
        enumValues[28] = 28;
        enumValues[29] = 29;
        enumValues[30] = 30;
        enumValues[31] = 31;
        enumValues[32] = 32;
        enumValues[33] = 33;
        enumValues[34] = 34;
        enumValues[35] = 35;

        typelib_typedescription_newEnum( &pTD,
            sTypeName.pData,
            (sal_Int32)::com::sun::star::ucb::IOErrorCode_ABORT,
            36, enumValueNames, enumValues );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );
        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_ENUM, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::IOErrorCode const *) {
    return *detail::theIOErrorCodeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::IOErrorCode const *) {
    return ::cppu::UnoType< ::css::ucb::IOErrorCode >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_IOERRORCODE_HPP
