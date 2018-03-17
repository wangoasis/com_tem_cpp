#include <iostream>
using std::cout; using std::endl;

struct printOneInt
{
    void operator() (int i)
    {
        cout << "One ";
        cout << i << endl;
    }
};
struct dummy_p { // test for error, line 53
    void operator() (int i) {
        cout << endl;
    }
};
struct printTwoInt
{
    void operator() (int i1, int i2)
    {
        cout << "Two ";
        cout << i1 << " " << i2 << endl;
    }
};
struct printThreeInt
{
    void operator() (int i1, int i2, int i3)
    {
        cout << "Three ";
        cout << i1 << " " << i2 << " " << i3 << endl;
    }
};

template <typename... Bases>
struct Overloader : Bases...
{
    // call derive all the operator() of bases classes
    using Bases::operator()...;
};

int main() 
{
    using printOneToThreeInt = Overloader<printOneInt, printTwoInt, printThreeInt>;
    printOneToThreeInt printOp;

    printOp(2);
    printOp(2, 4);
    printOp(1, 65, 2);

    // using dummyPrintInt = Overloader<printOneInt, dummy_p>;
    // Overload two same operator(), will cause error
    // dummyPrintInt dummyOp;

    // error: call to object of type 'dummyPrintInt'
    // (aka 'Overloader<printOneInt, dummy_p>') is ambiguous
    // dummyOp(1);
}