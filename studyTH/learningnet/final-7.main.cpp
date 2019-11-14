#include <iostream>

int main()
{
    int x[3] = { 1,2,3 };
    int n = 0;

    auto a1 = x[0];
    // std::cout << decltype(a1) << std::endl;

    auto a2 = n;
    decltype(x[0]) d1 = x[0];
    decltype(n)    d2 = n;  
}