#ifndef INCLUDED_COM_SUN_STAR_SDBC_DATATRUNCATION_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_DATATRUNCATION_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/DataTruncation.hdl"

#include "com/sun/star/sdbc/SQLWarning.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline DataTruncation::DataTruncation(
#if defined LIBO_USE_SOURCE_LOCATION
    o3tl::source_location location
#endif
)
    : ::css::sdbc::SQLWarning(
#if defined LIBO_USE_SOURCE_LOCATION
    location
#endif
)
    , Index(0)
    , IsParameter(false)
    , DuringRead(false)
    , DataSize(0)
    , TransferSize(0)
{
    ::cppu::UnoType< ::css::sdbc::DataTruncation >::get();
}

inline DataTruncation::DataTruncation(const ::rtl::OUString& Message_, const ::css::uno::Reference< ::css::uno::XInterface >& Context_, const ::rtl::OUString& SQLState_, const ::sal_Int32& ErrorCode_, const ::css::uno::Any& NextException_, const ::sal_Int32& Index_, const ::sal_Bool& IsParameter_, const ::sal_Bool& DuringRead_, const ::sal_Int32& DataSize_, const ::sal_Int32& TransferSize_
#if defined LIBO_USE_SOURCE_LOCATION
    , o3tl::source_location location
#endif
)
    : ::css::sdbc::SQLWarning(Message_, Context_, SQLState_, ErrorCode_, NextException_
#if defined LIBO_USE_SOURCE_LOCATION
    , location
#endif
)
    , Index(Index_)
    , IsParameter(IsParameter_)
    , DuringRead(DuringRead_)
    , DataSize(DataSize_)
    , TransferSize(TransferSize_)
{
    ::cppu::UnoType< ::css::sdbc::DataTruncation >::get();
}

#if !defined LIBO_INTERNAL_ONLY
DataTruncation::DataTruncation(DataTruncation const & the_other): ::css::sdbc::SQLWarning(the_other), Index(the_other.Index), IsParameter(the_other.IsParameter), DuringRead(the_other.DuringRead), DataSize(the_other.DataSize), TransferSize(the_other.TransferSize) {}

DataTruncation::~DataTruncation() {}

DataTruncation & DataTruncation::operator =(DataTruncation const & the_other) {
    //TODO: Just like its implicitly-defined counterpart, this function definition is not exception-safe
    ::css::sdbc::SQLWarning::operator =(the_other);
    Index = the_other.Index;
    IsParameter = the_other.IsParameter;
    DuringRead = the_other.DuringRead;
    DataSize = the_other.DataSize;
    TransferSize = the_other.TransferSize;
    return *this;
}
#endif

} } } }

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theDataTruncationType : public rtl::StaticWithInit< ::css::uno::Type *, theDataTruncationType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString sTypeName( "com.sun.star.sdbc.DataTruncation" );

        // Start inline typedescription generation
        typelib_TypeDescription * pTD = 0;
        const ::css::uno::Type& rSuperType = ::cppu::UnoType< ::css::sdbc::SQLWarning >::get();

        typelib_CompoundMember_Init aMembers[5];
        ::rtl::OUString sMemberType0( "long" );
        ::rtl::OUString sMemberName0( "Index" );
        aMembers[0].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
        aMembers[0].pTypeName = sMemberType0.pData;
        aMembers[0].pMemberName = sMemberName0.pData;
        ::rtl::OUString sMemberType1( "boolean" );
        ::rtl::OUString sMemberName1( "IsParameter" );
        aMembers[1].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
        aMembers[1].pTypeName = sMemberType1.pData;
        aMembers[1].pMemberName = sMemberName1.pData;
        ::rtl::OUString sMemberType2( "boolean" );
        ::rtl::OUString sMemberName2( "DuringRead" );
        aMembers[2].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_BOOLEAN;
        aMembers[2].pTypeName = sMemberType2.pData;
        aMembers[2].pMemberName = sMemberName2.pData;
        ::rtl::OUString sMemberType3( "long" );
        ::rtl::OUString sMemberName3( "DataSize" );
        aMembers[3].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
        aMembers[3].pTypeName = sMemberType3.pData;
        aMembers[3].pMemberName = sMemberName3.pData;
        ::rtl::OUString sMemberType4( "long" );
        ::rtl::OUString sMemberName4( "TransferSize" );
        aMembers[4].eTypeClass = (typelib_TypeClass)::css::uno::TypeClass_LONG;
        aMembers[4].pTypeName = sMemberType4.pData;
        aMembers[4].pMemberName = sMemberName4.pData;

        typelib_typedescription_new(
            &pTD,
            (typelib_TypeClass)::css::uno::TypeClass_EXCEPTION, sTypeName.pData,
            rSuperType.getTypeLibType(),
            5,
            aMembers );

        typelib_typedescription_register( (typelib_TypeDescription**)&pTD );

        typelib_typedescription_release( pTD );
        // End inline typedescription generation

        return new ::css::uno::Type( ::css::uno::TypeClass_EXCEPTION, sTypeName ); // leaked
    }
};

} } } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::DataTruncation const *) {
    return *detail::theDataTruncationType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::DataTruncation const *) {
    return ::cppu::UnoType< ::css::sdbc::DataTruncation >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_DATATRUNCATION_HPP
