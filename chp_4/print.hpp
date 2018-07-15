#pragma once

#include <iostream>

namespace v1
{
void print()
{
    // empty body
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg << "\n";
    print(args...);
}

template <typename... T>
void printDoubled(T const&... args)
{
    print(args + args...);
}

template <typename C, typename... Idxs>
void printElemsFromIdxs(C const& coll, Idxs... idxs)
{
    print(coll[idxs]...);
}
}  // namespace v1

namespace v2
{
template <typename T>
void print(T arg)
{
    std::cout << arg << "\n";
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg << "\n";
    print(args...);
    // if two functions template only differ by a trailing
    // parameter pack, the function template without the
    // trailing pack is preferred
}

template <typename... T>
void printDoubled(T const&... args)
{
    print(args + args...);
}

template <typename C, typename... Idxs>
void printElemsFromIdxs(C const& coll, Idxs... idxs)
{
    print(coll[idxs]...);
}
}  // namespace v2
