#ifndef INCLUDED_COM_SUN_STAR_SYSTEM_WINDOWS_JUMPLISTITEM_HPP
#define INCLUDED_COM_SUN_STAR_SYSTEM_WINDOWS_JUMPLISTITEM_HPP

#include "sal/config.h"

#include "com/sun/star/system/windows/JumpListItem.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace system { namespace windows {

inline JumpListItem::JumpListItem()
    : name()
    , description()
    , arguments()
    , iconPath()
{
}

inline JumpListItem::JumpListItem(const ::rtl::OUString& name_, const ::rtl::OUString& description_, const ::rtl::OUString& arguments_, const ::rtl::OUString& iconPath_)
    : name(name_)
    , description(description_)
    , arguments(arguments_)
    , iconPath(iconPath_)
{
}


inline bool operator==(const JumpListItem& the_lhs, const JumpListItem& the_rhs)
{
    return the_lhs.name == the_rhs.name
        && the_lhs.description == the_rhs.description
        && the_lhs.arguments == the_rhs.arguments
        && the_lhs.iconPath == the_rhs.iconPath;
}

inline bool operator!=(const JumpListItem& the_lhs, const JumpListItem& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } } }

namespace com { namespace sun { namespace star { namespace system { namespace windows { namespace detail {

struct theJumpListItemType : public rtl::StaticWithInit< ::css::uno::Type *, theJumpListItemType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.system.windows.JumpListItem" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "name" );
        ::rtl::OUString the_name1( "description" );
        ::rtl::OUString the_name2( "arguments" );
        ::rtl::OUString the_name3( "iconPath" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } } }

namespace com { namespace sun { namespace star { namespace system { namespace windows {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::system::windows::JumpListItem const *) {
    return *detail::theJumpListItemType::get();
}

} } } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::system::windows::JumpListItem const *) {
    return ::cppu::UnoType< ::css::system::windows::JumpListItem >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SYSTEM_WINDOWS_JUMPLISTITEM_HPP
