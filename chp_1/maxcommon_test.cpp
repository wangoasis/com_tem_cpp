#include "./header/maxcommon.hpp"
#include <cassert>

int main() {
    assert(::max(4, 7.2) == 7.2);
    assert((::max(4, 7.2) == 7) == false);
    assert(::max2(4, 7.2) == 7.2);
    assert((::max2(4, 7.2) == 7) == false);
}
