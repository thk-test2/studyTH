#include <iostream>

using namespace std;

// 템플릿과 레퍼런스

void f1(int& a)  {}  // lvalue만 인자로 전달 가능. f1(n): ok.    f1(10): error
void f2(int&& a) {}  // rvalue만 인자로 전달 가능. f2(n): error. f2(10): ok

// 모든 타입의 lvalue만 전달 가능.
template<typename T> void f3(T& a) {} // T: int& / T&: int& &

int main()
{
    int n = 10;

    // T의 타입을 사용자가 지정할 경우
    f3<int>(n);    // f3(int& a)   => lvalue 전달 가능.
    f3<int&>(n);   // f3(int& &a)  => f3(int& a) => lvalue 전달 가능
    f3<int&&>(n);   // f3(int&& &a) => f3(int& a) => lvalue 전달 가능

    // 사용자가 T 타입을 지정하지 않은 경우
    f3(10);  // error
    f3(n);   // argument 추론으로 T: int. OK
}
