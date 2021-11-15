#include <iostream>

using namespace std;

class Test {
};

// T&: lvalue 만 받을 수 있다.
// T&&: lvalue와 rvalue를 모두 받을 수 있다.(Forwarding Reference 이해 필요)
// 인자로 lvalue 전달 : T => Test& / T&& : Test& && => Test&
//       rvalue 전달 : T => Test  / T&& : Test && => Test&&
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)
{
    // 목표 : rvalue로 캐스팅 하는 것.
    // return static_cast<T&&>(obj);

    return static_cast<typename remove_reference<T>::type &&>(obj);
}

int main()
{
    Test t1;
    Test t2 = t1; // copy
    Test t3 = xmove(t1); // move. rvalue로 캐스팅 하는 것
                        // static_cast<Test&&>(t1)

    Test t4 = xmove(Test() ); // move
}
