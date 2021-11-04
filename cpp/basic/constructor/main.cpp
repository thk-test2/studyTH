#include <iostream>

using namespace std;

class Point {
public:
    Point() {}
    Point(int a, int b) { x = a; y = b; }

private:
    int x;
    int y;
};

int main()
{
    Point p1(1, 2); // 2
    Point p2{1, 2}; // 2, C++ 11
    Point p3 = {1, 2}; // 2, Copy, C++ 11

    Point p4; // 1
    Point p5(); // 객체 생성 아님. 함수 선언문
    Point p6{}; // 1
    Point p7 = {}; // 1, Copy

    Point p8[3]; // 1번 생성자 3번
    Point p9[3] = {Point(1,1)}; // 2번 생성자 1회, 1번 생성자 2회
    Point p10[3] = { {1, 1}, {2, 2} }; // 2번 2회, 1번 1회 C++ 11

    Point* p11; // 객체 생성 아님.

    p11 = static_cast<Point*>(malloc(sizeof(Point)));
    free(p11);

    p11 = new Point; // 1번 생성자 호출
    delete p11;

    p11 = new Point(); // 1번..
    delete p11;

    p11 = new Point(1, 2); // 2번
    delete p11;

    Point* p12 = new Point{1, 2};

    return 0;
}
