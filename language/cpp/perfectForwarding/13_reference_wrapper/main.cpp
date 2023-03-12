#include <iostream>
#include <functional>
using namespace std;

void foo(int& a) { a = 30; }

template<typename T> struct xreference_wrapper
{
    T* ptr;
public:
    xreference_wrapper(T& r) : ptr(&r) {}

    operator T&() { return *ptr; }
};

template<typename T>
xreference_wrapper<T> xref(T& obj)
{
    return xreference_wrapper<T>(obj);
}

template<typename F, typename T>
void chronometry(F f, T arg)
{
    f(arg);
}

int main()
{
    int n = 0;
    //xreference_wrapper<int> r(n); // 결국 주소 보관
    //chronometry(&foo, r);

    //chronometry(&foo, xreference_wrapper<int>(n));
    chronometry(&foo, xref(n));

    cout << n << endl;

//    function<void()> f;
//    f = bind(&foo, n);
//    f();
}

// 핵심 1. 주소를 전달한다.
// 핵심 2. 포인터가 참조로 암시적 형변환되면 가능하다.

// 1. reference_wrapper
// 참조와 유사하게 동작하는 클래스 템플릿
// 참조로 변환 가능한 포인터

// 2. ref, cref
// reference_wrapper를 생성하는 helper 함수
