#ifndef INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSETINFOCHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSETINFOCHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/PropertySetInfoChangeEvent.hdl"

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

inline PropertySetInfoChangeEvent::PropertySetInfoChangeEvent()
    : ::css::lang::EventObject()
    , Name()
    , Handle(0)
    , Reason(0)
{
}

inline PropertySetInfoChangeEvent::PropertySetInfoChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& Name_, const ::sal_Int32& Handle_, const ::sal_Int32& Reason_)
    : ::css::lang::EventObject(Source_)
    , Name(Name_)
    , Handle(Handle_)
    , Reason(Reason_)
{
}


inline bool operator==(const PropertySetInfoChangeEvent& the_lhs, const PropertySetInfoChangeEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Name == the_rhs.Name
        && the_lhs.Handle == the_rhs.Handle
        && the_lhs.Reason == the_rhs.Reason;
}

inline bool operator!=(const PropertySetInfoChangeEvent& the_lhs, const PropertySetInfoChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct thePropertySetInfoChangeEventType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertySetInfoChangeEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.PropertySetInfoChangeEvent" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "Handle" );
        ::rtl::OUString the_name2( "Reason" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::PropertySetInfoChangeEvent const *) {
    return *detail::thePropertySetInfoChangeEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::PropertySetInfoChangeEvent const *) {
    return ::cppu::UnoType< ::css::beans::PropertySetInfoChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_PROPERTYSETINFOCHANGEEVENT_HPP
