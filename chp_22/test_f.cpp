#include <vector>
#include <iostream>
#include <functional>

void printInt(int i)
{
  std::cout << i << ' ';  
}

template<typename F>
void forUpTo(int n, F f)
{
  std::cout << "using template parameter to pass function" << std::endl;
  for (int i = 0; i != n; ++i)
  {
    f(i);  
  }
}

void forUpTo2(int n, std::function<void(int)> f)
{

  std::cout << "using std::function" << std::endl;
  for (int i = 0; i != n; ++i)
  {
    f(i);
  }
}

void forUpTo3(int n, void (*f)(int))
{
  std::cout << "using function pointer" << std::endl;
  for (int i = 0; i != n; ++i)
  {
    f(i);
  }
}

int main()
{
  std::vector<int> values;

  // insert values from 0 to 4:
  forUpTo(5,
          [&values](int i) {
            values.push_back(i);
          });

  // print elements:
  forUpTo(5,
          printInt);    // prints 0 1 2 3 4
  std::cout << std::endl;
  forUpTo2(5,
          printInt);    // prints 0 1 2 3 4
  std::cout << std::endl;
  forUpTo3(5,
          printInt);    // prints 0 1 2 3 4
  std::cout << std::endl;

  // also, a lambda function can be passed to forUpTo and forUpTo2 version
  // while failed conversion to function pointer
  forUpTo2(5,
          [&](int i){ std::cout << i << " "; });    // prints 0 1 2 3 4
  std::cout << std::endl;
}