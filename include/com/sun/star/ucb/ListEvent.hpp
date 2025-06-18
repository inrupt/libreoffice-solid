#ifndef INCLUDED_COM_SUN_STAR_UCB_LISTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_LISTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ListEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/ucb/ListAction.hpp"
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

inline ListEvent::ListEvent()
    : ::css::lang::EventObject()
    , Changes()
{
}

inline ListEvent::ListEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Sequence< ::css::ucb::ListAction >& Changes_)
    : ::css::lang::EventObject(Source_)
    , Changes(Changes_)
{
}


inline bool operator==(const ListEvent& the_lhs, const ListEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Changes == the_rhs.Changes;
}

inline bool operator!=(const ListEvent& the_lhs, const ListEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theListEventType : public rtl::StaticWithInit< ::css::uno::Type *, theListEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.ListEvent" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::ucb::ListAction > >::get();
        ::rtl::OUString the_tname0( "[]com.sun.star.ucb.ListAction" );
        ::rtl::OUString the_name0( "Changes" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SEQUENCE, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ListEvent const *) {
    return *detail::theListEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ListEvent const *) {
    return ::cppu::UnoType< ::css::ucb::ListEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_LISTEVENT_HPP
