#include <iostream>

using namespace std;

struct Base
{
    virtual void foo() { cout << "B:foo" << endl; }
};
struct Derived : public Base
{
    virtual void foo() { cout << "D::foo" << endl; }
};

Derived d;
Base   f1() { return d; }
Base&  f2() { return d; }
Base&& f3() { return move(d);}

int main()
{
   Base b1 = f1(); // 임시객체, move
   Base b2 = f2(); // copy
   Base b3 = f3(); // move

   f1().foo(); // B::foo non-polimorphic
   f2().foo(); // D::foo polimorphic
   f3().foo(); // D::foo polimorphic

   int n = 10;
   n = 20;           // n: lvalue / 20: prvalue
   int n3 = move(n); // xvalue

   // cppreference.com 에서 value categories 확인하기.
}
