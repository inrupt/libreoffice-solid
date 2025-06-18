#ifndef INCLUDED_COM_SUN_STAR_UCB_FOLDERLIST_HPP
#define INCLUDED_COM_SUN_STAR_UCB_FOLDERLIST_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/FolderList.hdl"

#include "com/sun/star/ucb/FolderListCommand.hpp"
#include "com/sun/star/ucb/FolderListEntry.hpp"
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

inline FolderList::FolderList()
    : Command(::css::ucb::FolderListCommand_GET)
    , List()
{
}

inline FolderList::FolderList(const ::css::ucb::FolderListCommand& Command_, const ::css::uno::Sequence< ::css::ucb::FolderListEntry >& List_)
    : Command(Command_)
    , List(List_)
{
}


inline bool operator==(const FolderList& the_lhs, const FolderList& the_rhs)
{
    return the_lhs.Command == the_rhs.Command
        && the_lhs.List == the_rhs.List;
}

inline bool operator!=(const FolderList& the_lhs, const FolderList& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theFolderListType : public rtl::StaticWithInit< ::css::uno::Type *, theFolderListType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.FolderList" );
        ::cppu::UnoType< ::css::ucb::FolderListCommand >::get();
        ::rtl::OUString the_tname0( "com.sun.star.ucb.FolderListCommand" );
        ::rtl::OUString the_name0( "Command" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::FolderListEntry > >::get();
        ::rtl::OUString the_tname1( "[]com.sun.star.ucb.FolderListEntry" );
        ::rtl::OUString the_name1( "List" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::FolderList const *) {
    return *detail::theFolderListType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::FolderList const *) {
    return ::cppu::UnoType< ::css::ucb::FolderList >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_FOLDERLIST_HPP
