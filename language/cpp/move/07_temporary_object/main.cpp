#include <iostream>

using namespace std;

// 임시객체가 생성되는 다양한 경우

struct Base
{
    int v = 10;
};
struct Derived : public Base
{
    int v = 20;
};

int main()
{
    Derived d;

    cout << d.v << endl;       // 20
    cout << d.Base::v << endl; // 10

    cout << static_cast<Base>(d).v << endl;  // 10. Base 타입의 temporary를 만듬
    cout << static_cast<Base&>(d).v << endl; // 10. d를 볼 때 Base로 해석해서 봄

    static_cast<Base>(d).v = 30;  // ERROR
    static_cast<Base&>(d).v = 30; // OK

    return 0;
}
