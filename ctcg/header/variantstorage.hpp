#ifndef _VARIANTSTORAGE_H
#define _VARIANTSTORAGE_H

#include <new>
#include "typelist.hpp"

namespace ctcg
{
namespace va
{
using namespace ctcg::tl;

template <typename... Types>
class VariantStorage
{
public:
    using LargestT = LargestType<TypeList<Types...>>;
    alignas(Types...) unsigned char buffer[sizeof(LargestT)];
    unsigned char discriminator = 0;

public:
    unsigned char getDiscriminator() const { return discriminator; }

    void setDiscriminator(unsigned char d) { discriminator = d; }

    void* getRawBuffer() { return buffer; }

    const void* getRawBuffer() const { return buffer; }

    // reinterpret_cast: use with caution
    // use case: bit manipulation, stream, aligned pointer
    template <typename T>
    T* getBufferAs()
    {
        return reinterpret_cast<T*>(buffer);
    }

    template <typename T>
    T const* getBufferAs() const
    {
        return reinterpret_cast<T*>(buffer);
    }

    const std::size_t largestSize() const { return sizeof(LargestT); }
};

}  // namespace va
}  // namespace ctcg

#endif