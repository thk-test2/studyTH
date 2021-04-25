#include <iostream>

using namespace std;

using LREF = int&;  // typedef int& LREF;
using RREF = int&&; // typedef int&& RREF;

template<typename T> void foo(T& a) {}

int main()
{
    int n = 10;

    LREF r1 = n;
    RREF r2 = 10;

    LREF& r3 = n;   // int& & r3 = int&
    RREF& r4 = n;   // int&& & => int&

    LREF&& r5 = n;  // int& && => int&
    RREF&& r6 = 10; // int&& && => int&&

    int& && r7; // 컴파일 에러
    foo<int&>(n);  // foo(int& & a) => foo(int& a)

    return 0;
}
