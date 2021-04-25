#include <iostream>

using namespace std;

int main()
{
    int n = 10;

    // 규칙 1. non const lvalue reference는 lvalue만 참조 가능
    int& r1 = n;   // OK
    int& r2 = 10;  // ERROR

    // 규칙 2. const reference는 lvalue와 rvalue를 모두 참조 가능
    const int& r3 = n;  // OK
    const int& r4 = 10; // OK

    const Point& r = Point(1, 1); // 임시객체가 상수는 아님. 가리킬 수 있지만 상수성이 추가됨
    r.x = 10; // ERROR

    // 규칙 3. rvalue reference는 rvalue만 가리킬 수 있다. C++11 문법
    int&& r5 = n;   // ERROR
    int&& r6 = 10;  // OK

    return 0;
}
