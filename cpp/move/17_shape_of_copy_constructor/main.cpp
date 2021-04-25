#include <iostream>

using namespace std;

class Point
{
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}

//    Point(Point p) // Point p = p1. 결국 복사 생성자 무한 호출
//    Point(Point& p) // lvalue 객체만 인자로 받을 수 있다.
                      // 함수 리턴값으로 반환되는 임시객체를 받을 수 없다.
    Point(const Point& p) // lvalue 객체와 rvalue 객체를 모두 받을 수 있다.
    {
        // 모든 멤버 복사.
    }
};

Point foo()
{
    Point ret(0, 0);
    return ret;
}

int main()
{
    Point p1(1, 1);  // 생성자 호출
    Point p2(p1);    // Point( Point ) 복사 생성자.

    Point p3( foo() ); // 값 리턴이어서 rvalue
}
