#ifndef INCLUDED_COM_SUN_STAR_UCB_SORTINGINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SORTINGINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SortingInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline SortingInfo::SortingInfo()
    : PropertyName()
    , Ascending(false)
{
}

inline SortingInfo::SortingInfo(const ::rtl::OUString& PropertyName_, const ::sal_Bool& Ascending_)
    : PropertyName(PropertyName_)
    , Ascending(Ascending_)
{
}


inline bool operator==(const SortingInfo& the_lhs, const SortingInfo& the_rhs)
{
    return the_lhs.PropertyName == the_rhs.PropertyName
        && the_lhs.Ascending == the_rhs.Ascending;
}

inline bool operator!=(const SortingInfo& the_lhs, const SortingInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theSortingInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theSortingInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.SortingInfo" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "PropertyName" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "Ascending" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
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

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SortingInfo const *) {
    return *detail::theSortingInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SortingInfo const *) {
    return ::cppu::UnoType< ::css::ucb::SortingInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SORTINGINFO_HPP
