#ifndef INCLUDED_COM_SUN_STAR_UTIL_MODECHANGEEVENT_HPP
#define INCLUDED_COM_SUN_STAR_UTIL_MODECHANGEEVENT_HPP

#include "sal/config.h"

#include "com/sun/star/util/ModeChangeEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace util {

inline ModeChangeEvent::ModeChangeEvent()
    : ::css::lang::EventObject()
    , NewMode()
{
}

inline ModeChangeEvent::ModeChangeEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::rtl::OUString& NewMode_)
    : ::css::lang::EventObject(Source_)
    , NewMode(NewMode_)
{
}


inline bool operator==(const ModeChangeEvent& the_lhs, const ModeChangeEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.NewMode == the_rhs.NewMode;
}

inline bool operator!=(const ModeChangeEvent& the_lhs, const ModeChangeEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace util { namespace detail {

struct theModeChangeEventType : public rtl::StaticWithInit< ::css::uno::Type *, theModeChangeEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.util.ModeChangeEvent" );
        ::rtl::OUString the_tname0( "string" );
        ::rtl::OUString the_name0( "NewMode" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_STRING, the_tname0.pData, the_name0.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 1, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace util {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::util::ModeChangeEvent const *) {
    return *detail::theModeChangeEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::util::ModeChangeEvent const *) {
    return ::cppu::UnoType< ::css::util::ModeChangeEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_UTIL_MODECHANGEEVENT_HPP
