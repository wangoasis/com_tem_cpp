#include "stack9.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

TEST(chp_5, stack)
{
    Stack<int> iStack;    // stack of ints
    Stack<float> fStack;  // stack of floats

    // manipulate int stack
    iStack.push(1);
    iStack.push(2);
    EXPECT_EQ(iStack.top(), 2);

    // manipulate float stack:
    fStack.push(3.3);
    EXPECT_EQ(fStack.top(), 3.3f);

    // assign stack of different type and manipulate again
    fStack = iStack;
    fStack.push(4.4);
    EXPECT_EQ(fStack.top(), 4.4f);

    // stack for doubless using a vector as an internal container
    Stack<double, std::vector> vStack;
    vStack.push(5.5);
    vStack.push(6.6);
    EXPECT_EQ(vStack.top(), 6.6);

    vStack = fStack;
    std::cout << "vStack: ";
    while (!vStack.empty()) {
        std::cout << vStack.top() << ' ';
        vStack.pop();
    }
    std::cout << '\n';
}
