#ifndef INCLUDED_COM_SUN_STAR_UTIL_SORTFIELD_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_SORTFIELD_HPP

#include "sal/config.h"

#include "com/sun/star/util/SortField.hdl"

#include "com/sun/star/util/SortFieldType.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline SortField::SortField()
    : Field(0)
    , SortAscending(false)
    , FieldType(::css::util::SortFieldType_AUTOMATIC)
{
}

inline SortField::SortField(const ::sal_Int32& Field_, const ::sal_Bool& SortAscending_, const ::css::util::SortFieldType& FieldType_)
    : Field(Field_)
    , SortAscending(SortAscending_)
    , FieldType(FieldType_)
{
}


inline bool operator==(const SortField& the_lhs, const SortField& the_rhs)
{
    return the_lhs.Field == the_rhs.Field
        && the_lhs.SortAscending == the_rhs.SortAscending
        && the_lhs.FieldType == the_rhs.FieldType;
}

inline bool operator!=(const SortField& the_lhs, const SortField& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theSortFieldType : public rtl::StaticWithInit< ::css::uno::Type *, theSortFieldType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.SortField" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "Field" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "SortAscending" );
        ::cppu::UnoType< ::css::util::SortFieldType >::get();
        ::rtl::OUString the_tname2( "com.sun.star.util.SortFieldType" );
        ::rtl::OUString the_name2( "FieldType" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ENUM, the_tname2.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::SortField const *) {
    return *detail::theSortFieldType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::SortField const *) {
    return ::cppu::UnoType< ::css::util::SortField >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_SORTFIELD_HPP
