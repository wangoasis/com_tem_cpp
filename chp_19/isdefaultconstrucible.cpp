#include "header/isdefaultconstruct.hpp"

class S
{
    S(int i) {

    }
};

int main()
{
    // check whether a class can be initialized without 
    // parameters
    static_assert(IsDefaultConstructible<int>);
    static_assert(IsDefaultConstructible<S> == false);
}