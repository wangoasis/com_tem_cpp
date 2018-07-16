#include <gtest/gtest.h>

#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

template <typename T, unsigned N>
std::size_t len(T (&)[N])
{
    std::cout << "called with T&[N]" << std::endl;
    return N;
}

// decltype can take multiple parameters
// All the parameters except the last are expressions
// Compiler would check whether all expressions are valid
// If not, the function template are not matched
// If so, the return type is the last parameter of decltype
// Notice that "typename T::size_type()", both "typename" and "()"
// are necessary
template <typename T>
auto len(T const& t) -> decltype(t.size(), typename T::size_type())
{
    std::cout << "called with T.size(), using decltype to set return type"
              << std::endl;
    return t.size();
}

// variadic function
std::size_t len(...)
{
    std::cout << "No matching function" << std::endl;
    return -1;
}

TEST(chp_8, decltype)
{
    int* p = nullptr;
    std::allocator<int> ax;
    std::vector<int> v{10, 1};
    std::string s("hello");
    std::unordered_set<int> se;
    se.insert(1);

    EXPECT_EQ(7, len("hello:"));  // called with T&[N]
    EXPECT_EQ(5, len(s));         // called with T.size()
    EXPECT_EQ(1, len(se));        // called with T.size()
    EXPECT_EQ(2, len(v));         // called with T.size()
    EXPECT_EQ(-1, len(p));        // no matching function
    EXPECT_EQ(-1, len(ax));  // no matching function, because allocator<T> has
                             // no size() member function
}
