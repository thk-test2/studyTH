#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    Point pt(1, 1); // pt: 이름있는 객체

    pt.x = 10;          // OK
//    Point(1, 1).x = 10; // ERROR. 특징 1. 임시객체는 lvalue가 될 수 없다.

    Point* p1 = &pt;          // OK
//    Point* p2 = &Point(1, 1); // ERROR. 특징 2. 임시객체는 주소를 구할 수 없다.

    Point& r1 = pt;          // OK
//    Point& r2 = Point(1, 1); // ERROR. 특징 3. 임시객체는 non const 참조로 참조할 수 없다.

    const Point& r3 = pt;          // OK
    const Point& r4 = Point(1, 1); // OK. 특징 4. 임시객체는 const 참조로 참조할 수 있다.
                                   // 임시객체의 수명이 r4의 수명과 동일해 진다.
//    r4.x = 10; ERROR
    // C++11 rvalue reference
    Point&& r5 = Point(1, 1); // OK. 특징 5. 임시객체는 rvalue 참조로 참조할 수 있다.
    r5.x = 10;

    return 0;
}
