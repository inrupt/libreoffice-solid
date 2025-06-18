#ifndef INCLUDED_COM_SUN_STAR_SDBC_DRIVERPROPERTYINFO_HPP
#define INCLUDED_COM_SUN_STAR_SDBC_DRIVERPROPERTYINFO_HPP

#include "sal/config.h"

#include "com/sun/star/sdbc/DriverPropertyInfo.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace sdbc {

inline DriverPropertyInfo::DriverPropertyInfo()
    : Name()
    , Description()
    , IsRequired(false)
    , Value()
    , Choices()
{
}

inline DriverPropertyInfo::DriverPropertyInfo(const ::rtl::OUString& Name_, const ::rtl::OUString& Description_, const ::sal_Bool& IsRequired_, const ::rtl::OUString& Value_, const ::css::uno::Sequence< ::rtl::OUString >& Choices_)
    : Name(Name_)
    , Description(Description_)
    , IsRequired(IsRequired_)
    , Value(Value_)
    , Choices(Choices_)
{
}


inline bool operator==(const DriverPropertyInfo& the_lhs, const DriverPropertyInfo& the_rhs)
{
    return the_lhs.Name == the_rhs.Name
        && the_lhs.Description == the_rhs.Description
        && the_lhs.IsRequired == the_rhs.IsRequired
        && the_lhs.Value == the_rhs.Value
        && the_lhs.Choices == the_rhs.Choices;
}

inline bool operator!=(const DriverPropertyInfo& the_lhs, const DriverPropertyInfo& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace sdbc { namespace detail {

struct theDriverPropertyInfoType : public rtl::StaticWithInit< ::css::uno::Type *, theDriverPropertyInfoType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.sdbc.DriverPropertyInfo" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Name" );
        ::rtl::OUString the_name1( "Description" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name2( "IsRequired" );
        ::rtl::OUString the_name3( "Value" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::rtl::OUString > >::get();
        ::rtl::OUString the_tname2( "[]string" );
        ::rtl::OUString the_name4( "Choices" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name2.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name3.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname2.pData, the_name4.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 5, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace sdbc {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::sdbc::DriverPropertyInfo const *) {
    return *detail::theDriverPropertyInfoType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::sdbc::DriverPropertyInfo const *) {
    return ::cppu::UnoType< ::css::sdbc::DriverPropertyInfo >::get();
}

#endif // INCLUDED_COM_SUN_STAR_SDBC_DRIVERPROPERTYINFO_HPP
