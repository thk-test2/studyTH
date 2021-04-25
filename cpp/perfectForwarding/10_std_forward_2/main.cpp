#include <iostream>

using namespace std;

template<typename T>
T&& xforward(typename remove_reference<T>::type& arg)
{
    return static_cast<T&&>(arg);
}

// rvalue를 인자로 가지는 forward
// rvalue를 인자로 받아서 rvalue로 캐스팅하는 xforward
template<typename T>
T&& xforward(typename remove_reference<T>::type&& arg)
{
    return static_cast<T&&>(arg);
}

void foo(int&  a) { cout << "int&" << endl; }
void foo(int&& a) { cout << "int&&" << endl;}

class Test
{
    int data;
public:
    int& get() &  { return data; }
    int  get() && { return data; }
};

template<typename T> void wrapper(T&& obj)
{
    using Type = decltype(forward<T>(obj).get());
    foo(xforward<Type>(xforward<T>(obj).get()));
}

int main()
{
    Test t;
    wrapper(t);      // lvalue => foo(int&)
    wrapper(Test()); // rvalue => foo(int&&)
//    foo(t.get());      // foo(int&) => foo(int&)
//    foo(Test().get()); // foo(int)  => foo(int&&)
}
