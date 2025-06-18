#ifndef INCLUDED_COM_SUN_STAR_UCB_WELCOMEDYNAMICRESULTSETSTRUCT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_WELCOMEDYNAMICRESULTSETSTRUCT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/WelcomeDynamicResultSetStruct.hdl"

#include "com/sun/star/sdbc/XResultSet.hpp"
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

inline WelcomeDynamicResultSetStruct::WelcomeDynamicResultSetStruct()
    : Old()
    , New()
{
}

inline WelcomeDynamicResultSetStruct::WelcomeDynamicResultSetStruct(const ::css::uno::Reference< ::css::sdbc::XResultSet >& Old_, const ::css::uno::Reference< ::css::sdbc::XResultSet >& New_)
    : Old(Old_)
    , New(New_)
{
}


inline bool operator==(const WelcomeDynamicResultSetStruct& the_lhs, const WelcomeDynamicResultSetStruct& the_rhs)
{
    return the_lhs.Old == the_rhs.Old
        && the_lhs.New == the_rhs.New;
}

inline bool operator!=(const WelcomeDynamicResultSetStruct& the_lhs, const WelcomeDynamicResultSetStruct& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theWelcomeDynamicResultSetStructType : public rtl::StaticWithInit< ::css::uno::Type *, theWelcomeDynamicResultSetStructType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.WelcomeDynamicResultSetStruct" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::sdbc::XResultSet > >::get();
        ::rtl::OUString the_tname0( "com.sun.star.sdbc.XResultSet" );
        ::rtl::OUString the_name0( "Old" );
        ::rtl::OUString the_name1( "New" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_INTERFACE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_INTERFACE, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::WelcomeDynamicResultSetStruct const *) {
    return *detail::theWelcomeDynamicResultSetStructType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::WelcomeDynamicResultSetStruct const *) {
    return ::cppu::UnoType< ::css::ucb::WelcomeDynamicResultSetStruct >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_WELCOMEDYNAMICRESULTSETSTRUCT_HPP
