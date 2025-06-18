#ifndef INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT2_HPP
#define INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT2_HPP

#include "sal/config.h"

#include "com/sun/star/ucb/PostCommandArgument2.hdl"

#include "com/sun/star/ucb/PostCommandArgument.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace ucb {

inline PostCommandArgument2::PostCommandArgument2()
    : ::css::ucb::PostCommandArgument()
    , MediaType()
    , Referer()
{
}

inline PostCommandArgument2::PostCommandArgument2(const ::css::uno::Reference< ::css::io::XInputStream >& Source_, const ::css::uno::Reference< ::css::uno::XInterface >& Sink_, const ::rtl::OUString& MediaType_, const ::rtl::OUString& Referer_)
    : ::css::ucb::PostCommandArgument(Source_, Sink_)
    , MediaType(MediaType_)
    , Referer(Referer_)
{
}


inline bool operator==(const PostCommandArgument2& the_lhs, const PostCommandArgument2& the_rhs)
{
    return operator==( static_cast<const ::css::ucb::PostCommandArgument&>(the_lhs), static_cast<const ::css::ucb::PostCommandArgument&>(the_rhs) )

        && the_lhs.MediaType == the_rhs.MediaType
        && the_lhs.Referer == the_rhs.Referer;
}

inline bool operator!=(const PostCommandArgument2& the_lhs, const PostCommandArgument2& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace ucb { namespace detail {

struct thePostCommandArgument2Type : public rtl::StaticWithInit< ::css::uno::Type *, thePostCommandArgument2Type >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.ucb.PostCommandArgument2" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "MediaType" );
        ::rtl::OUString the_name1( "Referer" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::ucb::PostCommandArgument >::get().getTypeLibType(), 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace ucb {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::ucb::PostCommandArgument2 const *) {
    return *detail::thePostCommandArgument2Type::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::ucb::PostCommandArgument2 const *) {
    return ::cppu::UnoType< ::css::ucb::PostCommandArgument2 >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UCB_POSTCOMMANDARGUMENT2_HPP
