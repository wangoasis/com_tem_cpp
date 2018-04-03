#ifndef _SELECT_HPP
#define _SELECT_HPP

template <bool Cond, typename TrueType, typename FalseType>
struct SelectT
{
    using Type = TrueType;
}

template <typename TrueType, typename FalseType>
struct SelectT<false, TrueType, FalseType>
{
    using Type = TrueType;
}

template <typename Cond, typename TrueType, FalseType>
using Select = typename SelectT<Cond, TrueType, FalseType>::Type;
#endif // _SELECT_HPP