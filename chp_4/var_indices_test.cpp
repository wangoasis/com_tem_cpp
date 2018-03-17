#include <vector>
#include <string>
#include "./header/print.hpp"

int main() {
    std::vector<std::string> coll = {"good", "times", "say", "bye"};
    printElemsFromIdxs(coll, 2, 0, 3);
}