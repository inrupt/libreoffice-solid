#ifndef INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/OpenCommandArgument2.hdl"

#include "com/sun/star/ucb/NumberedSortingInfo.hpp"
#include "com/sun/star/ucb/OpenCommandArgument.hpp"
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

inline OpenCommandArgument2::OpenCommandArgument2()
    : ::css::ucb::OpenCommandArgument()
    , SortingInfo()
{
}

inline OpenCommandArgument2::OpenCommandArgument2(const ::sal_Int32& Mode_, const ::sal_Int32& Priority_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_, const ::css::uno::Sequence< ::css::ucb::NumberedSortingInfo >& SortingInfo_)
    : ::css::ucb::OpenCommandArgument(Mode_, Priority_, Sink_, Properties_)
    , SortingInfo(SortingInfo_)
{
}


inline bool operator==(const OpenCommandArgument2& the_lhs, const OpenCommandArgument2& the_rhs)
{
    return operator==( static_cast<const ::css::ucb::OpenCommandArgument&>(the_lhs), static_cast<const ::css::ucb::OpenCommandArgument&>(the_rhs) )

        && the_lhs.SortingInfo == the_rhs.SortingInfo;
}

inline bool operator!=(const OpenCommandArgument2& the_lhs, const OpenCommandArgument2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theOpenCommandArgument2Type : public rtl::StaticWithInit< ::css::uno::Type *, theOpenCommandArgument2Type >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.OpenCommandArgument2" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::NumberedSortingInfo > >::get();
        ::rtl::OUString the_tname0( "[]com.sun.star.ucb.NumberedSortingInfo" );
        ::rtl::OUString the_name0( "SortingInfo" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::ucb::OpenCommandArgument >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument2 const *) {
    return *detail::theOpenCommandArgument2Type::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::OpenCommandArgument2 const *) {
    return ::cppu::UnoType< ::css::ucb::OpenCommandArgument2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_OPENCOMMANDARGUMENT2_HPP
