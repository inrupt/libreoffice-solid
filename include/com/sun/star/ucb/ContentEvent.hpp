#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/ucb/XContent.hpp"
#include "com/sun/star/ucb/XContentIdentifier.hpp"
#include "com/sun/star/uno/Reference.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentEvent::ContentEvent()
    : ::css::lang::EventObject()
    , Action(0)
    , Content()
    , Id()
{
}

inline ContentEvent::ContentEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Action_, const ::css::uno::Reference< ::css::ucb::XContent >& Content_, const ::css::uno::Reference< ::css::ucb::XContentIdentifier >& Id_)
    : ::css::lang::EventObject(Source_)
    , Action(Action_)
    , Content(Content_)
    , Id(Id_)
{
}


inline bool operator==(const ContentEvent& the_lhs, const ContentEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Action == the_rhs.Action
        && the_lhs.Content == the_rhs.Content
        && the_lhs.Id == the_rhs.Id;
}

inline bool operator!=(const ContentEvent& the_lhs, const ContentEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theContentEventType : public rtl::StaticWithInit< ::css::uno::Type *, theContentEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.ContentEvent" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "Action" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContent > >::get();
        ::rtl::OUString the_tname1( "com.sun.star.ucb.XContent" );
        ::rtl::OUString the_name1( "Content" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentIdentifier > >::get();
        ::rtl::OUString the_tname2( "com.sun.star.ucb.XContentIdentifier" );
        ::rtl::OUString the_name2( "Id" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_INTERFACE, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_INTERFACE, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentEvent const *) {
    return *detail::theContentEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentEvent const *) {
    return ::cppu::UnoType< ::css::ucb::ContentEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTEVENT_HPP
