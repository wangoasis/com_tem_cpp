#pragma once

#include <type_traits>

namespace tmpl {

// NOTE: `std::common_type` decays implicitly so we don't need to worry that it
// returns a reference type.
template <typename T1, typename T2>
std::common_type_t<T1, T2> max(T1 a, T2 b)
{
    return b < a ? a : b;
}

// Additional NOTE:
// 1. `true ? a : b` doesn't decay thus we need to call explicitly.
//
// template <typename T1, typename T2>
// auto max(T1 a, T2 b) -> std::decay_t<decltype(true ? a : b)>
//
// 2. An initialization of `auto` always decays. This also applies to return
// values when the return type is `auto`.
//
// int i = 42;
// const int& ir = i;
// auto a = ir; // `a` is declared as of type int.

} // namespace tmpl
