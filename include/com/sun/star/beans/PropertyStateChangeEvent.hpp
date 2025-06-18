#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATECHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATECHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertyStateChangeEvent.hdl"

#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline PropertyStateChangeEvent::PropertyStateChangeEvent()
    : ::css::lang::EventObject()
    , PropertyName()
    , PropertyHandle(0)
    , OldValue(::css::beans::PropertyState_DIRECT_VALUE)
    , NewValue(::css::beans::PropertyState_DIRECT_VALUE)
{
}

inline PropertyStateChangeEvent::PropertyStateChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& PropertyName_, const ::sal_Int32& PropertyHandle_, const ::css::beans::PropertyState& OldValue_, const ::css::beans::PropertyState& NewValue_)
    : ::css::lang::EventObject(Source_)
    , PropertyName(PropertyName_)
    , PropertyHandle(PropertyHandle_)
    , OldValue(OldValue_)
    , NewValue(NewValue_)
{
}


inline bool operator==(const PropertyStateChangeEvent& the_lhs, const PropertyStateChangeEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.PropertyName == the_rhs.PropertyName
        && the_lhs.PropertyHandle == the_rhs.PropertyHandle
        && the_lhs.OldValue == the_rhs.OldValue
        && the_lhs.NewValue == the_rhs.NewValue;
}

inline bool operator!=(const PropertyStateChangeEvent& the_lhs, const PropertyStateChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct thePropertyStateChangeEventType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyStateChangeEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.PropertyStateChangeEvent" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "PropertyName" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "PropertyHandle" );
        ::cppu::UnoType< ::css::beans::PropertyState >::get();
        ::rtl::OUString the_tname2( "com.sun.star.beans.PropertyState" );
        ::rtl::OUString the_name2( "OldValue" );
        ::rtl::OUString the_name3( "NewValue" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname2.pData, the_name2.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname2.pData, the_name3.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 4, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertyStateChangeEvent const *) {
    return *detail::thePropertyStateChangeEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertyStateChangeEvent const *) {
    return ::cppu::UnoType< ::css::beans::PropertyStateChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSTATECHANGEEVENT_HPP
