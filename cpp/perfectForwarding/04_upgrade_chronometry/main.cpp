#include <iostream>

using namespace std;

int x = 10;
int  foo(int a) { return x; }
int& goo(int a) { return x; }

// ERROR. f가 선언 전에 사용됨
//template<typename F, typename T>
//decltype( f(forward<T>(arg) ) chronometry(F f, T&& arg)
//{
//    return f(forward<T>(arg));
//}

// OK
//template<typename F, typename T>
//auto chronometry(F f, T&& arg) -> decltype( f(forward<T>(arg) ) )
//{
//    return f(forward<T>(arg));
//}

// 컴파일 OK. C++14에서는 리턴 타입 안 써도 추론해줌
// 하지만 auto는 참조 속성을 제거해버림.
// 원본 함수가 참조를 리턴하면 버그.
//template<typename F, typename T>
//auto chronometry(F f, T&& arg)
//{
//    return f(forward<T>(arg));
//}

// OK. 원본 함수가 참조를 리턴해도 OK
template<typename F, typename T>
decltype(auto) chronometry(F f, T&& arg)
{
    return f(forward<T>(arg));
}

int main()
{
    int  ret = chronometry(&foo, 10);
    int& ret2 = chronometry(&goo, 10);
    ret = 20;
    cout << ret << endl;
    cout << ret2 << endl;
}
