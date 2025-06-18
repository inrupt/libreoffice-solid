#ifndef INCLUDED_COM_SUN_STAR_UTIL_ELEMENTCHANGE_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_ELEMENTCHANGE_HPP

#include "sal/config.h"

#include "com/sun/star/util/ElementChange.hdl"

#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline ElementChange::ElementChange()
    : Accessor()
    , Element()
    , ReplacedElement()
{
}

inline ElementChange::ElementChange(const ::css::uno::Any& Accessor_, const ::css::uno::Any& Element_, const ::css::uno::Any& ReplacedElement_)
    : Accessor(Accessor_)
    , Element(Element_)
    , ReplacedElement(ReplacedElement_)
{
}


inline bool operator==(const ElementChange& the_lhs, const ElementChange& the_rhs)
{
    return the_lhs.Accessor == the_rhs.Accessor
        && the_lhs.Element == the_rhs.Element
        && the_lhs.ReplacedElement == the_rhs.ReplacedElement;
}

inline bool operator!=(const ElementChange& the_lhs, const ElementChange& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theElementChangeType : public rtl::StaticWithInit< ::css::uno::Type *, theElementChangeType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.ElementChange" );
        ::rtl::OUString the_tname0( "any" );
        ::rtl::OUString the_name0( "Accessor" );
        ::rtl::OUString the_name1( "Element" );
        ::rtl::OUString the_name2( "ReplacedElement" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::ElementChange const *) {
    return *detail::theElementChangeType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::ElementChange const *) {
    return ::cppu::UnoType< ::css::util::ElementChange >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_ELEMENTCHANGE_HPP
