#include <iostream>

using namespace std;

void goo(int& a)  { cout << "goo" << endl; a = 30; }
void foo(int  a)  { cout << "foo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }

//// perfect forwarding: wrapper 함수가 인자를 받아서 원본 함수에게 완벽하게 전달하는 개념
//template<typename F>
//void chronometry(F f, int& arg)
//{
//    f(arg);
//}
//template<typename F>
//void chronometry(F f, int&& arg)
//{
//    f(static_cast<int&&>(arg));
//}

// int&  : 정수형 lvalue
// int&& : 정수형 rvalue
// T&    : 모든 타입 lvalue
// T&&   : 모든 타입 lvalue와 rvalue 모두 받는다. forwarding reference
template<typename F, typename T>
void chronometry(F f, T&& arg)
{
//    f(static_cast<T&&>(arg));
    f(forward<T>(arg));  // forward가 결국 내부적으로 위의 캐스팅 수행
}

int main()
{
    int n = 0;

    chronometry(&goo, n);
    chronometry(&hoo, 10);
    chronometry(&foo, 5);

    cout << n << endl;
}

// perfect forwarding을 사용하는 함수를 만드는 방법
// 1. 함수 인자로 forwarding reference를 사용한다.
// 2. 함수 인자를 원본 함수에 보낼 때 std::forward<T>(arg)로 묶어서 전달한다.

chronometry(&goo, n); // 컴파일러가 만들어 줌
void chronometry(void(*f)(int&), int& arg)
{
    f(static_cast<int&>(arg)); // 같은 int&로 스태틱 캐스팅하므로 컴파일 타임에 f(arg);
}

chronometry(&hoo, 10); // 컴파일러가 만들어 줌
void chronometry(void(*f)(int&&), int&& arg)
{
    f(static_cast<int&&>(arg));
}
