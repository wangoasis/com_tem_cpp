#include "ObjectCounter.hpp"
#include <gtest/gtest.h>

template <typename T>
class MyVector : public ObjectCounter<MyVector<T>>
{
};

TEST(chp_21, ObjectCounter)
{
    MyVector<int> v1;
    ASSERT_EQ(1, MyVector<int>::live());
    MyVector<int> v2;
    ASSERT_EQ(2, MyVector<int>::live());

    MyVector<int> v3(v1);
    ASSERT_EQ(3, MyVector<int>::live());

    MyVector<int> v4(std::move(v1));
    ASSERT_EQ(4, MyVector<int>::live());
}