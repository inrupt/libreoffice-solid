#ifndef INCLUDED_COM_SUN_STAR_UCB_REMOTECONTENTPROVIDERCHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_REMOTECONTENTPROVIDERCHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/RemoteContentProviderChangeEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/ucb/RemoteContentProviderChangeAction.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline RemoteContentProviderChangeEvent::RemoteContentProviderChangeEvent()
    : ::css::lang::EventObject()
    , Identifier()
    , Action(::css::ucb::RemoteContentProviderChangeAction_ADDED)
{
}

inline RemoteContentProviderChangeEvent::RemoteContentProviderChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& Identifier_, const ::css::ucb::RemoteContentProviderChangeAction& Action_)
    : ::css::lang::EventObject(Source_)
    , Identifier(Identifier_)
    , Action(Action_)
{
}


inline bool operator==(const RemoteContentProviderChangeEvent& the_lhs, const RemoteContentProviderChangeEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Identifier == the_rhs.Identifier
        && the_lhs.Action == the_rhs.Action;
}

inline bool operator!=(const RemoteContentProviderChangeEvent& the_lhs, const RemoteContentProviderChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theRemoteContentProviderChangeEventType : public rtl::StaticWithInit< ::css::uno::Type *, theRemoteContentProviderChangeEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.RemoteContentProviderChangeEvent" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Identifier" );
        ::cppu::UnoType< ::css::ucb::RemoteContentProviderChangeAction >::get();
        ::rtl::OUString the_tname1( "com.sun.star.ucb.RemoteContentProviderChangeAction" );
        ::rtl::OUString the_name1( "Action" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::RemoteContentProviderChangeEvent const *) {
    return *detail::theRemoteContentProviderChangeEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::RemoteContentProviderChangeEvent const *) {
    return ::cppu::UnoType< ::css::ucb::RemoteContentProviderChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_REMOTECONTENTPROVIDERCHANGEEVENT_HPP
