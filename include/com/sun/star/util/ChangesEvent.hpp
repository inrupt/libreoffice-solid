#ifndef INCLUDED_COM_SUN_STAR_UTIL_CHANGESEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_CHANGESEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/util/ChangesEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/util/ChangesSet.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline ChangesEvent::ChangesEvent()
    : ::css::lang::EventObject()
    , Base()
    , Changes()
{
}

inline ChangesEvent::ChangesEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& Base_, const ::css::uno::Sequence< ::css::util::ElementChange >& Changes_)
    : ::css::lang::EventObject(Source_)
    , Base(Base_)
    , Changes(Changes_)
{
}


inline bool operator==(const ChangesEvent& the_lhs, const ChangesEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Base == the_rhs.Base
        && the_lhs.Changes == the_rhs.Changes;
}

inline bool operator!=(const ChangesEvent& the_lhs, const ChangesEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theChangesEventType : public rtl::StaticWithInit< ::css::uno::Type *, theChangesEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.ChangesEvent" );
        ::rtl::OUString the_tname0( "any" );
        ::rtl::OUString the_name0( "Base" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::util::ElementChange > >::get();
        ::rtl::OUString the_tname1( "[]com.sun.star.util.ElementChange" );
        ::rtl::OUString the_name1( "Changes" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::ChangesEvent const *) {
    return *detail::theChangesEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::ChangesEvent const *) {
    return ::cppu::UnoType< ::css::util::ChangesEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_CHANGESEVENT_HPP
