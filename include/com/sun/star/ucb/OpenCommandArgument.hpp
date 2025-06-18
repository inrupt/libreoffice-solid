#ifndef INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/OpenCommandArgument.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/uno/XInterface.hpp"
#include "com/sun/star/uno/Reference.hxx"
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

inline OpenCommandArgument::OpenCommandArgument()
    : Mode(0)
    , Priority(0)
    , Sink()
    , Properties()
{
}

inline OpenCommandArgument::OpenCommandArgument(const ::sal_Int32& Mode_, const ::sal_Int32& Priority_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_)
    : Mode(Mode_)
    , Priority(Priority_)
    , Sink(Sink_)
    , Properties(Properties_)
{
}


inline bool operator==(const OpenCommandArgument& the_lhs, const OpenCommandArgument& the_rhs)
{
    return the_lhs.Mode == the_rhs.Mode
        && the_lhs.Priority == the_rhs.Priority
        && the_lhs.Sink == the_rhs.Sink
        && the_lhs.Properties == the_rhs.Properties;
}

inline bool operator!=(const OpenCommandArgument& the_lhs, const OpenCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theOpenCommandArgumentType : public rtl::StaticWithInit< ::css::uno::Type *, theOpenCommandArgumentType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.OpenCommandArgument" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "Mode" );
        ::rtl::OUString the_name1( "Priority" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::uno::XInterface > >::get();
        ::rtl::OUString the_tname1( "com.sun.star.uno.XInterface" );
        ::rtl::OUString the_name2( "Sink" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::Property > >::get();
        ::rtl::OUString the_tname2( "[]com.sun.star.beans.Property" );
        ::rtl::OUString the_name3( "Properties" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_INTERFACE, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname2.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument const *) {
    return *detail::theOpenCommandArgumentType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::OpenCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT_HPP
