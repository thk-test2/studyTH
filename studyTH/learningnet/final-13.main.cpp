#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <functional>

int main()
{
    int n1 = 10;
    int n2 = 20;

    std::reference_wrapper<int> r1(n1);
    std::reference_wrapper<int> r2(n2);

    r1 = r2;

    std::cout << n1 << ", ";
    std::cout << n2 << ", ";
    std::cout << r1 << ", ";
    std::cout << r2 << ", "; 
}