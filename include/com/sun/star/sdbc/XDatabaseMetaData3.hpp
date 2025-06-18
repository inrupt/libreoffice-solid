#ifndef INCLUDED_COM_SUN_STAR_SDBC_XDATABASEMETADATA3_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XDATABASEMETADATA3_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XDatabaseMetaData3.hdl"

#include "com/sun/star/beans/Optional.hpp"
#include "com/sun/star/sdbc/SQLException.hpp"
#include "com/sun/star/sdbc/XDatabaseMetaData2.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
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

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theXDatabaseMetaData3Type : public rtl::StaticWithInit< ::css::uno::Type *, theXDatabaseMetaData3Type >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.sdbc.XDatabaseMetaData3" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XDatabaseMetaData2 > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.sdbc.XDatabaseMetaData3::autoCommitFailureClosesAllResultSets" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.sdbc.XDatabaseMetaData3::generatedKeyAlwaysReturned" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.sdbc.XDatabaseMetaData3::getAttributes" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.sdbc.XDatabaseMetaData3::getClientInfoProperties" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );
        ::rtl::OUString sMethodName4( "com.sun.star.sdbc.XDatabaseMetaData3::getDatabaseMajorVersion" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName4.pData );
        ::rtl::OUString sMethodName5( "com.sun.star.sdbc.XDatabaseMetaData3::getDatabaseMinorVersion" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName5.pData );
        ::rtl::OUString sMethodName6( "com.sun.star.sdbc.XDatabaseMetaData3::getFunctions" );
        typelib_typedescriptionreference_new( &pMembers[6],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName6.pData );
        ::rtl::OUString sMethodName7( "com.sun.star.sdbc.XDatabaseMetaData3::getFunctionColumns" );
        typelib_typedescriptionreference_new( &pMembers[7],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName7.pData );
        ::rtl::OUString sMethodName8( "com.sun.star.sdbc.XDatabaseMetaData3::getMaxLogicalLobSize" );
        typelib_typedescriptionreference_new( &pMembers[8],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName8.pData );
        ::rtl::OUString sMethodName9( "com.sun.star.sdbc.XDatabaseMetaData3::getPseudoColumns" );
        typelib_typedescriptionreference_new( &pMembers[9],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName9.pData );
        ::rtl::OUString sMethodName10( "com.sun.star.sdbc.XDatabaseMetaData3::getResultSetHoldability" );
        typelib_typedescriptionreference_new( &pMembers[10],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName10.pData );
        ::rtl::OUString sMethodName11( "com.sun.star.sdbc.XDatabaseMetaData3::getRowIdLifetime" );
        typelib_typedescriptionreference_new( &pMembers[11],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName11.pData );
        ::rtl::OUString sMethodName12( "com.sun.star.sdbc.XDatabaseMetaData3::getSchemasFiltered" );
        typelib_typedescriptionreference_new( &pMembers[12],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName12.pData );
        ::rtl::OUString sMethodName13( "com.sun.star.sdbc.XDatabaseMetaData3::getSQLStateType" );
        typelib_typedescriptionreference_new( &pMembers[13],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName13.pData );
        ::rtl::OUString sMethodName14( "com.sun.star.sdbc.XDatabaseMetaData3::getSuperTables" );
        typelib_typedescriptionreference_new( &pMembers[14],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName14.pData );
        ::rtl::OUString sMethodName15( "com.sun.star.sdbc.XDatabaseMetaData3::getSuperTypes" );
        typelib_typedescriptionreference_new( &pMembers[15],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName15.pData );
        ::rtl::OUString sMethodName16( "com.sun.star.sdbc.XDatabaseMetaData3::locatorsUpdateCopy" );
        typelib_typedescriptionreference_new( &pMembers[16],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName16.pData );
        ::rtl::OUString sMethodName17( "com.sun.star.sdbc.XDatabaseMetaData3::supportsConvertInGeneral" );
        typelib_typedescriptionreference_new( &pMembers[17],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName17.pData );
        ::rtl::OUString sMethodName18( "com.sun.star.sdbc.XDatabaseMetaData3::supportsGetGeneratedKeys" );
        typelib_typedescriptionreference_new( &pMembers[18],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName18.pData );
        ::rtl::OUString sMethodName19( "com.sun.star.sdbc.XDatabaseMetaData3::supportsMultipleOpenResults" );
        typelib_typedescriptionreference_new( &pMembers[19],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName19.pData );
        ::rtl::OUString sMethodName20( "com.sun.star.sdbc.XDatabaseMetaData3::supportsNamedParameters" );
        typelib_typedescriptionreference_new( &pMembers[20],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName20.pData );
        ::rtl::OUString sMethodName21( "com.sun.star.sdbc.XDatabaseMetaData3::supportsRefCursors" );
        typelib_typedescriptionreference_new( &pMembers[21],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName21.pData );
        ::rtl::OUString sMethodName22( "com.sun.star.sdbc.XDatabaseMetaData3::supportsSavepoints" );
        typelib_typedescriptionreference_new( &pMembers[22],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName22.pData );
        ::rtl::OUString sMethodName23( "com.sun.star.sdbc.XDatabaseMetaData3::supportsSharding" );
        typelib_typedescriptionreference_new( &pMembers[23],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName23.pData );
        ::rtl::OUString sMethodName24( "com.sun.star.sdbc.XDatabaseMetaData3::supportsStatementPooling" );
        typelib_typedescriptionreference_new( &pMembers[24],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName24.pData );
        ::rtl::OUString sMethodName25( "com.sun.star.sdbc.XDatabaseMetaData3::supportsStoredFunctionsUsingCallSyntax" );
        typelib_typedescriptionreference_new( &pMembers[25],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName25.pData );

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

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XDatabaseMetaData3 const *) {
    const ::css::uno::Type &rRet = *detail::theXDatabaseMetaData3Type::get();
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
            ::cppu::UnoType< ::css::sdbc::SQLException >::get();

            typelib_InterfaceMethodTypeDescription * pMethod = 0;
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType0( "boolean" );
                ::rtl::OUString sMethodName0( "com.sun.star.sdbc.XDatabaseMetaData3::autoCommitFailureClosesAllResultSets" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    153, sal_False,
                    sMethodName0.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType0.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType1( "boolean" );
                ::rtl::OUString sMethodName1( "com.sun.star.sdbc.XDatabaseMetaData3::generatedKeyAlwaysReturned" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    154, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType1.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "typeNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "attributeNamePattern" );
                ::rtl::OUString sParamType3( "string" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType2( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName2( "com.sun.star.sdbc.XDatabaseMetaData3::getAttributes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    155, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType2.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType3( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName3( "com.sun.star.sdbc.XDatabaseMetaData3::getClientInfoProperties" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    156, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType3.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType4( "long" );
                ::rtl::OUString sMethodName4( "com.sun.star.sdbc.XDatabaseMetaData3::getDatabaseMajorVersion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    157, sal_False,
                    sMethodName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType4.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType5( "long" );
                ::rtl::OUString sMethodName5( "com.sun.star.sdbc.XDatabaseMetaData3::getDatabaseMinorVersion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    158, sal_False,
                    sMethodName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType5.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "functionNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType6( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName6( "com.sun.star.sdbc.XDatabaseMetaData3::getFunctions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    159, sal_False,
                    sMethodName6.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType6.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "functionNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "columnNamePattern" );
                ::rtl::OUString sParamType3( "string" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType7( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName7( "com.sun.star.sdbc.XDatabaseMetaData3::getFunctionColumns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    160, sal_False,
                    sMethodName7.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType7.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType8( "long" );
                ::rtl::OUString sMethodName8( "com.sun.star.sdbc.XDatabaseMetaData3::getMaxLogicalLobSize" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    161, sal_False,
                    sMethodName8.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType8.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "tableNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "columnNamePattern" );
                ::rtl::OUString sParamType3( "string" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType9( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName9( "com.sun.star.sdbc.XDatabaseMetaData3::getPseudoColumns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    162, sal_False,
                    sMethodName9.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType9.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType10( "long" );
                ::rtl::OUString sMethodName10( "com.sun.star.sdbc.XDatabaseMetaData3::getResultSetHoldability" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    163, sal_False,
                    sMethodName10.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType10.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType11( "long" );
                ::rtl::OUString sMethodName11( "com.sun.star.sdbc.XDatabaseMetaData3::getRowIdLifetime" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    164, sal_False,
                    sMethodName11.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType11.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "com.sun.star.beans.Optional<string>" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRUCT;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "com.sun.star.beans.Optional<string>" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRUCT;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType12( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName12( "com.sun.star.sdbc.XDatabaseMetaData3::getSchemasFiltered" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    165, sal_False,
                    sMethodName12.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType12.pData,
                    2, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType13( "long" );
                ::rtl::OUString sMethodName13( "com.sun.star.sdbc.XDatabaseMetaData3::getSQLStateType" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    166, sal_False,
                    sMethodName13.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType13.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "tableNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType14( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName14( "com.sun.star.sdbc.XDatabaseMetaData3::getSuperTables" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    167, sal_False,
                    sMethodName14.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType14.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "string" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schemaPattern" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "typeNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType15( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName15( "com.sun.star.sdbc.XDatabaseMetaData3::getSuperTypes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    168, sal_False,
                    sMethodName15.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType15.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType16( "boolean" );
                ::rtl::OUString sMethodName16( "com.sun.star.sdbc.XDatabaseMetaData3::locatorsUpdateCopy" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    169, sal_False,
                    sMethodName16.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType16.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType17( "boolean" );
                ::rtl::OUString sMethodName17( "com.sun.star.sdbc.XDatabaseMetaData3::supportsConvertInGeneral" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    170, sal_False,
                    sMethodName17.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType17.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType18( "boolean" );
                ::rtl::OUString sMethodName18( "com.sun.star.sdbc.XDatabaseMetaData3::supportsGetGeneratedKeys" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    171, sal_False,
                    sMethodName18.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType18.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType19( "boolean" );
                ::rtl::OUString sMethodName19( "com.sun.star.sdbc.XDatabaseMetaData3::supportsMultipleOpenResults" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    172, sal_False,
                    sMethodName19.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType19.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType20( "boolean" );
                ::rtl::OUString sMethodName20( "com.sun.star.sdbc.XDatabaseMetaData3::supportsNamedParameters" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    173, sal_False,
                    sMethodName20.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType20.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType21( "boolean" );
                ::rtl::OUString sMethodName21( "com.sun.star.sdbc.XDatabaseMetaData3::supportsRefCursors" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    174, sal_False,
                    sMethodName21.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType21.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType22( "boolean" );
                ::rtl::OUString sMethodName22( "com.sun.star.sdbc.XDatabaseMetaData3::supportsSavepoints" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    175, sal_False,
                    sMethodName22.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType22.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType23( "boolean" );
                ::rtl::OUString sMethodName23( "com.sun.star.sdbc.XDatabaseMetaData3::supportsSharding" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    176, sal_False,
                    sMethodName23.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType23.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType24( "boolean" );
                ::rtl::OUString sMethodName24( "com.sun.star.sdbc.XDatabaseMetaData3::supportsStatementPooling" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    177, sal_False,
                    sMethodName24.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType24.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType25( "boolean" );
                ::rtl::OUString sMethodName25( "com.sun.star.sdbc.XDatabaseMetaData3::supportsStoredFunctionsUsingCallSyntax" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    178, sal_False,
                    sMethodName25.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType25.pData,
                    0, 0,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XDatabaseMetaData3 > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XDatabaseMetaData3 > >::get();
}

::css::uno::Type const & ::css::sdbc::XDatabaseMetaData3::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XDatabaseMetaData3 >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::sdbc::XDatabaseMetaData3>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_SDBC_XDATABASEMETADATA3_HPP
