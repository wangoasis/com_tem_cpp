#include <iostream>

#ifdef FIRST_VERSION
void print() {
    // empty body
}

template <typename T, typename... Types> 
void print(T firstArg, Types... args)
{
    std::cout << "first version: " << firstArg << "\n";
    print(args...);
}
#endif

#ifndef FIRST_VERSION
template <typename T>
void print(T arg)
{
    std::cout << "second version: " << arg << "\n";
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << "second version: " << firstArg << "\n";
    print(args...);
    // if two functions template only differ by a trailing 
    // parameter pack, the function template without the 
    // trailing pack is preferred
}
#endif

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