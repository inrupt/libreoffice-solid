#ifndef INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP
#define INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/ContentProviderInfo.hdl"

#include "com/sun/star/ucb/XContentProvider.hpp"
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

inline ContentProviderInfo::ContentProviderInfo()
    : ContentProvider()
    , Scheme()
{
}

inline ContentProviderInfo::ContentProviderInfo(const ::css::uno::Reference< ::css::ucb::XContentProvider >& ContentProvider_, const ::rtl::OUString& Scheme_)
    : ContentProvider(ContentProvider_)
    , Scheme(Scheme_)
{
}


inline bool operator==(const ContentProviderInfo& the_lhs, const ContentProviderInfo& the_rhs)
{
    return the_lhs.ContentProvider == the_rhs.ContentProvider
        && the_lhs.Scheme == the_rhs.Scheme;
}

inline bool operator!=(const ContentProviderInfo& the_lhs, const ContentProviderInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theContentProviderInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theContentProviderInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.ContentProviderInfo" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::ucb::XContentProvider > >::get();
        ::rtl::OUString the_tname0( "com.sun.star.ucb.XContentProvider" );
        ::rtl::OUString the_name0( "ContentProvider" );
        ::rtl::OUString the_tname1( "string" );
        ::rtl::OUString the_name1( "Scheme" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_INTERFACE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::ContentProviderInfo const *) {
    return *detail::theContentProviderInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::ContentProviderInfo const *) {
    return ::cppu::UnoType< ::css::ucb::ContentProviderInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_CONTENTPROVIDERINFO_HPP
