#ifndef INCLUDED_COM_SUN_STAR_UTIL_ATOMCLASSREQUEST_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_ATOMCLASSREQUEST_HPP

#include "sal/config.h"

#include "com/sun/star/util/AtomClassRequest.hdl"

#include "com/sun/star/uno/Sequence.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline AtomClassRequest::AtomClassRequest()
    : atomClass(0)
    , atoms()
{
}

inline AtomClassRequest::AtomClassRequest(const ::sal_Int32& atomClass_, const ::css::uno::Sequence< ::sal_Int32 >& atoms_)
    : atomClass(atomClass_)
    , atoms(atoms_)
{
}


inline bool operator==(const AtomClassRequest& the_lhs, const AtomClassRequest& the_rhs)
{
    return the_lhs.atomClass == the_rhs.atomClass
        && the_lhs.atoms == the_rhs.atoms;
}

inline bool operator!=(const AtomClassRequest& the_lhs, const AtomClassRequest& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theAtomClassRequestType : public rtl::StaticWithInit< ::css::uno::Type *, theAtomClassRequestType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.AtomClassRequest" );
        ::rtl::OUString the_tname0( "long" );
        ::rtl::OUString the_name0( "atomClass" );
        ::cppu::UnoType< ::cppu::UnoSequenceType< ::sal_Int32 > >::get();
        ::rtl::OUString the_tname1( "[]long" );
        ::rtl::OUString the_name1( "atoms" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_LONG, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_SEQUENCE, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::AtomClassRequest const *) {
    return *detail::theAtomClassRequestType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::AtomClassRequest const *) {
    return ::cppu::UnoType< ::css::util::AtomClassRequest >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_ATOMCLASSREQUEST_HPP
