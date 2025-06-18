#ifndef INCLUDED_COM_SUN_STAR_BEANS_SETPROPERTYTOLERANTFAILED_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_SETPROPERTYTOLERANTFAILED_HPP

#include "sal/config.h"

#include "com/sun/star/beans/SetPropertyTolerantFailed.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

inline SetPropertyTolerantFailed::SetPropertyTolerantFailed()
    : Name()
    , Result(0)
{
}

inline SetPropertyTolerantFailed::SetPropertyTolerantFailed(const ::rtl::OUString& Name_, const ::sal_Int16& Result_)
    : Name(Name_)
    , Result(Result_)
{
}


inline bool operator==(const SetPropertyTolerantFailed& the_lhs, const SetPropertyTolerantFailed& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Result == the_rhs.Result;
}

inline bool operator!=(const SetPropertyTolerantFailed& the_lhs, const SetPropertyTolerantFailed& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace beans { namespace detail {

struct theSetPropertyTolerantFailedType : public rtl::StaticWithInit< ::css::uno::Type *, theSetPropertyTolerantFailedType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.beans.SetPropertyTolerantFailed" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::rtl::OUString the_tname1( "short" );
        ::rtl::OUString the_name1( "Result" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_SHORT, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace beans {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::beans::SetPropertyTolerantFailed const *) {
    return *detail::theSetPropertyTolerantFailedType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::SetPropertyTolerantFailed const *) {
    return ::cppu::UnoType< ::css::beans::SetPropertyTolerantFailed >::get();
}

#endif // INCLUDED_COM_SUN_STAR_BEANS_SETPROPERTYTOLERANTFAILED_HPP
