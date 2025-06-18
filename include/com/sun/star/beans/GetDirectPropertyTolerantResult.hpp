#ifndef INCLUDED_COM_SUN_STAR_BEANS_GETDIRECTPROPERTYTOLERANTRESULT_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_GETDIRECTPROPERTYTOLERANTRESULT_HPP

#include "sal/config.h"

#include "com/sun/star/beans/GetDirectPropertyTolerantResult.hdl"

#include "com/sun/star/beans/GetPropertyTolerantResult.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline GetDirectPropertyTolerantResult::GetDirectPropertyTolerantResult()
    : ::css::beans::GetPropertyTolerantResult()
    , Name()
{
}

inline GetDirectPropertyTolerantResult::GetDirectPropertyTolerantResult(const ::sal_Int16& Result_, const ::css::beans::PropertyState& State_, const ::css::uno::Any& Value_, const ::rtl::OUString& Name_)
    : ::css::beans::GetPropertyTolerantResult(Result_, State_, Value_)
    , Name(Name_)
{
}


inline bool operator==(const GetDirectPropertyTolerantResult& the_lhs, const GetDirectPropertyTolerantResult& the_rhs)
{
    return operator==( static_cast<const ::css::beans::GetPropertyTolerantResult&>(the_lhs), static_cast<const ::css::beans::GetPropertyTolerantResult&>(the_rhs) )

        && the_lhs.Name == the_rhs.Name;
}

inline bool operator!=(const GetDirectPropertyTolerantResult& the_lhs, const GetDirectPropertyTolerantResult& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct theGetDirectPropertyTolerantResultType : public rtl::StaticWithInit< ::css::uno::Type *, theGetDirectPropertyTolerantResultType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.GetDirectPropertyTolerantResult" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::beans::GetPropertyTolerantResult >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::GetDirectPropertyTolerantResult const *) {
    return *detail::theGetDirectPropertyTolerantResultType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::GetDirectPropertyTolerantResult const *) {
    return ::cppu::UnoType< ::css::beans::GetDirectPropertyTolerantResult >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_GETDIRECTPROPERTYTOLERANTRESULT_HPP
