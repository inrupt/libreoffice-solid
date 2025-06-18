#ifndef INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUEINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUEINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PropertyValueInfo.hdl"

#include "com/sun/star/beans/PropertyValue.hpp"
#include "com/sun/star/ucb/PropertyValueState.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PropertyValueInfo::PropertyValueInfo()
    : ::css::beans::PropertyValue()
    , ValueState(::css::ucb::PropertyValueState_UNPROCESSED)
{
}

inline PropertyValueInfo::PropertyValueInfo(const ::rtl::OUString& Name_, const ::sal_Int32& Handle_, const ::css::uno::Any& Value_, const ::css::beans::PropertyState& State_, const ::css::ucb::PropertyValueState& ValueState_)
    : ::css::beans::PropertyValue(Name_, Handle_, Value_, State_)
    , ValueState(ValueState_)
{
}


inline bool operator==(const PropertyValueInfo& the_lhs, const PropertyValueInfo& the_rhs)
{
    return operator==( static_cast<const ::css::beans::PropertyValue&>(the_lhs), static_cast<const ::css::beans::PropertyValue&>(the_rhs) )

        && the_lhs.ValueState == the_rhs.ValueState;
}

inline bool operator!=(const PropertyValueInfo& the_lhs, const PropertyValueInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct thePropertyValueInfoType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyValueInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.PropertyValueInfo" );
        ::cppu::UnoType< ::css::ucb::PropertyValueState >::get();
        ::rtl::OUString the_tname0( "com.sun.star.ucb.PropertyValueState" );
        ::rtl::OUString the_name0( "ValueState" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ENUM, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::beans::PropertyValue >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyValueInfo const *) {
    return *detail::thePropertyValueInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyValueInfo const *) {
    return ::cppu::UnoType< ::css::ucb::PropertyValueInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_PROPERTYVALUEINFO_HPP
