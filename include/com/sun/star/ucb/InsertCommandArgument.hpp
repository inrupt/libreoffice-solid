#ifndef INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT_HPP
#define INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/InsertCommandArgument.hdl"

#include "com/sun/star/io/XInputStream.hpp"
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

inline InsertCommandArgument::InsertCommandArgument()
    : Data()
    , ReplaceExisting(false)
{
}

inline InsertCommandArgument::InsertCommandArgument(const ::css::uno::Reference< ::css::io::XInputStream >& Data_, const ::sal_Bool& ReplaceExisting_)
    : Data(Data_)
    , ReplaceExisting(ReplaceExisting_)
{
}


inline bool operator==(const InsertCommandArgument& the_lhs, const InsertCommandArgument& the_rhs)
{
    return the_lhs.Data == the_rhs.Data
        && the_lhs.ReplaceExisting == the_rhs.ReplaceExisting;
}

inline bool operator!=(const InsertCommandArgument& the_lhs, const InsertCommandArgument& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct theInsertCommandArgumentType : public rtl::StaticWithInit< ::css::uno::Type *, theInsertCommandArgumentType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.InsertCommandArgument" );
        ::cppu::UnoType< ::css::uno::Reference< ::css::io::XInputStream > >::get();
        ::rtl::OUString the_tname0( "com.sun.star.io.XInputStream" );
        ::rtl::OUString the_name0( "Data" );
        ::rtl::OUString the_tname1( "boolean" );
        ::rtl::OUString the_name1( "ReplaceExisting" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_INTERFACE, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_BOOLEAN, the_tname1.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::InsertCommandArgument const *) {
    return *detail::theInsertCommandArgumentType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::InsertCommandArgument const *) {
    return ::cppu::UnoType< ::css::ucb::InsertCommandArgument >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_INSERTCOMMANDARGUMENT_HPP
