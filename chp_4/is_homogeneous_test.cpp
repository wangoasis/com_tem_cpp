#include <cassert>
#include <type_traits>
#include <iostream>

template <typename T1, typename... TN>
constexpr bool isHomogeneous(T1, TN...)
// if don't care parameter, don't need specify parameter name 
// in function signature
{
    // fold expression, supported since c++17
    return (std::is_same_v<T1, TN> && ...);
}

int main() 
{
    // static_assert is used for compilation time assertion
    static_assert(isHomogeneous("hello", "world", " ", "!")); // all are const char*
    static_assert(isHomogeneous("hello", " ", 5) == false);
    static_assert(isHomogeneous(5, 4.5, 3) == false);

    // this line would cause compilation failure
    // static_assert(isHomogeneous("Hello", 5));

    // compile successfully, but run-time assertion failure
    assert(isHomogeneous("Hello", 5));
}
