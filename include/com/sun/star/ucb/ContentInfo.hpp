#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentInfo.hdl"

#include "com/sun/star/beans/Property.hpp"
#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline ContentInfo::ContentInfo()
    : Type()
    , Attributes(0)
    , Properties()
{
}

inline ContentInfo::ContentInfo(const ::rtl::OUString& Type_, const ::sal_Int32& Attributes_, const ::css::uno::Sequence< ::css::beans::Property >& Properties_)
    : Type(Type_)
    , Attributes(Attributes_)
    , Properties(Properties_)
{
}


inline bool operator==(const ContentInfo& the_lhs, const ContentInfo& the_rhs)
{
    return the_lhs.Type == the_rhs.Type
        && the_lhs.Attributes == the_rhs.Attributes
        && the_lhs.Properties == the_rhs.Properties;
}

inline bool operator!=(const ContentInfo& the_lhs, const ContentInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theContentInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theContentInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.ContentInfo" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Type" );
        ::rtl::OUString the_tname1( "long" );
        ::rtl::OUString the_name1( "Attributes" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::css::beans::Property > >::get();
        ::rtl::OUString the_tname2( "[]com.sun.star.beans.Property" );
        ::rtl::OUString the_name2( "Properties" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_LONG, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentInfo const *) {
    return *detail::theContentInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentInfo const *) {
    return ::cppu::UnoType< ::css::ucb::ContentInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTINFO_HPP
