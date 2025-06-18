#ifndef INCLUDED_COM_SUN_STAR_SDBC_CHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_CHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/ChangeEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline ChangeEvent::ChangeEvent()
    : ::css::lang::EventObject()
    , Action(0)
    , Rows(0)
{
}

inline ChangeEvent::ChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::sal_Int32& Action_, const ::sal_Int32& Rows_)
    : ::css::lang::EventObject(Source_)
    , Action(Action_)
    , Rows(Rows_)
{
}


inline bool operator==(const ChangeEvent& the_lhs, const ChangeEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Action == the_rhs.Action
        && the_lhs.Rows == the_rhs.Rows;
}

inline bool operator!=(const ChangeEvent& the_lhs, const ChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theChangeEventType : public rtl::StaticWithInit< ::css::uno::Type *, theChangeEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.sdbc.ChangeEvent" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "Action" );
        ::rtl::OUString the_name1( "Rows" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::ChangeEvent const *) {
    return *detail::theChangeEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::ChangeEvent const *) {
    return ::cppu::UnoType< ::css::sdbc::ChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_CHANGEEVENT_HPP
