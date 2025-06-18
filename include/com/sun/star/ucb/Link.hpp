#ifndef INCLUDED_COM_SUN_STAR_UCB_LINK_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LINK_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/Link.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline Link::Link()
    : Source()
    , Destination()
{
}

inline Link::Link(const ::rtl::OUString& Source_, const ::rtl::OUString& Destination_)
    : Source(Source_)
    , Destination(Destination_)
{
}


inline bool operator==(const Link& the_lhs, const Link& the_rhs)
{
    return the_lhs.Source == the_rhs.Source
        && the_lhs.Destination == the_rhs.Destination;
}

inline bool operator!=(const Link& the_lhs, const Link& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theLinkType : public rtl::StaticWithInit< ::css::uno::Type *, theLinkType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.Link" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Source" );
        ::rtl::OUString the_name1( "Destination" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::Link const *) {
    return *detail::theLinkType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::Link const *) {
    return ::cppu::UnoType< ::css::ucb::Link >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LINK_HPP
