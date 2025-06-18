#ifndef INCLUDED_COM_SUN_STAR_BEANS_PAIR_HPP
#define INCLUDED_COM_SUN_STAR_BEANS_PAIR_HPP

#include "sal/config.h"

#include "com/sun/star/beans/Pair.hdl"

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

template< typename typeparam_T, typename typeparam_U > inline Pair< typeparam_T, typeparam_U >::Pair()
    : First()
    , Second()
{
}

template< typename typeparam_T, typename typeparam_U > inline Pair< typeparam_T, typeparam_U >::Pair(typeparam_T const & First_, typeparam_U const & Second_)
    : First(First_)
    , Second(Second_)
{
}

template< typename typeparam_T, typename typeparam_U > 
inline Pair< typeparam_T, typeparam_U >
make_Pair(typeparam_T const & First_, typeparam_U const & Second_)
{
    return Pair< typeparam_T, typeparam_U >(First_, Second_);
}

template< typename typeparam_T, typename typeparam_U >  inline bool operator==(const Pair< typeparam_T, typeparam_U >& the_lhs, const Pair< typeparam_T, typeparam_U >& the_rhs)
{
    return the_lhs.First == the_rhs.First
        && the_lhs.Second == the_rhs.Second;
}
template< typename typeparam_T, typename typeparam_U >  inline bool operator!=(const Pair< typeparam_T, typeparam_U >& the_lhs, const Pair< typeparam_T, typeparam_U >& the_rhs)
{
return !operator==(the_lhs, the_rhs);
}
} } } }

namespace cppu {  namespace detail {

template< typename typeparam_T, typename typeparam_U > struct thePairType : public rtl::StaticWithInit< ::css::uno::Type *, thePairType< typeparam_T, typeparam_U > >
{
    ::css::uno::Type * operator()() const
    {
#ifdef LIBO_INTERNAL_ONLY
        ::rtl::OUString the_name =
        "com.sun.star.beans.Pair<" +
        ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName() +
        "," +
        ::cppu::getTypeFavourChar(static_cast< typeparam_U * >(0)).getTypeName() +
        ">";
#else
        ::rtl::OUStringBuffer the_buffer;
        the_buffer.append("com.sun.star.beans.Pair<");
        the_buffer.append(::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0)).getTypeName());
        the_buffer.append(static_cast< ::sal_Unicode >(','));
        the_buffer.append(::cppu::getTypeFavourChar(static_cast< typeparam_U * >(0)).getTypeName());
        the_buffer.append(static_cast< ::sal_Unicode >('>'));
        ::rtl::OUString the_name(the_buffer.makeStringAndClear());
#endif
        ::css::uno::Type const & the_ptype0 = ::cppu::getTypeFavourChar(static_cast< typeparam_T * >(0));
        ::typelib_TypeClass the_pclass0 = (::typelib_TypeClass) the_ptype0.getTypeClass();
        ::rtl::OUString the_pname0(the_ptype0.getTypeName());
        ::rtl::OUString the_name0( "First" );
        ::css::uno::Type const & the_ptype1 = ::cppu::getTypeFavourChar(static_cast< typeparam_U * >(0));
        ::typelib_TypeClass the_pclass1 = (::typelib_TypeClass) the_ptype1.getTypeClass();
        ::rtl::OUString the_pname1(the_ptype1.getTypeName());
        ::rtl::OUString the_name1( "Second" );
        ::typelib_StructMember_Init the_members[] = {
            { { the_pclass0, the_pname0.pData, the_name0.pData }, true },
            { { the_pclass1, the_pname1.pData, the_name1.pData }, true } };
        ::typelib_TypeDescription * the_newType = 0;
        ::typelib_typedescription_newStruct(&the_newType, the_name.pData, 0, 2, the_members);
        ::typelib_typedescription_register(&the_newType);
        ::typelib_typedescription_release(the_newType);
        return new ::css::uno::Type(::css::uno::TypeClass_STRUCT, the_name); // leaked
    }
};
 } }

namespace cppu {

template< typename typeparam_T, typename typeparam_U > class UnoType< ::css::beans::Pair< typeparam_T, typeparam_U > > {
public:
    static inline ::css::uno::Type const & get() {
        return *detail::thePairType< typeparam_T, typeparam_U >::get();
    }

private:
    UnoType(UnoType &); // not defined
    ~UnoType(); // not defined
    void operator =(UnoType); // not defined
};

}

template< typename typeparam_T, typename typeparam_U > SAL_DEPRECATED("use cppu::UnoType") inline ::css::uno::Type const & SAL_CALL getCppuType(SAL_UNUSED_PARAMETER ::css::beans::Pair< typeparam_T, typeparam_U > const *) {
        return ::cppu::UnoType< ::css::beans::Pair< typeparam_T, typeparam_U > >::get();
    }

#endif // INCLUDED_COM_SUN_STAR_BEANS_PAIR_HPP
