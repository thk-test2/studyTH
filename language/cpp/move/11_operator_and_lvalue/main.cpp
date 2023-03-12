#include <iostream>

using namespace std;

// 후위형 증가 연산자. 값 리턴
int operator++(int& a, int)
{
    int temp = a;
    a = a + 1;
    return temp;
}
// 전위형 증가 연산자. 참조 리턴
int& operator++(int& a)
{
    a = a + 1;
    return a;
}

int main()
{
    int n = 0;
    n = 10;

    n++ = 20;  // operator++(n, int) ERROR
    ++n = 20;  // operator++(n). lvalue OK

    ++(++n);

    int a = 10, b = 0;
    a + b = 20;

    int x[3] = {1, 2, 3};
    x[0] = 5; // x.operator[](0) = 5; 리턴값이 참조일 것. lvalue

    int n = 0;
    int* p = &n;

    decltype(n) n1;  // int
    decltype(p) d1;  // int*
    decltype(*p) d2; // int? int&?
                     // *p가 lvalue가 될 수 있으면 int&

    int x[3] = {1, 2, 3};
    decltype(x[0]) d3; // int& 초기값 없어서 ERROR
    auto a1 = x[0];    // auto일 때는 참조가 제거됨

    decltype(++n) d4; // int&
    decltype(n++) d5; // int
}
