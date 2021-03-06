#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "call_with_invoke.hpp"

struct printThreeString {
    void operator()(std::string const& s1, std::string const& s2) const
    {
        std::cout << s1 << " " << s2 << std::endl;
    }
};

void printTwoInt(int const& i1, int const& i2)
{
    std::cout << i1 << " " << i2 << std::endl;
}

std::string concatenateTwoStr(std::string const& s1, std::string const& s2)
{
    return s1 + " " + s2;
}

TEST(chp_11, call_test)
{
    printThreeString op;
    std::string s1("hello"), s2("world");
    call(op, s1, s2);
    call(printTwoInt, 1, 2);
    auto tmps = call(concatenateTwoStr, s1, s2);
    std::cout << tmps << std::endl;
}