#include <gtest/gtest.h>
#include <iostream>
using std::cout;
using std::endl;

struct printOneInt {
    void operator()(int i)
    {
        cout << "Print one element: ";
        cout << i << endl;
    }
};
struct dummy_p {  // test for error, line 53
    void operator()(int i) { cout << endl; }
};
struct printTwoInt {
    void operator()(int i1, int i2)
    {
        cout << "Print two element: ";
        cout << i1 << " " << i2 << endl;
    }
};
struct printThreeInt {
    void operator()(int i1, int i2, int i3)
    {
        cout << "Print three element: ";
        cout << i1 << " " << i2 << " " << i3 << endl;
    }
};

template <typename... Bases>
struct Overloader : Bases... {
    // call derive all the operator() of bases classes
    using Bases::operator()...;
};

TEST(chp_4, var_using)
{
    using printOneToThreeInt =
        Overloader<printOneInt, printTwoInt, printThreeInt>;
    printOneToThreeInt printOp;

    std::cout << "chp_4, var_using." << std::endl;
    printOp(2);         // call the operator() from printOneInt
    printOp(2, 4);      // call the operator() from printTwoInt
    printOp(1, 65, 2);  // call the operator() from printThreeInt

    /*
        Overload two same operator(), will cause error.

        using dummyPrintInt = Overloader<printOneInt, dummy_p>;
        dummyPrintInt dummyOp;

        error: call to object of type 'dummyPrintInt'
            (aka 'Overloader<printOneInt, dummy_p>') is ambiguous
        dummyOp(1);
    */
}