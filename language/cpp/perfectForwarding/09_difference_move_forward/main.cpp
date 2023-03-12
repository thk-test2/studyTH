#include <iostream>

using namespace std;

// static_cast<T&&>(arg): T의 타입에 따라 rvalue 또는 lvalue 캐스팅.

// 함수 인자: lvalue와 rvalue를 모두 받아서
// 리턴 타입: rvlaue로 캐스팅.
template<typename T>
typename remove_reference<T>::type&&
xmove(T&& obj)
{
    return static_cast<typename remove_reference<T>::type &&>(obj);
}

// 함수 인자: lvalue를 받아서
// 리턴 타입: T에 따라서 lvalue 또는 rvalue로 캐스팅.
template<typename T> T&& xforward(T& arg)
{
    return static_cast<T&&>(arg);
}

int main()
{

}
