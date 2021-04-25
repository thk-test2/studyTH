#include <iostream>

using namespace std;

void f1(int   a) {}
void f2(int&  a) {}
void f3(int&& a) {}

int main()
{
    int n = 10;

    f1(n);
    f2(n);
    f3(static_cast<int&&>(n));
    f3(move(n));
}

// 1. 지역변수는 참조로 리턴할 수 없다.
// 2. 리턴 타입에 따른 리턴 방법.
int x = 0;
int   f4() { return x; }
int&  f5() { return x; }
int&& f6() { return move(x); }

int main()
{
    f4() = 10; // ERROR
    f5() = 20; // OK
    f6() = 30; // ERROR
}
