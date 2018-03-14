#include <type_traits>

// c++ 11 version
template<typename T1, typename T2>
typename std::common_type<T1, T2>::type  // return type
max(T1 a, T2 b) 
{
    return b < a ? a : b;
}

// c++ 14 version
template<typename T1, typename T2>
std::common_type_t<T1, T2>  // return type
max2(T1 a, T2 b) 
{
    return b < a ? a : b;
}
