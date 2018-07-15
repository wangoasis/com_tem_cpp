#include <gtest/gtest.h>

#include <cassert>
#include <functional>
#include <iostream>
#include <string>

void printString(std::string const& s) { std::cout << s << std::endl; }

template <typename T>
void printT(T arg)
{
    printString(arg);
}

void modifyNumber(int& s) { s = 100; }

template <typename T>
void modifyT(T arg)
{
    modifyNumber(arg);
    std::cout << "Inside modifyT: " << arg << std::endl;
}

TEST(chp_7, cref)
{
    std::string s("hello");
    printT(s);
    printT(std::cref(s));

    int i = 43;
    modifyT(i);
    ASSERT_EQ(43, i);  // i should not be modified

    modifyT(std::ref(i));
    ASSERT_EQ(100, i);  // i should be modified
}
