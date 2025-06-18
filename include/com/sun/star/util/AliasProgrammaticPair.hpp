#ifndef INCLUDED_COM_SUN_STAR_UTIL_ALIASPROGRAMMATICPAIR_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_ALIASPROGRAMMATICPAIR_HPP

#include "sal/config.h"

#include "com/sun/star/util/AliasProgrammaticPair.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline AliasProgrammaticPair::AliasProgrammaticPair()
    : Alias()
    , ProgrammaticName()
{
}

inline AliasProgrammaticPair::AliasProgrammaticPair(const ::rtl::OUString& Alias_, const ::rtl::OUString& ProgrammaticName_)
    : Alias(Alias_)
    , ProgrammaticName(ProgrammaticName_)
{
}


inline bool operator==(const AliasProgrammaticPair& the_lhs, const AliasProgrammaticPair& the_rhs)
{
    return the_lhs.Alias == the_rhs.Alias
        && the_lhs.ProgrammaticName == the_rhs.ProgrammaticName;
}

inline bool operator!=(const AliasProgrammaticPair& the_lhs, const AliasProgrammaticPair& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theAliasProgrammaticPairType : public rtl::StaticWithInit< ::css::uno::Type *, theAliasProgrammaticPairType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.AliasProgrammaticPair" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "Alias" );
        ::rtl::OUString the_name1( "ProgrammaticName" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::AliasProgrammaticPair const *) {
    return *detail::theAliasProgrammaticPairType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::AliasProgrammaticPair const *) {
    return ::cppu::UnoType< ::css::util::AliasProgrammaticPair >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_ALIASPROGRAMMATICPAIR_HPP
