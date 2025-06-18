#ifndef INCLUDED_COM_SUN_STAR_UCB_PROPERTYCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_PROPERTYCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PropertyCommandArgument.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PropertyCommandArgument::PropertyCommandArgument()
    : Property()
    , DefaultValue()
{
}

inline PropertyCommandArgument::PropertyCommandArgument(const ::css::beans::Property& Property_, const ::css::uno::Any& DefaultValue_)
    : Property(Property_)
    , DefaultValue(DefaultValue_)
{
}


inline bool operator==(const PropertyCommandArgument& the_lhs, const PropertyCommandArgument& the_rhs)
{
    return the_lhs.Property == the_rhs.Property
        && the_lhs.DefaultValue == the_rhs.DefaultValue;
}

inline bool operator!=(const PropertyCommandArgument& the_lhs, const PropertyCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct thePropertyCommandArgumentType : public rtl::StaticWithInit< ::css::uno::Type *, thePropertyCommandArgumentType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.PropertyCommandArgument" );
        ::cppu::UnoType< ::css::beans::Property >::get();
        ::rtl::OUString the_tname0( "com.sun.star.beans.Property" );
        ::rtl::OUString the_name0( "Property" );
        ::rtl::OUString the_tname1( "any" );
        ::rtl::OUString the_name1( "DefaultValue" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRUCT, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ANY, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyCommandArgument const *) {
    return *detail::thePropertyCommandArgumentType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PropertyCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::PropertyCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_PROPERTYCOMMANDARGUMENT_HPP
