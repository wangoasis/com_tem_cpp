#include "header/accum.hpp"
#include <iostream>
#include <unordered_set>
#include <vector>

int main()
{
    int arr[] = {1,2,3,4,5};
    auto sum_arr = accum(arr, arr+5);
    std::cout << sum_arr / (sizeof(arr)/sizeof(int)) << std::endl;

    char s[] = "hello world!";
    int len = sizeof(s) / sizeof(char) - 1;
    auto sum_s = accum(s, s+len);
    std::cout << sum_s / len << std::endl; 

    std::unordered_set<int> my_set;
    for (int i = 1; i < 10; i++)
        my_set.insert(i);
    std::cout << accum(my_set.begin(), my_set.end()) / my_set.size() << std::endl;

    std::vector<char> v{'a', ',', '!', 'K'};
    std::cout << accum(v.begin(), v.end()) / v.size() << std::endl;
}