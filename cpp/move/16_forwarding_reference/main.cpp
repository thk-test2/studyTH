#include <iostream>

using namespace std;

// T&&: lvalue와 rvalue를 모두 전달 가능.
//      lvalue를 전달하면 T는 lvalue reference로 결정
//      rvalue를 전달하면 T는 값 타입으로 결정
template<typename T> void f4(T&& a) {}

int main()
{
    int n = 10;

    // 사용자가 T의 타입을 명시적으로 전달할 때
    f4<int>();    // f4(int&& a)    => rvalue를 전달
    f4<int&>();   // f4(int& && a)  => f4(int& a) => lvalue를 전달
    f4<int&&>();  // f4(int&& && a) => f4(int&& a) => rvalue를 전달

    // T의 타입을 명시적으로 전달하지 않을 때
    f4(n);   // OK. 컴파일러가 T를 int& 로 결정.
    f4(10);  // OK. 컴파일러가 T를 int  로 결정. f4(T&& ) =? f4(int && )

}

void f1(int&  a) {}
void f2(int&& a) {}
template<typename T> void f3(T&  a) {}
template<typename T> void f4(T&& a) {}
// int&  : int 형의 lvalue 전달 가능.
// int&& : int 형의 rvalue 전달 가능.
// T&    : 모든 타입의 lvalue 전달 가능.(함수 생성)
// T&&   : 모든 타입의 lvalue와 rvalue 모두 전달 가능.(함수 생성)
//         forwarding reference
//         lvalue 를 전달하면 foo(n)  => T: int& / T&&: int& && => int&
//         rvalue 를 전달하면 foo(10) => T: int  / T&&: int&&


template<typename T> void foo(T&& a) {}

template<typename T> class Test
{
public:
    void goo(T&& a) {} // forwarding reference 아님.

    template<typename U> void hoo(U&& a) {} // forwarding reference 맞음.
};

int main()
{
    int n = 10;

    foo(n);   // OK
    foo(10);  // OK

    Test<int> t1; // T가 int로 결정. void(int&& a)
    t1.goo(n);  // ERROR
    t1.goo(10); // OK

    Test<int&> t2; // T int& => void goo(int& && a) => void goo(int&)
    t2.goo(n);  // OK
    t2.goo(10); // ERROR
}
