#include <iostream>

using namespace std;

void goo(int&  a) { cout << "goo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }

template<typename T> T&& xforward(T& arg)
{
    return static_cast<T&&>(arg);
}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
    f(xforward(arg)); // ERROR
    // f(xforward<T>(arg));
}

int main()
{
    int n = 0;
    chronometry(&goo, n);
    chronometry(&hoo, 1);

    cout << n << endl;
}

// std::forward
// lvalue를 인자로 받아서 T의 타입에 따라 lvalue 또는 rvalue로 캐스팅 한다.
