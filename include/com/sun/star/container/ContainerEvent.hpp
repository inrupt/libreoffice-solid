#ifndef INCLUDED_COM_SUN_STAR_CONTAINER_CONTAINEREVENT_HPP
#define INCLUDED_COM_SUN_STAR_CONTAINER_CONTAINEREVENT_HPP

#include "sal/config.h"

#include "com/sun/star/container/ContainerEvent.hdl"

#include "com/sun/star/lang/EventObject.hpp"
#include "com/sun/star/uno/Any.hxx"
#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace container {

inline ContainerEvent::ContainerEvent()
    : ::css::lang::EventObject()
    , Accessor()
    , Element()
    , ReplacedElement()
{
}

inline ContainerEvent::ContainerEvent(const ::css::uno::Reference< ::css::uno::XInterface >& Source_, const ::css::uno::Any& Accessor_, const ::css::uno::Any& Element_, const ::css::uno::Any& ReplacedElement_)
    : ::css::lang::EventObject(Source_)
    , Accessor(Accessor_)
    , Element(Element_)
    , ReplacedElement(ReplacedElement_)
{
}


inline bool operator==(const ContainerEvent& the_lhs, const ContainerEvent& the_rhs)
{
    return operator==( static_cast<const ::css::lang::EventObject&>(the_lhs), static_cast<const ::css::lang::EventObject&>(the_rhs) )

        && the_lhs.Accessor == the_rhs.Accessor
        && the_lhs.Element == the_rhs.Element
        && the_lhs.ReplacedElement == the_rhs.ReplacedElement;
}

inline bool operator!=(const ContainerEvent& the_lhs, const ContainerEvent& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace com { namespace sun { namespace star { namespace container { namespace detail {

struct theContainerEventType : public rtl::StaticWithInit< ::css::uno::Type *, theContainerEventType >
{
    ::css::uno::Type * operator()() const
    {
        ::rtl::OUString the_name( "com.sun.star.container.ContainerEvent" );
        ::rtl::OUString the_tname0( "any" );
        ::rtl::OUString the_name0( "Accessor" );
        ::rtl::OUString the_name1( "Element" );
        ::rtl::OUString the_name2( "ReplacedElement" );
        ::typelib_StructMember_Init the_members[] = {
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name0.pData }, false },
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name1.pData }, false },
            { { typelib_TypeClass_ANY, the_tname0.pData, the_name2.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, ::cppu::UnoType< ::css::lang::EventObject >::get().getTypeLibType(), 3, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
} } } } }

namespace com { namespace sun { namespace star { namespace container {

inline ::css::uno::Type const & cppu_detail_getUnoType(SAL_UNUSED_PARAMETER ::css::container::ContainerEvent const *) {
    return *detail::theContainerEventType::get();
}

} } } }

SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::container::ContainerEvent const *) {
    return ::cppu::UnoType< ::css::container::ContainerEvent >::get();
}

#endif // INCLUDED_COM_SUN_STAR_CONTAINER_CONTAINEREVENT_HPP
