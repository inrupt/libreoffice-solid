#ifndef INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/util/DataEditorEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/util/DataEditorEventType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline DataEditorEvent::DataEditorEvent()
    : ::css::lang::EventObject()
    , Type(::css::util::DataEditorEventType_DONE)
{
}

inline DataEditorEvent::DataEditorEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::util::DataEditorEventType& Type_)
    : ::css::lang::EventObject(Source_)
    , Type(Type_)
{
}


inline bool operator==(const DataEditorEvent& the_lhs, const DataEditorEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Type == the_rhs.Type;
}

inline bool operator!=(const DataEditorEvent& the_lhs, const DataEditorEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theDataEditorEventType : public rtl::StaticWithInit< ::css::uno::Type *, theDataEditorEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.DataEditorEvent" );
        ::cppu::UnoType< ::css::util::DataEditorEventType >::get();
        ::rtl::OUString the_tname0( "com.sun.star.util.DataEditorEventType" );
        ::rtl::OUString the_name0( "Type" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::DataEditorEvent const *) {
    return *detail::theDataEditorEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::DataEditorEvent const *) {
    return ::cppu::UnoType< ::css::util::DataEditorEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_DATAEDITOREVENT_HPP
