#include <iostream>

using namespace std;

// 임시객체와 멤버함수

class Test
{
public:
    int data;

    void foo() { cout << "foo" << endl; }
    void goo() & { cout << "goo" << endl; }  // lvalue 객체에 대해서만 호출.
    void hoo() && { cout << "hoo" << endl; } // rvalue 객체에 대해서만 호출.

    int& roo() & { return data; }
};

int main()
{
    Test t;
    t.foo();

    Test().foo(); // OK
//    Test().goo(); // ERROR
    Test().hoo(); // OK

    int& ret = t.roo();

    int& ret2 = Test().roo(); // ERROR

    return 0;
}
