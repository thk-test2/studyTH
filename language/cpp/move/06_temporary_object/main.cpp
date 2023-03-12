#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;
// 참조리턴 vs 값 리턴

Point p;    // global variable

Point foo() // 값 리턴: 임시객체가 리턴된다.
{
    return p;
}
Point& goo() // 참조 리턴: 임시객체가 생성되지 않는다.
{
    return p;
}

int x;
int foo1() { return x; }
int& goo1() { return x; }

int main()
{
//    Point ret = foo();
//    foo().x = 10; // ERROR
    goo().x = 20;   // OK
    cout << p.x << endl; // 20

    vector<int> v(10, 2);
    v[0] = 10; // v.operator[](0) = 10;

//    foo1() = 10; // ERROR
    goo1() = 10; // OK

    return 0;
}
