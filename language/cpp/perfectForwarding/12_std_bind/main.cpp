#include <iostream>
#include <functional>
using namespace std;

void foo()      {}
void goo(int& a) { a = 30; }

int main()
{
    void(*f)() = &foo;
    //f = &goo; // error

    function<void()> f2 = &foo;
    f2(); // foo()

    int n = 0;

    // f2 = bind(&goo, n); // 값으로 고정
    f2 = bind(&goo, ref(n)); // 참조로 고정.
    f2(); // goo(n);

    cout << n << endl; // 0
}

// 1. std::function
// 함수 포인터 역할을 하는 템플릿
// 일반 함수 뿐 아니라 함수 객체, 람다 표현식 등도 담을 수 있다.
// bind와 함께 사용하면 인자의 개수가 다른 함수(함수 객체)도 사용할 수 있다.

// 2. std::bind
// 함수 또는 함수 객체의 인자를 고정할 때 사용한다.
// 인자의 값을 고정할 때 값 방식을 사용한다.
// 참조로 인자를 고정하려면 ref() 또는 cref()를 사용한다.
