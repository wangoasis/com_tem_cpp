#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;

template <int Val, typename T>
T addValue(T x)
{
    return x + Val;
}

TEST(Chp_3, AddValue)
{
    vector<int> v{1, 2, 3, 4, 5};

    {
        vector<double> ret;
        std::transform(
            v.begin(), v.end(), std::back_inserter(ret), addValue<5, int>);

        vector<double> expected{6, 7, 8, 9, 10};
        EXPECT_EQ(expected, ret);
    }

    {
        vector<double> origin{1.4, 2.3, 3.1, 4.2, 5.3};
        vector<double> ret;
        std::transform(
            origin.begin(), origin.end(), std::back_inserter(ret),
            addValue<5, int>);

        vector<double> expected{6, 7, 8, 9, 10};

        // The result should still be int, although `origin` is a vector of
        // double type.
        EXPECT_EQ(expected, ret);
    }

    {
        vector<double> origin{1.4, 2.3, 3.1, 4.2, 5.3};
        vector<double> ret;
        std::transform(
            origin.begin(), origin.end(), std::back_inserter(ret),
            addValue<5, double>);

        vector<double> expected{6.4, 7.3, 8.1, 9.2, 10.3};

        // The result should now be double type.
        EXPECT_EQ(expected, ret);
    }
}
