#include <iostream>

using namespace std;

void goo(int& a)  { cout << "goo" << endl; a = 30; }
void foo(int  a)  { cout << "foo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }

// perfect forwarding: wrapper 함수가 인자를 받아서 원본 함수에게 완벽하게 전달하는 개념
template<typename F>
void chronometry(F f, int& arg)
{
    f(arg);
}
template<typename F>
void chronometry(F f, int&& arg)
{
    // int&& arg = 10
    // f(arg);
    // 해결책: lvalue인 arg를 rvalue로 다시 캐스팅한다
    f(static_cast<int&&>(arg));
}

int main()
{
    hoo(10);   // OK
    chronometry(&hoo, 10);

    int&& arg = 10; // 10 은 rvalue, arg 는 lvalue이다.

    int n = 0;

    chronometry(&goo, n); // goo(n)
    chronometry(&foo, 5); // foo(5) 실행시 수행시간 측정.

    cout << n << endl; // 30
}
// perfect forwarding 을 하려면
// 1. 함수 인자를 받을 때 reference를 사용해야 한다.
// 2. lvalue와 rvalue reference 버전을 모두 제공해야 한다.
// 3. rvalue reference 버전의 함수에서는 인자를 원본 함수에 전달할 때 rvalue로 캐스팅해서 전달한다.
