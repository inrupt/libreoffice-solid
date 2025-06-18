#ifndef INCLUDED_COM_SUN_STAR_BEANS_AMBIGUOUS_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_AMBIGUOUS_HPP

#include "sal/config.h"

#include "com/sun/star/beans/Ambiguous.hdl"

#include "com/sun/star/uno/Type.hxx"
#include "cppu/unotype.hxx"
#include "rtl/string.h"
#include "rtl/ustrbuf.hxx"
#include "rtl/ustring.h"
#include "rtl/ustring.hxx"
#include "rtl/instance.hxx"
#include "sal/types.h"
#include "typelib/typeclass.h"
#include "typelib/typedescription.h"

namespace com { namespace sun { namespace star { namespace beans {

template< typename typeparam_T > inline Ambiguous< typeparam_T >::Ambiguous()
    : Value()
    , IsAmbiguous(false)
{
}

template< typename typeparam_T > inline Ambiguous< typeparam_T >::Ambiguous(typeparam_T const & Value_, const ::sal_Bool& IsAmbiguous_)
    : Value(Value_)
    , IsAmbiguous(IsAmbiguous_)
{
}

template< typename typeparam_T > 
inline Ambiguous< typeparam_T >
make_Ambiguous(typeparam_T const & Value_, const ::sal_Bool& IsAmbiguous_)
{
    return Ambiguous< typeparam_T >(Value_, IsAmbiguous_);
}

template< typename typeparam_T >  inline bool operator==(const Ambiguous< typeparam_T >& the_lhs, const Ambiguous< typeparam_T >& the_rhs)
{
    return the_lhs.Value == the_rhs.Value
        && the_lhs.IsAmbiguous == the_rhs.IsAmbiguous;
}
template< typename typeparam_T >  inline bool operator!=(const Ambiguous< typeparam_T >& the_lhs, const Ambiguous< typeparam_T >& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace cppu {  namespace detail {

template< typename typeparam_T > struct theAmbiguousType : public rtl::StaticWithInit< ::css::uno::Type *, theAmbiguousType< typeparam_T > >
{
    ::css::uno::Type * operator()() const
    {
#ifdef LIBO_INTERNAL_ONLY
        ::rtl::OUString the_name =
        "com.sun.star.beans.Ambiguous<" +
        ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName() +
        ">";
#else
        ::rtl::OUStringBuffer the_buffer;
        the_buffer.append("com.sun.star.beans.Ambiguous<");
        the_buffer.append(::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName());
        the_buffer.append(static_cast< ::sal_Unicode >('>'));
        ::rtl::OUString the_name(the_buffer.makeStringAndClear());
#endif
        ::css::uno::Type const & the_ptype0 = ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0));
        ::typelib_TypeClass the_pclass0 = (::typelib_TypeClass) the_ptype0.getTypeClass();
        ::rtl::OUString the_pname0(the_ptype0.getTypeName());
        ::rtl::OUString the_name0( "Value" );
        ::rtl::OUString the_tname0( "boolean" );
        ::rtl::OUString the_name1( "IsAmbiguous" );
        ::typelib_StructMember_Init the_members[] = {
            { { the_pclass0, the_pname0.pData, the_name0.pData }, true },
            { { typelib_TypeClass_BOOLEAN, the_tname0.pData, the_name1.pData }, false } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
 } }

namespace cppu {

template< typename typeparam_T > class UnoType< ::css::beans::Ambiguous< typeparam_T > > {
public:
    static inline ::css::uno::Type const & get() {
        return *detail::theAmbiguousType< typeparam_T >::get();
    }

private:
    UnoType(UnoType &); // not defined
    ~UnoType(); // not defined
    void operator =(UnoType); // not defined
};

}

template< typename typeparam_T > SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::Ambiguous< typeparam_T > const *) {
        return ::cppu::UnoType< ::css::beans::Ambiguous< typeparam_T > >::get();
    }

#endif // INCLUDED_COM_SUN_STAR_BEANS_AMBIGUOUS_HPP
