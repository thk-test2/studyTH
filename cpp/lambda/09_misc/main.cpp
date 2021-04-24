#include <iostream>

using namespace std;

// Concept Ts. g++에서는 함수의 인자로 auto 가능
void foo(auto n) {}

int main()
{
    // generic lambda : C++14
    auto f1 = [](auto a, auto b) { return a + b; };
    cout << f1(1, 2.1) << endl;

    // nullary lambda
    auto f2 = [] { return 10; };

    // C++ 17: () 함수를 constexpr 함수로..
    auto f3 = [](int a, int b) constexpr
    {
        return a + b;
    };

    int y[f3(1, 2)];

//    decltype(f1) f4; // error. 기본 생성자 없음
    decltype(f1) f5 = f1; // ok. 복사 생성자 기본 제공.
    decltype(f1) f6 = move(f1); // ok

    return 0;
}
