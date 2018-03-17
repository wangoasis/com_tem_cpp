#include "./header/print.hpp"
#include <string>
using std::string;
#include <complex>

int main() {
    string s("world");
    // should run first version
#define FIRST_VERSION
    print(1, 4.3, "hello", s);
#undef FIRST_VERSION
    
    // should run second version
    print(1, 3.2, "hello", s);
    
    printDoubled(1, 3.2, s, std::complex<float>(4, 2));
}