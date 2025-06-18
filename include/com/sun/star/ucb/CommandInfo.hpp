#ifndef INCLUDED_COM_SUN_STAR_UCB_COMMANDINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_COMMANDINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/CommandInfo.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline CommandInfo::CommandInfo()
    : Name()
    , Handle(0)
    , ArgType()
{
}

inline CommandInfo::CommandInfo(const ::rtl::OUString& Name_, const ::sal_Int32& Handle_, const ::css::uno::Type& ArgType_)
    : Name(Name_)
    , Handle(Handle_)
    , ArgType(ArgType_)
{
}


inline bool operator==(const CommandInfo& the_lhs, const CommandInfo& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Handle == the_rhs.Handle
        && the_lhs.ArgType == the_rhs.ArgType;
}

inline bool operator!=(const CommandInfo& the_lhs, const CommandInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theCommandInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theCommandInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.CommandInfo" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "Handle" );
        ::rtl::OUString the_tname2( "type" );
        ::rtl::OUString the_name2( "ArgType" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_TYPE, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::CommandInfo const *) {
    return *detail::theCommandInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::CommandInfo const *) {
    return ::cppu::UnoType< ::css::ucb::CommandInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_COMMANDINFO_HPP
