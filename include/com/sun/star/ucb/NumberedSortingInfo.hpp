#ifndef INCLUDED_COM_SUN_STAR_UCB_NUMBEREDSORTINGINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_NUMBEREDSORTINGINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/NumberedSortingInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline NumberedSortingInfo::NumberedSortingInfo()
    : ColumnIndex(0)
    , Ascending(false)
{
}

inline NumberedSortingInfo::NumberedSortingInfo(const ::sal_Int32& ColumnIndex_, const ::sal_Bool& Ascending_)
    : ColumnIndex(ColumnIndex_)
    , Ascending(Ascending_)
{
}


inline bool operator==(const NumberedSortingInfo& the_lhs, const NumberedSortingInfo& the_rhs)
{
    return the_lhs.ColumnIndex == the_rhs.ColumnIndex
        && the_lhs.Ascending == the_rhs.Ascending;
}

inline bool operator!=(const NumberedSortingInfo& the_lhs, const NumberedSortingInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theNumberedSortingInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theNumberedSortingInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.NumberedSortingInfo" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "ColumnIndex" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "Ascending" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::NumberedSortingInfo const *) {
    return *detail::theNumberedSortingInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::NumberedSortingInfo const *) {
    return ::cppu::UnoType< ::css::ucb::NumberedSortingInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_NUMBEREDSORTINGINFO_HPP
