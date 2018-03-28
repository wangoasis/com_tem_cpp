#include "header/foreach_with_invoke.hpp"
#include <iostream>
#include <vector>
#include <string>

class MyOp
{
public:
    void memfunc(std::string const& prefix, int i) const
    {
        std::cout << prefix << i << std::endl;
    }
};

int main()
{
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    foreach(primes.begin(), primes.end(), 
            [](std::string const& prefix, int i)
            {
                std::cout << prefix << i << std::endl;
            },
            "Lambda called.");

    MyOp obj;
    foreach(primes.begin(), primes.end(),
            &MyOp::memfunc, // Callable
            obj,            // first argument, called as this pointer
            "Member function called."
            );
}
