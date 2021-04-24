#include <iostream>
#include <functional>
using namespace std;

// void foo(int(*f)(int, int)) 타입이 지워지기 때문에 inline 치환이 안 됨
// void foo(function<int(int, int)> f)
// void foo(auto f) auto는 함수 인자가 될 수 없다. ERROR
// template<typename T> void foo(T& f) 임시객체이므로 ERROR
//template<typename T> void foo(T f) // type이 지워지지 않고 각자 생성
template<typename T> void foo(const T& f) // type이 지워지지 않고 각자 생성
{
    f(1, 2);
}

int main()
{
    auto f1 = [](int a, int b) { return a + b;}; // lambda는 임시객체

    int (*f2)(int, int) =
            [](int a, int b) { return a + b;};
    f2 = [](int a, int b) { return a - b;};

    function<int(int, int)> f3 =
            [](int a, int b) { return a + b;};

    f1(1, 2); // inline 치환 가능
    f2(1, 2); // 다른 것을 담을 수 있으므로 iniline 치환 어렵다
    f3(1, 2); // 다른 것을 담을 수 있으므로 iniline 치환 어렵다

    foo([](int a, int b) { return a + b;});
    foo([](int a, int b) { return a - b;});

    return 0;
}
