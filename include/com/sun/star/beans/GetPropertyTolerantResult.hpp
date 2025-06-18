#ifndef INCLUDED_COM_SUN_STAR_BEANS_GETPROPERTYTOLERANTRESULT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_GETPROPERTYTOLERANTRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/GetPropertyTolerantResult.hdl"

#include "com/sun/star/beans/PropertyState.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline GetPropertyTolerantResult::GetPropertyTolerantResult()
    : Result(0)
    , State(::css::beans::PropertyState_DIRECT_VALUE)
    , Value()
{
}

inline GetPropertyTolerantResult::GetPropertyTolerantResult(const ::sal_Int16& Result_, const ::css::beans::PropertyState& State_, const ::css::uno::Any& Value_)
    : Result(Result_)
    , State(State_)
    , Value(Value_)
{
}


inline bool operator==(const GetPropertyTolerantResult& the_lhs, const GetPropertyTolerantResult& the_rhs)
{
    return the_lhs.Result == the_rhs.Result
        && the_lhs.State == the_rhs.State
        && the_lhs.Value == the_rhs.Value;
}

inline bool operator!=(const GetPropertyTolerantResult& the_lhs, const GetPropertyTolerantResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct theGetPropertyTolerantResultType : public rtl::StaticWithInit< ::css::uno::Type *, theGetPropertyTolerantResultType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.GetPropertyTolerantResult" );
        ::rtl::OUString the_tname0( "short" );
        ::rtl::OUString the_name0( "Result" );
        ::cppu::UnoType< ::css::beans::PropertyState >::get();
        ::rtl::OUString the_tname1( "com.sun.star.beans.PropertyState" );
        ::rtl::OUString the_name1( "State" );
        ::rtl::OUString the_tname2( "any" );
        ::rtl::OUString the_name2( "Value" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_SHORT, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ANY, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::GetPropertyTolerantResult const *) {
    return *detail::theGetPropertyTolerantResultType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::GetPropertyTolerantResult const *) {
    return ::cppu::UnoType< ::css::beans::GetPropertyTolerantResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_GETPROPERTYTOLERANTRESULT_HPP
