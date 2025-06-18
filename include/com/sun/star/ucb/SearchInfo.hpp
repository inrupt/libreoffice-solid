#ifndef INCLUDED_COM_SUN_STAR_UCB_SEARCHINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_SEARCHINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/SearchInfo.hdl"

#include "com/sun/star/ucb/SearchCriterium.hpp"
#include "com/sun/star/ucb/SearchRecursion.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline SearchInfo::SearchInfo()
    : Criteria()
    , Recursion(::css::ucb::SearchRecursion_NONE)
    , IncludeBase(false)
    , RespectFolderViewRestrictions(false)
    , RespectDocViewRestrictions(false)
    , FollowIndirections(false)
{
}

inline SearchInfo::SearchInfo(const ::css::uno::Sequence< ::css::ucb::SearchCriterium >& Criteria_, const ::css::ucb::SearchRecursion& Recursion_, const ::sal_Bool& IncludeBase_, const ::sal_Bool& RespectFolderViewRestrictions_, const ::sal_Bool& RespectDocViewRestrictions_, const ::sal_Bool& FollowIndirections_)
    : Criteria(Criteria_)
    , Recursion(Recursion_)
    , IncludeBase(IncludeBase_)
    , RespectFolderViewRestrictions(RespectFolderViewRestrictions_)
    , RespectDocViewRestrictions(RespectDocViewRestrictions_)
    , FollowIndirections(FollowIndirections_)
{
}


inline bool operator==(const SearchInfo& the_lhs, const SearchInfo& the_rhs)
{
    return the_lhs.Criteria == the_rhs.Criteria
        && the_lhs.Recursion == the_rhs.Recursion
        && the_lhs.IncludeBase == the_rhs.IncludeBase
        && the_lhs.RespectFolderViewRestrictions == the_rhs.RespectFolderViewRestrictions
        && the_lhs.RespectDocViewRestrictions == the_rhs.RespectDocViewRestrictions
        && the_lhs.FollowIndirections == the_rhs.FollowIndirections;
}

inline bool operator!=(const SearchInfo& the_lhs, const SearchInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theSearchInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theSearchInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.SearchInfo" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::SearchCriterium > >::get();
        ::rtl::OUString the_tname0( "[]com.sun.star.ucb.SearchCriterium" );
        ::rtl::OUString the_name0( "Criteria" );
        ::cppu::UnoType< ::css::ucb::SearchRecursion >::get();
        ::rtl::OUString the_tname1( "com.sun.star.ucb.SearchRecursion" );
        ::rtl::OUString the_name1( "Recursion" );
        ::rtl::OUString the_tname2( "boolean" );
        ::rtl::OUString the_name2( "IncludeBase" );
        ::rtl::OUString the_name3( "RespectFolderViewRestrictions" );
        ::rtl::OUString the_name4( "RespectDocViewRestrictions" );
        ::rtl::OUString the_name5( "FollowIndirections" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname2.pData, the_name3.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname2.pData, the_name4.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname2.pData, the_name5.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 6, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::SearchInfo const *) {
    return *detail::theSearchInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::SearchInfo const *) {
    return ::cppu::UnoType< ::css::ucb::SearchInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_SEARCHINFO_HPP
