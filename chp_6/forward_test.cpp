#include <gtest/gtest.h>

#include <iostream>
using std::cout;
using std::endl;
#include <utility>

class X
{
};

enum class ParamType {
    lvalue,
    const_lvalue,
    rvalue,
};

ParamType g(X&)
{
    cout << "g(X&) called" << endl;
    return ParamType::lvalue;
}

ParamType g(X const&)
{
    cout << "g(X const&) called" << endl;
    return ParamType::const_lvalue;
}

ParamType g(X&&)
{
    cout << "g(X&&) called" << endl;
    return ParamType::rvalue;
}

// perfect forward
// T&& for a template parameter T declares a forwarding reference
// (also called universal reference). It can be bound to a mutable
// immutable, or movable object.
template <typename T>
ParamType f(T&& val)  // universal reference, or forward reference
{
    return g(std::forward<T>(val));
}

// not right form
template <typename T>
ParamType f2(T val)
{
    return g(val);
}

TEST(chp_6, forward)
{
    X v;
    X const c;

    EXPECT_EQ(f(v), ParamType::lvalue);
    EXPECT_EQ(f(c), ParamType::const_lvalue);
    EXPECT_EQ(f(X()), ParamType::rvalue);
    EXPECT_EQ(f(std::move(v)), ParamType::rvalue);
    EXPECT_EQ(f2(v), ParamType::lvalue);
    EXPECT_EQ(f2(c), ParamType::lvalue);
    EXPECT_EQ(f2(X()), ParamType::lvalue);
    EXPECT_EQ(f2(std::move(v)), ParamType::lvalue);
}
