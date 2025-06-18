#ifndef INCLUDED_COM_SUN_STAR_SDBC_XDATABASEMETADATA_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_XDATABASEMETADATA_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/XDatabaseMetaData.hdl"

#include "com/sun/star/sdbc/SQLException.hpp"
#include "com/sun/star/sdbc/XConnection.hpp"
#include "com/sun/star/sdbc/XResultSet.hpp"
#include "com/sun/star/uno/RuntimeException.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Any.hxx"
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

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theXDatabaseMetaDataType : public rtl::StaticWithInit< ::css::uno::Type *, theXDatabaseMetaDataType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.sdbc.XDatabaseMetaData" );

        // Start inline typedescription generation
        typelib_InterfaceTypeDescription * pTD = 0;

        typelib_TypeDescriptionReference * aSuperTypes[1];
        aSuperTypes[0] = ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get().getTypeLibType();
        typelib_TypeDescriptionReference * pMembers[149] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
        ::rtl::OUString sMethodName0( "com.sun.star.sdbc.XDatabaseMetaData::allProceduresAreCallable" );
        typelib_typedescriptionreference_new( &pMembers[0],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName0.pData );
        ::rtl::OUString sMethodName1( "com.sun.star.sdbc.XDatabaseMetaData::allTablesAreSelectable" );
        typelib_typedescriptionreference_new( &pMembers[1],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName1.pData );
        ::rtl::OUString sMethodName2( "com.sun.star.sdbc.XDatabaseMetaData::getURL" );
        typelib_typedescriptionreference_new( &pMembers[2],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName2.pData );
        ::rtl::OUString sMethodName3( "com.sun.star.sdbc.XDatabaseMetaData::getUserName" );
        typelib_typedescriptionreference_new( &pMembers[3],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName3.pData );
        ::rtl::OUString sMethodName4( "com.sun.star.sdbc.XDatabaseMetaData::isReadOnly" );
        typelib_typedescriptionreference_new( &pMembers[4],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName4.pData );
        ::rtl::OUString sMethodName5( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedHigh" );
        typelib_typedescriptionreference_new( &pMembers[5],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName5.pData );
        ::rtl::OUString sMethodName6( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedLow" );
        typelib_typedescriptionreference_new( &pMembers[6],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName6.pData );
        ::rtl::OUString sMethodName7( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedAtStart" );
        typelib_typedescriptionreference_new( &pMembers[7],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName7.pData );
        ::rtl::OUString sMethodName8( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedAtEnd" );
        typelib_typedescriptionreference_new( &pMembers[8],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName8.pData );
        ::rtl::OUString sMethodName9( "com.sun.star.sdbc.XDatabaseMetaData::getDatabaseProductName" );
        typelib_typedescriptionreference_new( &pMembers[9],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName9.pData );
        ::rtl::OUString sMethodName10( "com.sun.star.sdbc.XDatabaseMetaData::getDatabaseProductVersion" );
        typelib_typedescriptionreference_new( &pMembers[10],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName10.pData );
        ::rtl::OUString sMethodName11( "com.sun.star.sdbc.XDatabaseMetaData::getDriverName" );
        typelib_typedescriptionreference_new( &pMembers[11],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName11.pData );
        ::rtl::OUString sMethodName12( "com.sun.star.sdbc.XDatabaseMetaData::getDriverVersion" );
        typelib_typedescriptionreference_new( &pMembers[12],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName12.pData );
        ::rtl::OUString sMethodName13( "com.sun.star.sdbc.XDatabaseMetaData::getDriverMajorVersion" );
        typelib_typedescriptionreference_new( &pMembers[13],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName13.pData );
        ::rtl::OUString sMethodName14( "com.sun.star.sdbc.XDatabaseMetaData::getDriverMinorVersion" );
        typelib_typedescriptionreference_new( &pMembers[14],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName14.pData );
        ::rtl::OUString sMethodName15( "com.sun.star.sdbc.XDatabaseMetaData::usesLocalFiles" );
        typelib_typedescriptionreference_new( &pMembers[15],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName15.pData );
        ::rtl::OUString sMethodName16( "com.sun.star.sdbc.XDatabaseMetaData::usesLocalFilePerTable" );
        typelib_typedescriptionreference_new( &pMembers[16],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName16.pData );
        ::rtl::OUString sMethodName17( "com.sun.star.sdbc.XDatabaseMetaData::supportsMixedCaseIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[17],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName17.pData );
        ::rtl::OUString sMethodName18( "com.sun.star.sdbc.XDatabaseMetaData::storesUpperCaseIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[18],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName18.pData );
        ::rtl::OUString sMethodName19( "com.sun.star.sdbc.XDatabaseMetaData::storesLowerCaseIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[19],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName19.pData );
        ::rtl::OUString sMethodName20( "com.sun.star.sdbc.XDatabaseMetaData::storesMixedCaseIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[20],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName20.pData );
        ::rtl::OUString sMethodName21( "com.sun.star.sdbc.XDatabaseMetaData::supportsMixedCaseQuotedIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[21],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName21.pData );
        ::rtl::OUString sMethodName22( "com.sun.star.sdbc.XDatabaseMetaData::storesUpperCaseQuotedIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[22],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName22.pData );
        ::rtl::OUString sMethodName23( "com.sun.star.sdbc.XDatabaseMetaData::storesLowerCaseQuotedIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[23],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName23.pData );
        ::rtl::OUString sMethodName24( "com.sun.star.sdbc.XDatabaseMetaData::storesMixedCaseQuotedIdentifiers" );
        typelib_typedescriptionreference_new( &pMembers[24],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName24.pData );
        ::rtl::OUString sMethodName25( "com.sun.star.sdbc.XDatabaseMetaData::getIdentifierQuoteString" );
        typelib_typedescriptionreference_new( &pMembers[25],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName25.pData );
        ::rtl::OUString sMethodName26( "com.sun.star.sdbc.XDatabaseMetaData::getSQLKeywords" );
        typelib_typedescriptionreference_new( &pMembers[26],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName26.pData );
        ::rtl::OUString sMethodName27( "com.sun.star.sdbc.XDatabaseMetaData::getNumericFunctions" );
        typelib_typedescriptionreference_new( &pMembers[27],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName27.pData );
        ::rtl::OUString sMethodName28( "com.sun.star.sdbc.XDatabaseMetaData::getStringFunctions" );
        typelib_typedescriptionreference_new( &pMembers[28],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName28.pData );
        ::rtl::OUString sMethodName29( "com.sun.star.sdbc.XDatabaseMetaData::getSystemFunctions" );
        typelib_typedescriptionreference_new( &pMembers[29],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName29.pData );
        ::rtl::OUString sMethodName30( "com.sun.star.sdbc.XDatabaseMetaData::getTimeDateFunctions" );
        typelib_typedescriptionreference_new( &pMembers[30],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName30.pData );
        ::rtl::OUString sMethodName31( "com.sun.star.sdbc.XDatabaseMetaData::getSearchStringEscape" );
        typelib_typedescriptionreference_new( &pMembers[31],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName31.pData );
        ::rtl::OUString sMethodName32( "com.sun.star.sdbc.XDatabaseMetaData::getExtraNameCharacters" );
        typelib_typedescriptionreference_new( &pMembers[32],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName32.pData );
        ::rtl::OUString sMethodName33( "com.sun.star.sdbc.XDatabaseMetaData::supportsAlterTableWithAddColumn" );
        typelib_typedescriptionreference_new( &pMembers[33],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName33.pData );
        ::rtl::OUString sMethodName34( "com.sun.star.sdbc.XDatabaseMetaData::supportsAlterTableWithDropColumn" );
        typelib_typedescriptionreference_new( &pMembers[34],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName34.pData );
        ::rtl::OUString sMethodName35( "com.sun.star.sdbc.XDatabaseMetaData::supportsColumnAliasing" );
        typelib_typedescriptionreference_new( &pMembers[35],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName35.pData );
        ::rtl::OUString sMethodName36( "com.sun.star.sdbc.XDatabaseMetaData::nullPlusNonNullIsNull" );
        typelib_typedescriptionreference_new( &pMembers[36],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName36.pData );
        ::rtl::OUString sMethodName37( "com.sun.star.sdbc.XDatabaseMetaData::supportsTypeConversion" );
        typelib_typedescriptionreference_new( &pMembers[37],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName37.pData );
        ::rtl::OUString sMethodName38( "com.sun.star.sdbc.XDatabaseMetaData::supportsConvert" );
        typelib_typedescriptionreference_new( &pMembers[38],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName38.pData );
        ::rtl::OUString sMethodName39( "com.sun.star.sdbc.XDatabaseMetaData::supportsTableCorrelationNames" );
        typelib_typedescriptionreference_new( &pMembers[39],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName39.pData );
        ::rtl::OUString sMethodName40( "com.sun.star.sdbc.XDatabaseMetaData::supportsDifferentTableCorrelationNames" );
        typelib_typedescriptionreference_new( &pMembers[40],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName40.pData );
        ::rtl::OUString sMethodName41( "com.sun.star.sdbc.XDatabaseMetaData::supportsExpressionsInOrderBy" );
        typelib_typedescriptionreference_new( &pMembers[41],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName41.pData );
        ::rtl::OUString sMethodName42( "com.sun.star.sdbc.XDatabaseMetaData::supportsOrderByUnrelated" );
        typelib_typedescriptionreference_new( &pMembers[42],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName42.pData );
        ::rtl::OUString sMethodName43( "com.sun.star.sdbc.XDatabaseMetaData::supportsGroupBy" );
        typelib_typedescriptionreference_new( &pMembers[43],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName43.pData );
        ::rtl::OUString sMethodName44( "com.sun.star.sdbc.XDatabaseMetaData::supportsGroupByUnrelated" );
        typelib_typedescriptionreference_new( &pMembers[44],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName44.pData );
        ::rtl::OUString sMethodName45( "com.sun.star.sdbc.XDatabaseMetaData::supportsGroupByBeyondSelect" );
        typelib_typedescriptionreference_new( &pMembers[45],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName45.pData );
        ::rtl::OUString sMethodName46( "com.sun.star.sdbc.XDatabaseMetaData::supportsLikeEscapeClause" );
        typelib_typedescriptionreference_new( &pMembers[46],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName46.pData );
        ::rtl::OUString sMethodName47( "com.sun.star.sdbc.XDatabaseMetaData::supportsMultipleResultSets" );
        typelib_typedescriptionreference_new( &pMembers[47],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName47.pData );
        ::rtl::OUString sMethodName48( "com.sun.star.sdbc.XDatabaseMetaData::supportsMultipleTransactions" );
        typelib_typedescriptionreference_new( &pMembers[48],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName48.pData );
        ::rtl::OUString sMethodName49( "com.sun.star.sdbc.XDatabaseMetaData::supportsNonNullableColumns" );
        typelib_typedescriptionreference_new( &pMembers[49],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName49.pData );
        ::rtl::OUString sMethodName50( "com.sun.star.sdbc.XDatabaseMetaData::supportsMinimumSQLGrammar" );
        typelib_typedescriptionreference_new( &pMembers[50],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName50.pData );
        ::rtl::OUString sMethodName51( "com.sun.star.sdbc.XDatabaseMetaData::supportsCoreSQLGrammar" );
        typelib_typedescriptionreference_new( &pMembers[51],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName51.pData );
        ::rtl::OUString sMethodName52( "com.sun.star.sdbc.XDatabaseMetaData::supportsExtendedSQLGrammar" );
        typelib_typedescriptionreference_new( &pMembers[52],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName52.pData );
        ::rtl::OUString sMethodName53( "com.sun.star.sdbc.XDatabaseMetaData::supportsANSI92EntryLevelSQL" );
        typelib_typedescriptionreference_new( &pMembers[53],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName53.pData );
        ::rtl::OUString sMethodName54( "com.sun.star.sdbc.XDatabaseMetaData::supportsANSI92IntermediateSQL" );
        typelib_typedescriptionreference_new( &pMembers[54],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName54.pData );
        ::rtl::OUString sMethodName55( "com.sun.star.sdbc.XDatabaseMetaData::supportsANSI92FullSQL" );
        typelib_typedescriptionreference_new( &pMembers[55],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName55.pData );
        ::rtl::OUString sMethodName56( "com.sun.star.sdbc.XDatabaseMetaData::supportsIntegrityEnhancementFacility" );
        typelib_typedescriptionreference_new( &pMembers[56],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName56.pData );
        ::rtl::OUString sMethodName57( "com.sun.star.sdbc.XDatabaseMetaData::supportsOuterJoins" );
        typelib_typedescriptionreference_new( &pMembers[57],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName57.pData );
        ::rtl::OUString sMethodName58( "com.sun.star.sdbc.XDatabaseMetaData::supportsFullOuterJoins" );
        typelib_typedescriptionreference_new( &pMembers[58],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName58.pData );
        ::rtl::OUString sMethodName59( "com.sun.star.sdbc.XDatabaseMetaData::supportsLimitedOuterJoins" );
        typelib_typedescriptionreference_new( &pMembers[59],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName59.pData );
        ::rtl::OUString sMethodName60( "com.sun.star.sdbc.XDatabaseMetaData::getSchemaTerm" );
        typelib_typedescriptionreference_new( &pMembers[60],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName60.pData );
        ::rtl::OUString sMethodName61( "com.sun.star.sdbc.XDatabaseMetaData::getProcedureTerm" );
        typelib_typedescriptionreference_new( &pMembers[61],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName61.pData );
        ::rtl::OUString sMethodName62( "com.sun.star.sdbc.XDatabaseMetaData::getCatalogTerm" );
        typelib_typedescriptionreference_new( &pMembers[62],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName62.pData );
        ::rtl::OUString sMethodName63( "com.sun.star.sdbc.XDatabaseMetaData::isCatalogAtStart" );
        typelib_typedescriptionreference_new( &pMembers[63],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName63.pData );
        ::rtl::OUString sMethodName64( "com.sun.star.sdbc.XDatabaseMetaData::getCatalogSeparator" );
        typelib_typedescriptionreference_new( &pMembers[64],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName64.pData );
        ::rtl::OUString sMethodName65( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInDataManipulation" );
        typelib_typedescriptionreference_new( &pMembers[65],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName65.pData );
        ::rtl::OUString sMethodName66( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInProcedureCalls" );
        typelib_typedescriptionreference_new( &pMembers[66],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName66.pData );
        ::rtl::OUString sMethodName67( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInTableDefinitions" );
        typelib_typedescriptionreference_new( &pMembers[67],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName67.pData );
        ::rtl::OUString sMethodName68( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInIndexDefinitions" );
        typelib_typedescriptionreference_new( &pMembers[68],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName68.pData );
        ::rtl::OUString sMethodName69( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInPrivilegeDefinitions" );
        typelib_typedescriptionreference_new( &pMembers[69],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName69.pData );
        ::rtl::OUString sMethodName70( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInDataManipulation" );
        typelib_typedescriptionreference_new( &pMembers[70],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName70.pData );
        ::rtl::OUString sMethodName71( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInProcedureCalls" );
        typelib_typedescriptionreference_new( &pMembers[71],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName71.pData );
        ::rtl::OUString sMethodName72( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInTableDefinitions" );
        typelib_typedescriptionreference_new( &pMembers[72],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName72.pData );
        ::rtl::OUString sMethodName73( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInIndexDefinitions" );
        typelib_typedescriptionreference_new( &pMembers[73],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName73.pData );
        ::rtl::OUString sMethodName74( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInPrivilegeDefinitions" );
        typelib_typedescriptionreference_new( &pMembers[74],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName74.pData );
        ::rtl::OUString sMethodName75( "com.sun.star.sdbc.XDatabaseMetaData::supportsPositionedDelete" );
        typelib_typedescriptionreference_new( &pMembers[75],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName75.pData );
        ::rtl::OUString sMethodName76( "com.sun.star.sdbc.XDatabaseMetaData::supportsPositionedUpdate" );
        typelib_typedescriptionreference_new( &pMembers[76],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName76.pData );
        ::rtl::OUString sMethodName77( "com.sun.star.sdbc.XDatabaseMetaData::supportsSelectForUpdate" );
        typelib_typedescriptionreference_new( &pMembers[77],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName77.pData );
        ::rtl::OUString sMethodName78( "com.sun.star.sdbc.XDatabaseMetaData::supportsStoredProcedures" );
        typelib_typedescriptionreference_new( &pMembers[78],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName78.pData );
        ::rtl::OUString sMethodName79( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInComparisons" );
        typelib_typedescriptionreference_new( &pMembers[79],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName79.pData );
        ::rtl::OUString sMethodName80( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInExists" );
        typelib_typedescriptionreference_new( &pMembers[80],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName80.pData );
        ::rtl::OUString sMethodName81( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInIns" );
        typelib_typedescriptionreference_new( &pMembers[81],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName81.pData );
        ::rtl::OUString sMethodName82( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInQuantifieds" );
        typelib_typedescriptionreference_new( &pMembers[82],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName82.pData );
        ::rtl::OUString sMethodName83( "com.sun.star.sdbc.XDatabaseMetaData::supportsCorrelatedSubqueries" );
        typelib_typedescriptionreference_new( &pMembers[83],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName83.pData );
        ::rtl::OUString sMethodName84( "com.sun.star.sdbc.XDatabaseMetaData::supportsUnion" );
        typelib_typedescriptionreference_new( &pMembers[84],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName84.pData );
        ::rtl::OUString sMethodName85( "com.sun.star.sdbc.XDatabaseMetaData::supportsUnionAll" );
        typelib_typedescriptionreference_new( &pMembers[85],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName85.pData );
        ::rtl::OUString sMethodName86( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenCursorsAcrossCommit" );
        typelib_typedescriptionreference_new( &pMembers[86],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName86.pData );
        ::rtl::OUString sMethodName87( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenCursorsAcrossRollback" );
        typelib_typedescriptionreference_new( &pMembers[87],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName87.pData );
        ::rtl::OUString sMethodName88( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenStatementsAcrossCommit" );
        typelib_typedescriptionreference_new( &pMembers[88],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName88.pData );
        ::rtl::OUString sMethodName89( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenStatementsAcrossRollback" );
        typelib_typedescriptionreference_new( &pMembers[89],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName89.pData );
        ::rtl::OUString sMethodName90( "com.sun.star.sdbc.XDatabaseMetaData::getMaxBinaryLiteralLength" );
        typelib_typedescriptionreference_new( &pMembers[90],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName90.pData );
        ::rtl::OUString sMethodName91( "com.sun.star.sdbc.XDatabaseMetaData::getMaxCharLiteralLength" );
        typelib_typedescriptionreference_new( &pMembers[91],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName91.pData );
        ::rtl::OUString sMethodName92( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnNameLength" );
        typelib_typedescriptionreference_new( &pMembers[92],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName92.pData );
        ::rtl::OUString sMethodName93( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInGroupBy" );
        typelib_typedescriptionreference_new( &pMembers[93],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName93.pData );
        ::rtl::OUString sMethodName94( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInIndex" );
        typelib_typedescriptionreference_new( &pMembers[94],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName94.pData );
        ::rtl::OUString sMethodName95( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInOrderBy" );
        typelib_typedescriptionreference_new( &pMembers[95],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName95.pData );
        ::rtl::OUString sMethodName96( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInSelect" );
        typelib_typedescriptionreference_new( &pMembers[96],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName96.pData );
        ::rtl::OUString sMethodName97( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInTable" );
        typelib_typedescriptionreference_new( &pMembers[97],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName97.pData );
        ::rtl::OUString sMethodName98( "com.sun.star.sdbc.XDatabaseMetaData::getMaxConnections" );
        typelib_typedescriptionreference_new( &pMembers[98],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName98.pData );
        ::rtl::OUString sMethodName99( "com.sun.star.sdbc.XDatabaseMetaData::getMaxCursorNameLength" );
        typelib_typedescriptionreference_new( &pMembers[99],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName99.pData );
        ::rtl::OUString sMethodName100( "com.sun.star.sdbc.XDatabaseMetaData::getMaxIndexLength" );
        typelib_typedescriptionreference_new( &pMembers[100],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName100.pData );
        ::rtl::OUString sMethodName101( "com.sun.star.sdbc.XDatabaseMetaData::getMaxSchemaNameLength" );
        typelib_typedescriptionreference_new( &pMembers[101],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName101.pData );
        ::rtl::OUString sMethodName102( "com.sun.star.sdbc.XDatabaseMetaData::getMaxProcedureNameLength" );
        typelib_typedescriptionreference_new( &pMembers[102],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName102.pData );
        ::rtl::OUString sMethodName103( "com.sun.star.sdbc.XDatabaseMetaData::getMaxCatalogNameLength" );
        typelib_typedescriptionreference_new( &pMembers[103],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName103.pData );
        ::rtl::OUString sMethodName104( "com.sun.star.sdbc.XDatabaseMetaData::getMaxRowSize" );
        typelib_typedescriptionreference_new( &pMembers[104],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName104.pData );
        ::rtl::OUString sMethodName105( "com.sun.star.sdbc.XDatabaseMetaData::doesMaxRowSizeIncludeBlobs" );
        typelib_typedescriptionreference_new( &pMembers[105],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName105.pData );
        ::rtl::OUString sMethodName106( "com.sun.star.sdbc.XDatabaseMetaData::getMaxStatementLength" );
        typelib_typedescriptionreference_new( &pMembers[106],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName106.pData );
        ::rtl::OUString sMethodName107( "com.sun.star.sdbc.XDatabaseMetaData::getMaxStatements" );
        typelib_typedescriptionreference_new( &pMembers[107],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName107.pData );
        ::rtl::OUString sMethodName108( "com.sun.star.sdbc.XDatabaseMetaData::getMaxTableNameLength" );
        typelib_typedescriptionreference_new( &pMembers[108],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName108.pData );
        ::rtl::OUString sMethodName109( "com.sun.star.sdbc.XDatabaseMetaData::getMaxTablesInSelect" );
        typelib_typedescriptionreference_new( &pMembers[109],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName109.pData );
        ::rtl::OUString sMethodName110( "com.sun.star.sdbc.XDatabaseMetaData::getMaxUserNameLength" );
        typelib_typedescriptionreference_new( &pMembers[110],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName110.pData );
        ::rtl::OUString sMethodName111( "com.sun.star.sdbc.XDatabaseMetaData::getDefaultTransactionIsolation" );
        typelib_typedescriptionreference_new( &pMembers[111],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName111.pData );
        ::rtl::OUString sMethodName112( "com.sun.star.sdbc.XDatabaseMetaData::supportsTransactions" );
        typelib_typedescriptionreference_new( &pMembers[112],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName112.pData );
        ::rtl::OUString sMethodName113( "com.sun.star.sdbc.XDatabaseMetaData::supportsTransactionIsolationLevel" );
        typelib_typedescriptionreference_new( &pMembers[113],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName113.pData );
        ::rtl::OUString sMethodName114( "com.sun.star.sdbc.XDatabaseMetaData::supportsDataDefinitionAndDataManipulationTransactions" );
        typelib_typedescriptionreference_new( &pMembers[114],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName114.pData );
        ::rtl::OUString sMethodName115( "com.sun.star.sdbc.XDatabaseMetaData::supportsDataManipulationTransactionsOnly" );
        typelib_typedescriptionreference_new( &pMembers[115],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName115.pData );
        ::rtl::OUString sMethodName116( "com.sun.star.sdbc.XDatabaseMetaData::dataDefinitionCausesTransactionCommit" );
        typelib_typedescriptionreference_new( &pMembers[116],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName116.pData );
        ::rtl::OUString sMethodName117( "com.sun.star.sdbc.XDatabaseMetaData::dataDefinitionIgnoredInTransactions" );
        typelib_typedescriptionreference_new( &pMembers[117],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName117.pData );
        ::rtl::OUString sMethodName118( "com.sun.star.sdbc.XDatabaseMetaData::getProcedures" );
        typelib_typedescriptionreference_new( &pMembers[118],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName118.pData );
        ::rtl::OUString sMethodName119( "com.sun.star.sdbc.XDatabaseMetaData::getProcedureColumns" );
        typelib_typedescriptionreference_new( &pMembers[119],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName119.pData );
        ::rtl::OUString sMethodName120( "com.sun.star.sdbc.XDatabaseMetaData::getTables" );
        typelib_typedescriptionreference_new( &pMembers[120],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName120.pData );
        ::rtl::OUString sMethodName121( "com.sun.star.sdbc.XDatabaseMetaData::getSchemas" );
        typelib_typedescriptionreference_new( &pMembers[121],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName121.pData );
        ::rtl::OUString sMethodName122( "com.sun.star.sdbc.XDatabaseMetaData::getCatalogs" );
        typelib_typedescriptionreference_new( &pMembers[122],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName122.pData );
        ::rtl::OUString sMethodName123( "com.sun.star.sdbc.XDatabaseMetaData::getTableTypes" );
        typelib_typedescriptionreference_new( &pMembers[123],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName123.pData );
        ::rtl::OUString sMethodName124( "com.sun.star.sdbc.XDatabaseMetaData::getColumns" );
        typelib_typedescriptionreference_new( &pMembers[124],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName124.pData );
        ::rtl::OUString sMethodName125( "com.sun.star.sdbc.XDatabaseMetaData::getColumnPrivileges" );
        typelib_typedescriptionreference_new( &pMembers[125],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName125.pData );
        ::rtl::OUString sMethodName126( "com.sun.star.sdbc.XDatabaseMetaData::getTablePrivileges" );
        typelib_typedescriptionreference_new( &pMembers[126],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName126.pData );
        ::rtl::OUString sMethodName127( "com.sun.star.sdbc.XDatabaseMetaData::getBestRowIdentifier" );
        typelib_typedescriptionreference_new( &pMembers[127],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName127.pData );
        ::rtl::OUString sMethodName128( "com.sun.star.sdbc.XDatabaseMetaData::getVersionColumns" );
        typelib_typedescriptionreference_new( &pMembers[128],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName128.pData );
        ::rtl::OUString sMethodName129( "com.sun.star.sdbc.XDatabaseMetaData::getPrimaryKeys" );
        typelib_typedescriptionreference_new( &pMembers[129],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName129.pData );
        ::rtl::OUString sMethodName130( "com.sun.star.sdbc.XDatabaseMetaData::getImportedKeys" );
        typelib_typedescriptionreference_new( &pMembers[130],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName130.pData );
        ::rtl::OUString sMethodName131( "com.sun.star.sdbc.XDatabaseMetaData::getExportedKeys" );
        typelib_typedescriptionreference_new( &pMembers[131],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName131.pData );
        ::rtl::OUString sMethodName132( "com.sun.star.sdbc.XDatabaseMetaData::getCrossReference" );
        typelib_typedescriptionreference_new( &pMembers[132],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName132.pData );
        ::rtl::OUString sMethodName133( "com.sun.star.sdbc.XDatabaseMetaData::getTypeInfo" );
        typelib_typedescriptionreference_new( &pMembers[133],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName133.pData );
        ::rtl::OUString sMethodName134( "com.sun.star.sdbc.XDatabaseMetaData::getIndexInfo" );
        typelib_typedescriptionreference_new( &pMembers[134],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName134.pData );
        ::rtl::OUString sMethodName135( "com.sun.star.sdbc.XDatabaseMetaData::supportsResultSetType" );
        typelib_typedescriptionreference_new( &pMembers[135],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName135.pData );
        ::rtl::OUString sMethodName136( "com.sun.star.sdbc.XDatabaseMetaData::supportsResultSetConcurrency" );
        typelib_typedescriptionreference_new( &pMembers[136],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName136.pData );
        ::rtl::OUString sMethodName137( "com.sun.star.sdbc.XDatabaseMetaData::ownUpdatesAreVisible" );
        typelib_typedescriptionreference_new( &pMembers[137],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName137.pData );
        ::rtl::OUString sMethodName138( "com.sun.star.sdbc.XDatabaseMetaData::ownDeletesAreVisible" );
        typelib_typedescriptionreference_new( &pMembers[138],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName138.pData );
        ::rtl::OUString sMethodName139( "com.sun.star.sdbc.XDatabaseMetaData::ownInsertsAreVisible" );
        typelib_typedescriptionreference_new( &pMembers[139],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName139.pData );
        ::rtl::OUString sMethodName140( "com.sun.star.sdbc.XDatabaseMetaData::othersUpdatesAreVisible" );
        typelib_typedescriptionreference_new( &pMembers[140],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName140.pData );
        ::rtl::OUString sMethodName141( "com.sun.star.sdbc.XDatabaseMetaData::othersDeletesAreVisible" );
        typelib_typedescriptionreference_new( &pMembers[141],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName141.pData );
        ::rtl::OUString sMethodName142( "com.sun.star.sdbc.XDatabaseMetaData::othersInsertsAreVisible" );
        typelib_typedescriptionreference_new( &pMembers[142],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName142.pData );
        ::rtl::OUString sMethodName143( "com.sun.star.sdbc.XDatabaseMetaData::updatesAreDetected" );
        typelib_typedescriptionreference_new( &pMembers[143],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName143.pData );
        ::rtl::OUString sMethodName144( "com.sun.star.sdbc.XDatabaseMetaData::deletesAreDetected" );
        typelib_typedescriptionreference_new( &pMembers[144],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName144.pData );
        ::rtl::OUString sMethodName145( "com.sun.star.sdbc.XDatabaseMetaData::insertsAreDetected" );
        typelib_typedescriptionreference_new( &pMembers[145],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName145.pData );
        ::rtl::OUString sMethodName146( "com.sun.star.sdbc.XDatabaseMetaData::supportsBatchUpdates" );
        typelib_typedescriptionreference_new( &pMembers[146],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName146.pData );
        ::rtl::OUString sMethodName147( "com.sun.star.sdbc.XDatabaseMetaData::getUDTs" );
        typelib_typedescriptionreference_new( &pMembers[147],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName147.pData );
        ::rtl::OUString sMethodName148( "com.sun.star.sdbc.XDatabaseMetaData::getConnection" );
        typelib_typedescriptionreference_new( &pMembers[148],
                                              (typelib_TypeClass)::css::uno::TypeClass_INTERFACE_METHOD,
                                              sMethodName148.pData );

        typelib_typedescription_newMIInterface(
            &pTD,
            sTypeName.pData, 0, 0, 0, 0, 0,
            1, aSuperTypes,
            149,
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
        typelib_typedescriptionreference_release( pMembers[26] );
        typelib_typedescriptionreference_release( pMembers[27] );
        typelib_typedescriptionreference_release( pMembers[28] );
        typelib_typedescriptionreference_release( pMembers[29] );
        typelib_typedescriptionreference_release( pMembers[30] );
        typelib_typedescriptionreference_release( pMembers[31] );
        typelib_typedescriptionreference_release( pMembers[32] );
        typelib_typedescriptionreference_release( pMembers[33] );
        typelib_typedescriptionreference_release( pMembers[34] );
        typelib_typedescriptionreference_release( pMembers[35] );
        typelib_typedescriptionreference_release( pMembers[36] );
        typelib_typedescriptionreference_release( pMembers[37] );
        typelib_typedescriptionreference_release( pMembers[38] );
        typelib_typedescriptionreference_release( pMembers[39] );
        typelib_typedescriptionreference_release( pMembers[40] );
        typelib_typedescriptionreference_release( pMembers[41] );
        typelib_typedescriptionreference_release( pMembers[42] );
        typelib_typedescriptionreference_release( pMembers[43] );
        typelib_typedescriptionreference_release( pMembers[44] );
        typelib_typedescriptionreference_release( pMembers[45] );
        typelib_typedescriptionreference_release( pMembers[46] );
        typelib_typedescriptionreference_release( pMembers[47] );
        typelib_typedescriptionreference_release( pMembers[48] );
        typelib_typedescriptionreference_release( pMembers[49] );
        typelib_typedescriptionreference_release( pMembers[50] );
        typelib_typedescriptionreference_release( pMembers[51] );
        typelib_typedescriptionreference_release( pMembers[52] );
        typelib_typedescriptionreference_release( pMembers[53] );
        typelib_typedescriptionreference_release( pMembers[54] );
        typelib_typedescriptionreference_release( pMembers[55] );
        typelib_typedescriptionreference_release( pMembers[56] );
        typelib_typedescriptionreference_release( pMembers[57] );
        typelib_typedescriptionreference_release( pMembers[58] );
        typelib_typedescriptionreference_release( pMembers[59] );
        typelib_typedescriptionreference_release( pMembers[60] );
        typelib_typedescriptionreference_release( pMembers[61] );
        typelib_typedescriptionreference_release( pMembers[62] );
        typelib_typedescriptionreference_release( pMembers[63] );
        typelib_typedescriptionreference_release( pMembers[64] );
        typelib_typedescriptionreference_release( pMembers[65] );
        typelib_typedescriptionreference_release( pMembers[66] );
        typelib_typedescriptionreference_release( pMembers[67] );
        typelib_typedescriptionreference_release( pMembers[68] );
        typelib_typedescriptionreference_release( pMembers[69] );
        typelib_typedescriptionreference_release( pMembers[70] );
        typelib_typedescriptionreference_release( pMembers[71] );
        typelib_typedescriptionreference_release( pMembers[72] );
        typelib_typedescriptionreference_release( pMembers[73] );
        typelib_typedescriptionreference_release( pMembers[74] );
        typelib_typedescriptionreference_release( pMembers[75] );
        typelib_typedescriptionreference_release( pMembers[76] );
        typelib_typedescriptionreference_release( pMembers[77] );
        typelib_typedescriptionreference_release( pMembers[78] );
        typelib_typedescriptionreference_release( pMembers[79] );
        typelib_typedescriptionreference_release( pMembers[80] );
        typelib_typedescriptionreference_release( pMembers[81] );
        typelib_typedescriptionreference_release( pMembers[82] );
        typelib_typedescriptionreference_release( pMembers[83] );
        typelib_typedescriptionreference_release( pMembers[84] );
        typelib_typedescriptionreference_release( pMembers[85] );
        typelib_typedescriptionreference_release( pMembers[86] );
        typelib_typedescriptionreference_release( pMembers[87] );
        typelib_typedescriptionreference_release( pMembers[88] );
        typelib_typedescriptionreference_release( pMembers[89] );
        typelib_typedescriptionreference_release( pMembers[90] );
        typelib_typedescriptionreference_release( pMembers[91] );
        typelib_typedescriptionreference_release( pMembers[92] );
        typelib_typedescriptionreference_release( pMembers[93] );
        typelib_typedescriptionreference_release( pMembers[94] );
        typelib_typedescriptionreference_release( pMembers[95] );
        typelib_typedescriptionreference_release( pMembers[96] );
        typelib_typedescriptionreference_release( pMembers[97] );
        typelib_typedescriptionreference_release( pMembers[98] );
        typelib_typedescriptionreference_release( pMembers[99] );
        typelib_typedescriptionreference_release( pMembers[100] );
        typelib_typedescriptionreference_release( pMembers[101] );
        typelib_typedescriptionreference_release( pMembers[102] );
        typelib_typedescriptionreference_release( pMembers[103] );
        typelib_typedescriptionreference_release( pMembers[104] );
        typelib_typedescriptionreference_release( pMembers[105] );
        typelib_typedescriptionreference_release( pMembers[106] );
        typelib_typedescriptionreference_release( pMembers[107] );
        typelib_typedescriptionreference_release( pMembers[108] );
        typelib_typedescriptionreference_release( pMembers[109] );
        typelib_typedescriptionreference_release( pMembers[110] );
        typelib_typedescriptionreference_release( pMembers[111] );
        typelib_typedescriptionreference_release( pMembers[112] );
        typelib_typedescriptionreference_release( pMembers[113] );
        typelib_typedescriptionreference_release( pMembers[114] );
        typelib_typedescriptionreference_release( pMembers[115] );
        typelib_typedescriptionreference_release( pMembers[116] );
        typelib_typedescriptionreference_release( pMembers[117] );
        typelib_typedescriptionreference_release( pMembers[118] );
        typelib_typedescriptionreference_release( pMembers[119] );
        typelib_typedescriptionreference_release( pMembers[120] );
        typelib_typedescriptionreference_release( pMembers[121] );
        typelib_typedescriptionreference_release( pMembers[122] );
        typelib_typedescriptionreference_release( pMembers[123] );
        typelib_typedescriptionreference_release( pMembers[124] );
        typelib_typedescriptionreference_release( pMembers[125] );
        typelib_typedescriptionreference_release( pMembers[126] );
        typelib_typedescriptionreference_release( pMembers[127] );
        typelib_typedescriptionreference_release( pMembers[128] );
        typelib_typedescriptionreference_release( pMembers[129] );
        typelib_typedescriptionreference_release( pMembers[130] );
        typelib_typedescriptionreference_release( pMembers[131] );
        typelib_typedescriptionreference_release( pMembers[132] );
        typelib_typedescriptionreference_release( pMembers[133] );
        typelib_typedescriptionreference_release( pMembers[134] );
        typelib_typedescriptionreference_release( pMembers[135] );
        typelib_typedescriptionreference_release( pMembers[136] );
        typelib_typedescriptionreference_release( pMembers[137] );
        typelib_typedescriptionreference_release( pMembers[138] );
        typelib_typedescriptionreference_release( pMembers[139] );
        typelib_typedescriptionreference_release( pMembers[140] );
        typelib_typedescriptionreference_release( pMembers[141] );
        typelib_typedescriptionreference_release( pMembers[142] );
        typelib_typedescriptionreference_release( pMembers[143] );
        typelib_typedescriptionreference_release( pMembers[144] );
        typelib_typedescriptionreference_release( pMembers[145] );
        typelib_typedescriptionreference_release( pMembers[146] );
        typelib_typedescriptionreference_release( pMembers[147] );
        typelib_typedescriptionreference_release( pMembers[148] );
        typelib_typedescription_release( (typelib_TypeDescription*)pTD );

        return new ::css::uno::Type( ::css::uno::TypeClass_INTERFACE, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::XDatabaseMetaData const *) {
    const ::css::uno::Type &rRet = *detail::theXDatabaseMetaDataType::get();
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
                ::rtl::OUString sMethodName0( "com.sun.star.sdbc.XDatabaseMetaData::allProceduresAreCallable" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    3, sal_False,
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
                ::rtl::OUString sMethodName1( "com.sun.star.sdbc.XDatabaseMetaData::allTablesAreSelectable" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    4, sal_False,
                    sMethodName1.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType1.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType2( "string" );
                ::rtl::OUString sMethodName2( "com.sun.star.sdbc.XDatabaseMetaData::getURL" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    5, sal_False,
                    sMethodName2.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType2.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType3( "string" );
                ::rtl::OUString sMethodName3( "com.sun.star.sdbc.XDatabaseMetaData::getUserName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    6, sal_False,
                    sMethodName3.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType3.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType4( "boolean" );
                ::rtl::OUString sMethodName4( "com.sun.star.sdbc.XDatabaseMetaData::isReadOnly" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    7, sal_False,
                    sMethodName4.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType4.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType5( "boolean" );
                ::rtl::OUString sMethodName5( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedHigh" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    8, sal_False,
                    sMethodName5.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType5.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType6( "boolean" );
                ::rtl::OUString sMethodName6( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedLow" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    9, sal_False,
                    sMethodName6.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType6.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType7( "boolean" );
                ::rtl::OUString sMethodName7( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedAtStart" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    10, sal_False,
                    sMethodName7.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType7.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType8( "boolean" );
                ::rtl::OUString sMethodName8( "com.sun.star.sdbc.XDatabaseMetaData::nullsAreSortedAtEnd" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    11, sal_False,
                    sMethodName8.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType8.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType9( "string" );
                ::rtl::OUString sMethodName9( "com.sun.star.sdbc.XDatabaseMetaData::getDatabaseProductName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    12, sal_False,
                    sMethodName9.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType9.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType10( "string" );
                ::rtl::OUString sMethodName10( "com.sun.star.sdbc.XDatabaseMetaData::getDatabaseProductVersion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    13, sal_False,
                    sMethodName10.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType10.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType11( "string" );
                ::rtl::OUString sMethodName11( "com.sun.star.sdbc.XDatabaseMetaData::getDriverName" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    14, sal_False,
                    sMethodName11.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType11.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType12( "string" );
                ::rtl::OUString sMethodName12( "com.sun.star.sdbc.XDatabaseMetaData::getDriverVersion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    15, sal_False,
                    sMethodName12.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType12.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType13( "long" );
                ::rtl::OUString sMethodName13( "com.sun.star.sdbc.XDatabaseMetaData::getDriverMajorVersion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    16, sal_False,
                    sMethodName13.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType13.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData };
                ::rtl::OUString sReturnType14( "long" );
                ::rtl::OUString sMethodName14( "com.sun.star.sdbc.XDatabaseMetaData::getDriverMinorVersion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    17, sal_False,
                    sMethodName14.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType14.pData,
                    0, 0,
                    1, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType15( "boolean" );
                ::rtl::OUString sMethodName15( "com.sun.star.sdbc.XDatabaseMetaData::usesLocalFiles" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    18, sal_False,
                    sMethodName15.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType15.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType16( "boolean" );
                ::rtl::OUString sMethodName16( "com.sun.star.sdbc.XDatabaseMetaData::usesLocalFilePerTable" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    19, sal_False,
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
                ::rtl::OUString sMethodName17( "com.sun.star.sdbc.XDatabaseMetaData::supportsMixedCaseIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    20, sal_False,
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
                ::rtl::OUString sMethodName18( "com.sun.star.sdbc.XDatabaseMetaData::storesUpperCaseIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    21, sal_False,
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
                ::rtl::OUString sMethodName19( "com.sun.star.sdbc.XDatabaseMetaData::storesLowerCaseIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    22, sal_False,
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
                ::rtl::OUString sMethodName20( "com.sun.star.sdbc.XDatabaseMetaData::storesMixedCaseIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    23, sal_False,
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
                ::rtl::OUString sMethodName21( "com.sun.star.sdbc.XDatabaseMetaData::supportsMixedCaseQuotedIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    24, sal_False,
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
                ::rtl::OUString sMethodName22( "com.sun.star.sdbc.XDatabaseMetaData::storesUpperCaseQuotedIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    25, sal_False,
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
                ::rtl::OUString sMethodName23( "com.sun.star.sdbc.XDatabaseMetaData::storesLowerCaseQuotedIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    26, sal_False,
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
                ::rtl::OUString sMethodName24( "com.sun.star.sdbc.XDatabaseMetaData::storesMixedCaseQuotedIdentifiers" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    27, sal_False,
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
                ::rtl::OUString sReturnType25( "string" );
                ::rtl::OUString sMethodName25( "com.sun.star.sdbc.XDatabaseMetaData::getIdentifierQuoteString" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    28, sal_False,
                    sMethodName25.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType25.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType26( "string" );
                ::rtl::OUString sMethodName26( "com.sun.star.sdbc.XDatabaseMetaData::getSQLKeywords" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    29, sal_False,
                    sMethodName26.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType26.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType27( "string" );
                ::rtl::OUString sMethodName27( "com.sun.star.sdbc.XDatabaseMetaData::getNumericFunctions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    30, sal_False,
                    sMethodName27.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType27.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType28( "string" );
                ::rtl::OUString sMethodName28( "com.sun.star.sdbc.XDatabaseMetaData::getStringFunctions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    31, sal_False,
                    sMethodName28.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType28.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType29( "string" );
                ::rtl::OUString sMethodName29( "com.sun.star.sdbc.XDatabaseMetaData::getSystemFunctions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    32, sal_False,
                    sMethodName29.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType29.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType30( "string" );
                ::rtl::OUString sMethodName30( "com.sun.star.sdbc.XDatabaseMetaData::getTimeDateFunctions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    33, sal_False,
                    sMethodName30.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType30.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType31( "string" );
                ::rtl::OUString sMethodName31( "com.sun.star.sdbc.XDatabaseMetaData::getSearchStringEscape" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    34, sal_False,
                    sMethodName31.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType31.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType32( "string" );
                ::rtl::OUString sMethodName32( "com.sun.star.sdbc.XDatabaseMetaData::getExtraNameCharacters" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    35, sal_False,
                    sMethodName32.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType32.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType33( "boolean" );
                ::rtl::OUString sMethodName33( "com.sun.star.sdbc.XDatabaseMetaData::supportsAlterTableWithAddColumn" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    36, sal_False,
                    sMethodName33.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType33.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType34( "boolean" );
                ::rtl::OUString sMethodName34( "com.sun.star.sdbc.XDatabaseMetaData::supportsAlterTableWithDropColumn" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    37, sal_False,
                    sMethodName34.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType34.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType35( "boolean" );
                ::rtl::OUString sMethodName35( "com.sun.star.sdbc.XDatabaseMetaData::supportsColumnAliasing" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    38, sal_False,
                    sMethodName35.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType35.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType36( "boolean" );
                ::rtl::OUString sMethodName36( "com.sun.star.sdbc.XDatabaseMetaData::nullPlusNonNullIsNull" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    39, sal_False,
                    sMethodName36.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType36.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType37( "boolean" );
                ::rtl::OUString sMethodName37( "com.sun.star.sdbc.XDatabaseMetaData::supportsTypeConversion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    40, sal_False,
                    sMethodName37.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType37.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "fromType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "toType" );
                ::rtl::OUString sParamType1( "long" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType38( "boolean" );
                ::rtl::OUString sMethodName38( "com.sun.star.sdbc.XDatabaseMetaData::supportsConvert" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    41, sal_False,
                    sMethodName38.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType38.pData,
                    2, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType39( "boolean" );
                ::rtl::OUString sMethodName39( "com.sun.star.sdbc.XDatabaseMetaData::supportsTableCorrelationNames" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    42, sal_False,
                    sMethodName39.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType39.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType40( "boolean" );
                ::rtl::OUString sMethodName40( "com.sun.star.sdbc.XDatabaseMetaData::supportsDifferentTableCorrelationNames" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    43, sal_False,
                    sMethodName40.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType40.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType41( "boolean" );
                ::rtl::OUString sMethodName41( "com.sun.star.sdbc.XDatabaseMetaData::supportsExpressionsInOrderBy" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    44, sal_False,
                    sMethodName41.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType41.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType42( "boolean" );
                ::rtl::OUString sMethodName42( "com.sun.star.sdbc.XDatabaseMetaData::supportsOrderByUnrelated" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    45, sal_False,
                    sMethodName42.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType42.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType43( "boolean" );
                ::rtl::OUString sMethodName43( "com.sun.star.sdbc.XDatabaseMetaData::supportsGroupBy" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    46, sal_False,
                    sMethodName43.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType43.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType44( "boolean" );
                ::rtl::OUString sMethodName44( "com.sun.star.sdbc.XDatabaseMetaData::supportsGroupByUnrelated" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    47, sal_False,
                    sMethodName44.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType44.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType45( "boolean" );
                ::rtl::OUString sMethodName45( "com.sun.star.sdbc.XDatabaseMetaData::supportsGroupByBeyondSelect" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    48, sal_False,
                    sMethodName45.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType45.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType46( "boolean" );
                ::rtl::OUString sMethodName46( "com.sun.star.sdbc.XDatabaseMetaData::supportsLikeEscapeClause" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    49, sal_False,
                    sMethodName46.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType46.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType47( "boolean" );
                ::rtl::OUString sMethodName47( "com.sun.star.sdbc.XDatabaseMetaData::supportsMultipleResultSets" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    50, sal_False,
                    sMethodName47.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType47.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType48( "boolean" );
                ::rtl::OUString sMethodName48( "com.sun.star.sdbc.XDatabaseMetaData::supportsMultipleTransactions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    51, sal_False,
                    sMethodName48.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType48.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType49( "boolean" );
                ::rtl::OUString sMethodName49( "com.sun.star.sdbc.XDatabaseMetaData::supportsNonNullableColumns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    52, sal_False,
                    sMethodName49.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType49.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType50( "boolean" );
                ::rtl::OUString sMethodName50( "com.sun.star.sdbc.XDatabaseMetaData::supportsMinimumSQLGrammar" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    53, sal_False,
                    sMethodName50.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType50.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType51( "boolean" );
                ::rtl::OUString sMethodName51( "com.sun.star.sdbc.XDatabaseMetaData::supportsCoreSQLGrammar" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    54, sal_False,
                    sMethodName51.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType51.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType52( "boolean" );
                ::rtl::OUString sMethodName52( "com.sun.star.sdbc.XDatabaseMetaData::supportsExtendedSQLGrammar" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    55, sal_False,
                    sMethodName52.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType52.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType53( "boolean" );
                ::rtl::OUString sMethodName53( "com.sun.star.sdbc.XDatabaseMetaData::supportsANSI92EntryLevelSQL" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    56, sal_False,
                    sMethodName53.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType53.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType54( "boolean" );
                ::rtl::OUString sMethodName54( "com.sun.star.sdbc.XDatabaseMetaData::supportsANSI92IntermediateSQL" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    57, sal_False,
                    sMethodName54.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType54.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType55( "boolean" );
                ::rtl::OUString sMethodName55( "com.sun.star.sdbc.XDatabaseMetaData::supportsANSI92FullSQL" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    58, sal_False,
                    sMethodName55.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType55.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType56( "boolean" );
                ::rtl::OUString sMethodName56( "com.sun.star.sdbc.XDatabaseMetaData::supportsIntegrityEnhancementFacility" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    59, sal_False,
                    sMethodName56.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType56.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType57( "boolean" );
                ::rtl::OUString sMethodName57( "com.sun.star.sdbc.XDatabaseMetaData::supportsOuterJoins" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    60, sal_False,
                    sMethodName57.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType57.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType58( "boolean" );
                ::rtl::OUString sMethodName58( "com.sun.star.sdbc.XDatabaseMetaData::supportsFullOuterJoins" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    61, sal_False,
                    sMethodName58.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType58.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType59( "boolean" );
                ::rtl::OUString sMethodName59( "com.sun.star.sdbc.XDatabaseMetaData::supportsLimitedOuterJoins" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    62, sal_False,
                    sMethodName59.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType59.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType60( "string" );
                ::rtl::OUString sMethodName60( "com.sun.star.sdbc.XDatabaseMetaData::getSchemaTerm" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    63, sal_False,
                    sMethodName60.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType60.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType61( "string" );
                ::rtl::OUString sMethodName61( "com.sun.star.sdbc.XDatabaseMetaData::getProcedureTerm" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    64, sal_False,
                    sMethodName61.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType61.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType62( "string" );
                ::rtl::OUString sMethodName62( "com.sun.star.sdbc.XDatabaseMetaData::getCatalogTerm" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    65, sal_False,
                    sMethodName62.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType62.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType63( "boolean" );
                ::rtl::OUString sMethodName63( "com.sun.star.sdbc.XDatabaseMetaData::isCatalogAtStart" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    66, sal_False,
                    sMethodName63.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType63.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType64( "string" );
                ::rtl::OUString sMethodName64( "com.sun.star.sdbc.XDatabaseMetaData::getCatalogSeparator" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    67, sal_False,
                    sMethodName64.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_STRING, sReturnType64.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType65( "boolean" );
                ::rtl::OUString sMethodName65( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInDataManipulation" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    68, sal_False,
                    sMethodName65.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType65.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType66( "boolean" );
                ::rtl::OUString sMethodName66( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInProcedureCalls" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    69, sal_False,
                    sMethodName66.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType66.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType67( "boolean" );
                ::rtl::OUString sMethodName67( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInTableDefinitions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    70, sal_False,
                    sMethodName67.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType67.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType68( "boolean" );
                ::rtl::OUString sMethodName68( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInIndexDefinitions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    71, sal_False,
                    sMethodName68.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType68.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType69( "boolean" );
                ::rtl::OUString sMethodName69( "com.sun.star.sdbc.XDatabaseMetaData::supportsSchemasInPrivilegeDefinitions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    72, sal_False,
                    sMethodName69.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType69.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType70( "boolean" );
                ::rtl::OUString sMethodName70( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInDataManipulation" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    73, sal_False,
                    sMethodName70.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType70.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType71( "boolean" );
                ::rtl::OUString sMethodName71( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInProcedureCalls" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    74, sal_False,
                    sMethodName71.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType71.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType72( "boolean" );
                ::rtl::OUString sMethodName72( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInTableDefinitions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    75, sal_False,
                    sMethodName72.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType72.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType73( "boolean" );
                ::rtl::OUString sMethodName73( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInIndexDefinitions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    76, sal_False,
                    sMethodName73.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType73.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType74( "boolean" );
                ::rtl::OUString sMethodName74( "com.sun.star.sdbc.XDatabaseMetaData::supportsCatalogsInPrivilegeDefinitions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    77, sal_False,
                    sMethodName74.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType74.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType75( "boolean" );
                ::rtl::OUString sMethodName75( "com.sun.star.sdbc.XDatabaseMetaData::supportsPositionedDelete" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    78, sal_False,
                    sMethodName75.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType75.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType76( "boolean" );
                ::rtl::OUString sMethodName76( "com.sun.star.sdbc.XDatabaseMetaData::supportsPositionedUpdate" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    79, sal_False,
                    sMethodName76.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType76.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType77( "boolean" );
                ::rtl::OUString sMethodName77( "com.sun.star.sdbc.XDatabaseMetaData::supportsSelectForUpdate" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    80, sal_False,
                    sMethodName77.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType77.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType78( "boolean" );
                ::rtl::OUString sMethodName78( "com.sun.star.sdbc.XDatabaseMetaData::supportsStoredProcedures" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    81, sal_False,
                    sMethodName78.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType78.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType79( "boolean" );
                ::rtl::OUString sMethodName79( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInComparisons" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    82, sal_False,
                    sMethodName79.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType79.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType80( "boolean" );
                ::rtl::OUString sMethodName80( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInExists" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    83, sal_False,
                    sMethodName80.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType80.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType81( "boolean" );
                ::rtl::OUString sMethodName81( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInIns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    84, sal_False,
                    sMethodName81.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType81.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType82( "boolean" );
                ::rtl::OUString sMethodName82( "com.sun.star.sdbc.XDatabaseMetaData::supportsSubqueriesInQuantifieds" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    85, sal_False,
                    sMethodName82.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType82.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType83( "boolean" );
                ::rtl::OUString sMethodName83( "com.sun.star.sdbc.XDatabaseMetaData::supportsCorrelatedSubqueries" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    86, sal_False,
                    sMethodName83.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType83.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType84( "boolean" );
                ::rtl::OUString sMethodName84( "com.sun.star.sdbc.XDatabaseMetaData::supportsUnion" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    87, sal_False,
                    sMethodName84.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType84.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType85( "boolean" );
                ::rtl::OUString sMethodName85( "com.sun.star.sdbc.XDatabaseMetaData::supportsUnionAll" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    88, sal_False,
                    sMethodName85.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType85.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType86( "boolean" );
                ::rtl::OUString sMethodName86( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenCursorsAcrossCommit" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    89, sal_False,
                    sMethodName86.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType86.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType87( "boolean" );
                ::rtl::OUString sMethodName87( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenCursorsAcrossRollback" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    90, sal_False,
                    sMethodName87.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType87.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType88( "boolean" );
                ::rtl::OUString sMethodName88( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenStatementsAcrossCommit" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    91, sal_False,
                    sMethodName88.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType88.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType89( "boolean" );
                ::rtl::OUString sMethodName89( "com.sun.star.sdbc.XDatabaseMetaData::supportsOpenStatementsAcrossRollback" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    92, sal_False,
                    sMethodName89.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType89.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType90( "long" );
                ::rtl::OUString sMethodName90( "com.sun.star.sdbc.XDatabaseMetaData::getMaxBinaryLiteralLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    93, sal_False,
                    sMethodName90.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType90.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType91( "long" );
                ::rtl::OUString sMethodName91( "com.sun.star.sdbc.XDatabaseMetaData::getMaxCharLiteralLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    94, sal_False,
                    sMethodName91.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType91.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType92( "long" );
                ::rtl::OUString sMethodName92( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    95, sal_False,
                    sMethodName92.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType92.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType93( "long" );
                ::rtl::OUString sMethodName93( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInGroupBy" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    96, sal_False,
                    sMethodName93.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType93.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType94( "long" );
                ::rtl::OUString sMethodName94( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInIndex" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    97, sal_False,
                    sMethodName94.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType94.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType95( "long" );
                ::rtl::OUString sMethodName95( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInOrderBy" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    98, sal_False,
                    sMethodName95.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType95.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType96( "long" );
                ::rtl::OUString sMethodName96( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInSelect" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    99, sal_False,
                    sMethodName96.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType96.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType97( "long" );
                ::rtl::OUString sMethodName97( "com.sun.star.sdbc.XDatabaseMetaData::getMaxColumnsInTable" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    100, sal_False,
                    sMethodName97.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType97.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType98( "long" );
                ::rtl::OUString sMethodName98( "com.sun.star.sdbc.XDatabaseMetaData::getMaxConnections" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    101, sal_False,
                    sMethodName98.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType98.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType99( "long" );
                ::rtl::OUString sMethodName99( "com.sun.star.sdbc.XDatabaseMetaData::getMaxCursorNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    102, sal_False,
                    sMethodName99.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType99.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType100( "long" );
                ::rtl::OUString sMethodName100( "com.sun.star.sdbc.XDatabaseMetaData::getMaxIndexLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    103, sal_False,
                    sMethodName100.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType100.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType101( "long" );
                ::rtl::OUString sMethodName101( "com.sun.star.sdbc.XDatabaseMetaData::getMaxSchemaNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    104, sal_False,
                    sMethodName101.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType101.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType102( "long" );
                ::rtl::OUString sMethodName102( "com.sun.star.sdbc.XDatabaseMetaData::getMaxProcedureNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    105, sal_False,
                    sMethodName102.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType102.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType103( "long" );
                ::rtl::OUString sMethodName103( "com.sun.star.sdbc.XDatabaseMetaData::getMaxCatalogNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    106, sal_False,
                    sMethodName103.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType103.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType104( "long" );
                ::rtl::OUString sMethodName104( "com.sun.star.sdbc.XDatabaseMetaData::getMaxRowSize" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    107, sal_False,
                    sMethodName104.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType104.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType105( "boolean" );
                ::rtl::OUString sMethodName105( "com.sun.star.sdbc.XDatabaseMetaData::doesMaxRowSizeIncludeBlobs" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    108, sal_False,
                    sMethodName105.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType105.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType106( "long" );
                ::rtl::OUString sMethodName106( "com.sun.star.sdbc.XDatabaseMetaData::getMaxStatementLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    109, sal_False,
                    sMethodName106.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType106.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType107( "long" );
                ::rtl::OUString sMethodName107( "com.sun.star.sdbc.XDatabaseMetaData::getMaxStatements" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    110, sal_False,
                    sMethodName107.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType107.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType108( "long" );
                ::rtl::OUString sMethodName108( "com.sun.star.sdbc.XDatabaseMetaData::getMaxTableNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    111, sal_False,
                    sMethodName108.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType108.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType109( "long" );
                ::rtl::OUString sMethodName109( "com.sun.star.sdbc.XDatabaseMetaData::getMaxTablesInSelect" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    112, sal_False,
                    sMethodName109.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType109.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType110( "long" );
                ::rtl::OUString sMethodName110( "com.sun.star.sdbc.XDatabaseMetaData::getMaxUserNameLength" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    113, sal_False,
                    sMethodName110.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType110.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType111( "long" );
                ::rtl::OUString sMethodName111( "com.sun.star.sdbc.XDatabaseMetaData::getDefaultTransactionIsolation" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    114, sal_False,
                    sMethodName111.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_LONG, sReturnType111.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType112( "boolean" );
                ::rtl::OUString sMethodName112( "com.sun.star.sdbc.XDatabaseMetaData::supportsTransactions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    115, sal_False,
                    sMethodName112.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType112.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "level" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType113( "boolean" );
                ::rtl::OUString sMethodName113( "com.sun.star.sdbc.XDatabaseMetaData::supportsTransactionIsolationLevel" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    116, sal_False,
                    sMethodName113.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType113.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType114( "boolean" );
                ::rtl::OUString sMethodName114( "com.sun.star.sdbc.XDatabaseMetaData::supportsDataDefinitionAndDataManipulationTransactions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    117, sal_False,
                    sMethodName114.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType114.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType115( "boolean" );
                ::rtl::OUString sMethodName115( "com.sun.star.sdbc.XDatabaseMetaData::supportsDataManipulationTransactionsOnly" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    118, sal_False,
                    sMethodName115.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType115.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType116( "boolean" );
                ::rtl::OUString sMethodName116( "com.sun.star.sdbc.XDatabaseMetaData::dataDefinitionCausesTransactionCommit" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    119, sal_False,
                    sMethodName116.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType116.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType117( "boolean" );
                ::rtl::OUString sMethodName117( "com.sun.star.sdbc.XDatabaseMetaData::dataDefinitionIgnoredInTransactions" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    120, sal_False,
                    sMethodName117.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType117.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
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
                ::rtl::OUString sParamName2( "procedureNamePattern" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType118( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName118( "com.sun.star.sdbc.XDatabaseMetaData::getProcedures" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    121, sal_False,
                    sMethodName118.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType118.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
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
                ::rtl::OUString sParamName2( "procedureNamePattern" );
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
                ::rtl::OUString sReturnType119( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName119( "com.sun.star.sdbc.XDatabaseMetaData::getProcedureColumns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    122, sal_False,
                    sMethodName119.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType119.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
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
                ::rtl::OUString sParamName3( "types" );
                ::rtl::OUString sParamType3( "[]string" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType120( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName120( "com.sun.star.sdbc.XDatabaseMetaData::getTables" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    123, sal_False,
                    sMethodName120.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType120.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType121( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName121( "com.sun.star.sdbc.XDatabaseMetaData::getSchemas" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    124, sal_False,
                    sMethodName121.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType121.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType122( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName122( "com.sun.star.sdbc.XDatabaseMetaData::getCatalogs" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    125, sal_False,
                    sMethodName122.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType122.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType123( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName123( "com.sun.star.sdbc.XDatabaseMetaData::getTableTypes" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    126, sal_False,
                    sMethodName123.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType123.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
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
                ::rtl::OUString sReturnType124( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName124( "com.sun.star.sdbc.XDatabaseMetaData::getColumns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    127, sal_False,
                    sMethodName124.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType124.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
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
                ::rtl::OUString sReturnType125( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName125( "com.sun.star.sdbc.XDatabaseMetaData::getColumnPrivileges" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    128, sal_False,
                    sMethodName125.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType125.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
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
                ::rtl::OUString sReturnType126( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName126( "com.sun.star.sdbc.XDatabaseMetaData::getTablePrivileges" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    129, sal_False,
                    sMethodName126.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType126.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[5];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "scope" );
                ::rtl::OUString sParamType3( "long" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString sParamName4( "nullable" );
                ::rtl::OUString sParamType4( "boolean" );
                aParameters[4].pParamName = sParamName4.pData;
                aParameters[4].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
                aParameters[4].pTypeName = sParamType4.pData;
                aParameters[4].bIn = sal_True;
                aParameters[4].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType127( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName127( "com.sun.star.sdbc.XDatabaseMetaData::getBestRowIdentifier" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    130, sal_False,
                    sMethodName127.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType127.pData,
                    5, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType128( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName128( "com.sun.star.sdbc.XDatabaseMetaData::getVersionColumns" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    131, sal_False,
                    sMethodName128.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType128.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType129( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName129( "com.sun.star.sdbc.XDatabaseMetaData::getPrimaryKeys" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    132, sal_False,
                    sMethodName129.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType129.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType130( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName130( "com.sun.star.sdbc.XDatabaseMetaData::getImportedKeys" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    133, sal_False,
                    sMethodName130.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType130.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[3];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType131( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName131( "com.sun.star.sdbc.XDatabaseMetaData::getExportedKeys" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    134, sal_False,
                    sMethodName131.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType131.pData,
                    3, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[6];
                ::rtl::OUString sParamName0( "primaryCatalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "primarySchema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "primaryTable" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "foreignCatalog" );
                ::rtl::OUString sParamType3( "any" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString sParamName4( "foreignSchema" );
                ::rtl::OUString sParamType4( "string" );
                aParameters[4].pParamName = sParamName4.pData;
                aParameters[4].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[4].pTypeName = sParamType4.pData;
                aParameters[4].bIn = sal_True;
                aParameters[4].bOut = sal_False;
                ::rtl::OUString sParamName5( "foreignTable" );
                ::rtl::OUString sParamType5( "string" );
                aParameters[5].pParamName = sParamName5.pData;
                aParameters[5].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[5].pTypeName = sParamType5.pData;
                aParameters[5].bIn = sal_True;
                aParameters[5].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType132( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName132( "com.sun.star.sdbc.XDatabaseMetaData::getCrossReference" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    135, sal_False,
                    sMethodName132.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType132.pData,
                    6, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType133( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName133( "com.sun.star.sdbc.XDatabaseMetaData::getTypeInfo" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    136, sal_False,
                    sMethodName133.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType133.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[5];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "schema" );
                ::rtl::OUString sParamType1( "string" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString sParamName2( "table" );
                ::rtl::OUString sParamType2( "string" );
                aParameters[2].pParamName = sParamName2.pData;
                aParameters[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_STRING;
                aParameters[2].pTypeName = sParamType2.pData;
                aParameters[2].bIn = sal_True;
                aParameters[2].bOut = sal_False;
                ::rtl::OUString sParamName3( "unique" );
                ::rtl::OUString sParamType3( "boolean" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString sParamName4( "approximate" );
                ::rtl::OUString sParamType4( "boolean" );
                aParameters[4].pParamName = sParamName4.pData;
                aParameters[4].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
                aParameters[4].pTypeName = sParamType4.pData;
                aParameters[4].bIn = sal_True;
                aParameters[4].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType134( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName134( "com.sun.star.sdbc.XDatabaseMetaData::getIndexInfo" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    137, sal_False,
                    sMethodName134.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType134.pData,
                    5, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType135( "boolean" );
                ::rtl::OUString sMethodName135( "com.sun.star.sdbc.XDatabaseMetaData::supportsResultSetType" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    138, sal_False,
                    sMethodName135.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType135.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[2];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString sParamName1( "concurrency" );
                ::rtl::OUString sParamType1( "long" );
                aParameters[1].pParamName = sParamName1.pData;
                aParameters[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[1].pTypeName = sParamType1.pData;
                aParameters[1].bIn = sal_True;
                aParameters[1].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType136( "boolean" );
                ::rtl::OUString sMethodName136( "com.sun.star.sdbc.XDatabaseMetaData::supportsResultSetConcurrency" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    139, sal_False,
                    sMethodName136.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType136.pData,
                    2, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType137( "boolean" );
                ::rtl::OUString sMethodName137( "com.sun.star.sdbc.XDatabaseMetaData::ownUpdatesAreVisible" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    140, sal_False,
                    sMethodName137.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType137.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType138( "boolean" );
                ::rtl::OUString sMethodName138( "com.sun.star.sdbc.XDatabaseMetaData::ownDeletesAreVisible" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    141, sal_False,
                    sMethodName138.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType138.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType139( "boolean" );
                ::rtl::OUString sMethodName139( "com.sun.star.sdbc.XDatabaseMetaData::ownInsertsAreVisible" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    142, sal_False,
                    sMethodName139.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType139.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType140( "boolean" );
                ::rtl::OUString sMethodName140( "com.sun.star.sdbc.XDatabaseMetaData::othersUpdatesAreVisible" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    143, sal_False,
                    sMethodName140.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType140.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType141( "boolean" );
                ::rtl::OUString sMethodName141( "com.sun.star.sdbc.XDatabaseMetaData::othersDeletesAreVisible" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    144, sal_False,
                    sMethodName141.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType141.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType142( "boolean" );
                ::rtl::OUString sMethodName142( "com.sun.star.sdbc.XDatabaseMetaData::othersInsertsAreVisible" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    145, sal_False,
                    sMethodName142.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType142.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType143( "boolean" );
                ::rtl::OUString sMethodName143( "com.sun.star.sdbc.XDatabaseMetaData::updatesAreDetected" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    146, sal_False,
                    sMethodName143.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType143.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType144( "boolean" );
                ::rtl::OUString sMethodName144( "com.sun.star.sdbc.XDatabaseMetaData::deletesAreDetected" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    147, sal_False,
                    sMethodName144.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType144.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[1];
                ::rtl::OUString sParamName0( "setType" );
                ::rtl::OUString sParamType0( "long" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
                aParameters[0].pTypeName = sParamType0.pData;
                aParameters[0].bIn = sal_True;
                aParameters[0].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType145( "boolean" );
                ::rtl::OUString sMethodName145( "com.sun.star.sdbc.XDatabaseMetaData::insertsAreDetected" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    148, sal_False,
                    sMethodName145.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType145.pData,
                    1, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType146( "boolean" );
                ::rtl::OUString sMethodName146( "com.sun.star.sdbc.XDatabaseMetaData::supportsBatchUpdates" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    149, sal_False,
                    sMethodName146.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN, sReturnType146.pData,
                    0, 0,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                typelib_Parameter_Init aParameters[4];
                ::rtl::OUString sParamName0( "catalog" );
                ::rtl::OUString sParamType0( "any" );
                aParameters[0].pParamName = sParamName0.pData;
                aParameters[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_ANY;
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
                ::rtl::OUString sParamName3( "types" );
                ::rtl::OUString sParamType3( "[]long" );
                aParameters[3].pParamName = sParamName3.pData;
                aParameters[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_SEQUENCE;
                aParameters[3].pTypeName = sParamType3.pData;
                aParameters[3].bIn = sal_True;
                aParameters[3].bOut = sal_False;
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType147( "com.sun.star.sdbc.XResultSet" );
                ::rtl::OUString sMethodName147( "com.sun.star.sdbc.XDatabaseMetaData::getUDTs" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    150, sal_False,
                    sMethodName147.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType147.pData,
                    4, aParameters,
                    2, the_Exceptions );
                typelib_typedescription_register( (typelib_TypeDescription**)&pMethod );
            }
            {
                ::rtl::OUString the_ExceptionName0( "com.sun.star.sdbc.SQLException" );
                ::rtl::OUString the_ExceptionName1( "com.sun.star.uno.RuntimeException" );
                rtl_uString * the_Exceptions[] = { the_ExceptionName0.pData, the_ExceptionName1.pData };
                ::rtl::OUString sReturnType148( "com.sun.star.sdbc.XConnection" );
                ::rtl::OUString sMethodName148( "com.sun.star.sdbc.XDatabaseMetaData::getConnection" );
                typelib_typedescription_newInterfaceMethod( &pMethod,
                    151, sal_False,
                    sMethodName148.pData,
                    (typelib_TypeClass)::css::uno::TypeClass_INTERFACE, sReturnType148.pData,
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

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::uno::Reference< ::css::sdbc::XDatabaseMetaData > const *) {
    return ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XDatabaseMetaData > >::get();
}

::css::uno::Type const & ::css::sdbc::XDatabaseMetaData::static_type(SAL_UNUSED_PARAMETER void *) {
    return ::cppu::UnoType< ::css::sdbc::XDatabaseMetaData >::get();
}

#if defined LIBO_INTERNAL_ONLY
namespace cppu::detail {
template<> struct IsUnoInterfaceType<::css::sdbc::XDatabaseMetaData>: ::std::true_type {};
}
#endif

#endif // INCLUDED_COM_SUN_STAR_SDBC_XDATABASEMETADATA_HPP
