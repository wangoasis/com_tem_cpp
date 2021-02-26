#ifndef _VARIANTCHOICE_H
#define _VARIANTCHOICE_H

#include "typelist.hpp"
#include "variant.hpp"

namespace ctcg
{
namespace va
{
using namespace ctcg::tl;

template <typename T, typename... Types>
class VariantChoice
{
public:
    using Derived = Variant<Types...>;
    Derived& getDerived() { return *static_cast<Derived*>(this); }
    Derived const& getDerived() const
    {
        return *static_cast<Derived const*>(this);
    }

protected:
    constexpr static unsigned Discriminator =
        FindIndexOf<TypeList<Types...>, T>::value + 1;

public:
    VariantChoice() {}

    VariantChoice(T const& t)
    {
        new (getDerived().getRawBuffer()) T(t);
        getDerived().setDiscriminator(Discriminator);
    }

    VariantChoice(T&& t)
    {
        new (getDerived().getRawBuffer()) T(t);
        getDerived().setDiscriminator(Discriminator);
    }

    bool destroy()
    {
        if (getDerived().getDiscriminator() == Discriminator) {
            getDerived().template getBufferAs<T>()->~T();
            return true;
        }
        return false;
    }

    Derived& operator=(T const& t)
    {
        if (getDerived().getDiscriminator() == Discriminator) {
            *getDerived().template getBufferAs<T>() = t;
        } else {
            getDerived().destroy();
            new (getDerived().getRawBuffer()) T(t);
            getDerived().setDiscriminator(Discriminator);
        }
        return getDerived();
    }

    Derived& operator=(T&& t)
    {
        if (getDerived().getDiscriminator() == Discriminator) {
            *getDerived().template getBufferAs<T>() = std::move(t);
        } else {
            getDerived().destroy();
            new (getDerived().getRawBuffer()) T(std::move(t));
            getDerived().setDiscriminator(Discriminator);
        }
        return getDerived();
    }
};

}  // namespace va
}  // namespace ctcg

#endif