#ifndef INCLUDED_COM_SUN_STAR_UCB_LISTACTION_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LISTACTION_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ListAction.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ListAction::ListAction()
    : Position(0)
    , Count(0)
    , ListActionType(0)
    , ActionInfo()
{
}

inline ListAction::ListAction(const ::sal_Int32& Position_, const ::sal_Int32& Count_, const ::sal_Int32& ListActionType_, const ::css::uno::Any& ActionInfo_)
    : Position(Position_)
    , Count(Count_)
    , ListActionType(ListActionType_)
    , ActionInfo(ActionInfo_)
{
}


inline bool operator==(const ListAction& the_lhs, const ListAction& the_rhs)
{
    return the_lhs.Position == the_rhs.Position
        && the_lhs.Count == the_rhs.Count
        && the_lhs.ListActionType == the_rhs.ListActionType
        && the_lhs.ActionInfo == the_rhs.ActionInfo;
}

inline bool operator!=(const ListAction& the_lhs, const ListAction& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theListActionType : public rtl::StaticWithInit< ::css::uno::Type *, theListActionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.ListAction" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "Position" );
        ::rtl::OUString the_name1( "Count" );
        ::rtl::OUString the_name2( "ListActionType" );
        ::rtl::OUString the_tname1( "any" );
        ::rtl::OUString the_name3( "ActionInfo" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name2.pData }, false },
            { { typelib_TypeClass_ANY, the_tname1.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ListAction const *) {
    return *detail::theListActionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ListAction const *) {
    return ::cppu::UnoType< ::css::ucb::ListAction >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LISTACTION_HPP
