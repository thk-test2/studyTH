#include <iostream>

using namespace std;

// 연산자와 임시객체

// 후위형. 값 리턴
int operator++(int& n, int) // 표준 type을 갖고 ++연산자 재정의는 불가능함. pseudo 코드임
{
    int temp = n;
    n = n + 1;
    return temp;
}

// 전위형. 참조 리턴
int& operator++(int& n)
{
    n = n + 1;
    return n;
}

int main()
{
    int n = 3;

    n++;   // operator++(n, int)
    ++n;   // operator++(n)

    ++(++n); // 값을 리턴하면 임시객체 이므로 불가능한 코드.

    n++ = 10; // ERROR
    ++n = 10; // OK

    return 0;
}
