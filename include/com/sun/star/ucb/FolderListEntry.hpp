#ifndef INCLUDED_COM_SUN_STAR_UCB_FOLDERLISTENTRY_HPP
#define INCLUDED_COM_SUN_STAR_UCB_FOLDERLISTENTRY_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/FolderListEntry.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline FolderListEntry::FolderListEntry()
    : Title()
    , ID()
    , Subscribed(false)
    , New(false)
    , Removed(false)
    , Purge(false)
{
}

inline FolderListEntry::FolderListEntry(const ::rtl::OUString& Title_, const ::rtl::OUString& ID_, const ::sal_Bool& Subscribed_, const ::sal_Bool& New_, const ::sal_Bool& Removed_, const ::sal_Bool& Purge_)
    : Title(Title_)
    , ID(ID_)
    , Subscribed(Subscribed_)
    , New(New_)
    , Removed(Removed_)
    , Purge(Purge_)
{
}


inline bool operator==(const FolderListEntry& the_lhs, const FolderListEntry& the_rhs)
{
    return the_lhs.Title == the_rhs.Title
        && the_lhs.ID == the_rhs.ID
        && the_lhs.Subscribed == the_rhs.Subscribed
        && the_lhs.New == the_rhs.New
        && the_lhs.Removed == the_rhs.Removed
        && the_lhs.Purge == the_rhs.Purge;
}

inline bool operator!=(const FolderListEntry& the_lhs, const FolderListEntry& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theFolderListEntryType : public rtl::StaticWithInit< ::css::uno::Type *, theFolderListEntryType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.FolderListEntry" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Title" );
        ::rtl::OUString the_name1( "ID" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name2( "Subscribed" );
        ::rtl::OUString the_name3( "New" );
        ::rtl::OUString the_name4( "Removed" );
        ::rtl::OUString the_name5( "Purge" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name3.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name4.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name5.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 6, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::FolderListEntry const *) {
    return *detail::theFolderListEntryType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::FolderListEntry const *) {
    return ::cppu::UnoType< ::css::ucb::FolderListEntry >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_FOLDERLISTENTRY_HPP
