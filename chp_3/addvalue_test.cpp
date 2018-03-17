#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

template <int Val, typename T>
T addValue(T x) {
    return x + Val;
}

template <typename T>
void printVector(vector<T> &v) {
    for (T &t : v)
        std::cout << t << " ";
    std::cout << std::endl;
}

int main() {
    vector<int> v{1,2,3,4,5};
    vector<double> v2(5, 0);
    std::transform(v.begin(), v.end(), // source
            v2.begin(),  // destination
            addValue<5, int>); // function
    printVector(v2);

    // vector of double
    vector<double> v3{1.4, 2.3, 3.1, 4.2, 5.3};
    std::transform(v3.begin(), v3.end(), // source
            v2.begin(),  // destination
            addValue<5, int>); // function
    printVector(v2);
    // the result should still be int, although v3 is a vector of double

    std::transform(v3.begin(), v3.end(), // source
            v2.begin(),  // destination
            addValue<5, double>); // function
    printVector(v2);
    // the result should now be double

    // lambda expression
    std::transform(v3.begin(), v3.end(), // source
            v2.begin(),  // destination
            [&](double i){ return i + 5; }); // function
    printVector(v2);
}
