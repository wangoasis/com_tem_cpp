#pragma once

#include <type_traits>

/*
    template <typename... T>
    struct common_type;

    Determines the common type among all types T..., that is the type all T...
    can be implicitly converted to.
*/

namespace std11
{
template <typename T1, typename T2>
typename std::common_type<T1, T2>::type  // return type
max(T1 a, T2 b)
{
    return b < a ? a : b;
}
}  // namespace std11

namespace std14
{
template <typename T1, typename T2>
std::common_type_t<T1, T2>  // return type
max(T1 a, T2 b)
{
    return b < a ? a : b;
}
}  // namespace std14