#include <iostream>

using namespace std;

class Test
{
public:
    Test()  { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
    Test(const Test& t) { cout << "Copy" << endl; }
    Test(Test&& t) noexcept { cout << "Move" << endl; }

    Test& operator=(const Test& t)
    {
        cout << "Copy=" << endl;
        return *this;
    }
    Test& operator=(Test&& t) noexcept
    {
        cout << "Move=" << endl;
        return *this;
    }
};

// T&  : lvalue만 받을 수 있다.
// T&& : lvalue와 rvalue를 모두 받을 수 있다.
// 인자로 lvalue 전달 : T => Test& T&& : Test& && => Test&
//       rvalue 전달 : T => Test T&&  : Test && => Test&&
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)
{
    // 목표: rvalue로 캐스팅
//    return static_cast<T&&>(obj);

    // lvalue일때 &가 생기므로 제거하여 &&로 캐스팅
    return static_cast<typename remove_reference<T>::type &&>(obj);
}

int main()
{
    Test t1;
    Test t2 = t1;       // copy
    Test t3 = xmove(t1); // move. static_cast<Test&&>(t1)
                         // 왜 copy가 호출되는가?
    Test t4 = xmove(Test());
}
