#ifndef INCLUDED_COM_SUN_STAR_UTIL_ATOMDESCRIPTION_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_ATOMDESCRIPTION_HPP

#include "sal/config.h"

#include "com/sun/star/util/AtomDescription.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline AtomDescription::AtomDescription()
    : atom(0)
    , description()
{
}

inline AtomDescription::AtomDescription(const ::sal_Int32& atom_, const ::rtl::OUString& description_)
    : atom(atom_)
    , description(description_)
{
}


inline bool operator==(const AtomDescription& the_lhs, const AtomDescription& the_rhs)
{
    return the_lhs.atom == the_rhs.atom
        && the_lhs.description == the_rhs.description;
}

inline bool operator!=(const AtomDescription& the_lhs, const AtomDescription& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theAtomDescriptionType : public rtl::StaticWithInit< ::css::uno::Type *, theAtomDescriptionType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.AtomDescription" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "atom" );
        ::rtl::OUString the_tname1( "string" );
        ::rtl::OUString the_name1( "description" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::AtomDescription const *) {
    return *detail::theAtomDescriptionType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::AtomDescription const *) {
    return ::cppu::UnoType< ::css::util::AtomDescription >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_ATOMDESCRIPTION_HPP
