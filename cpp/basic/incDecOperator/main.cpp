#include <iostream>

class Point
{
    int x;
    int y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) { }

    void print() const
    {
        std::cout << x << ", " << y << std::endl;
    }
    Point& operator++() { // 레퍼런스로 리턴해야 계속 증가가 가능
        ++x;
        ++y;
        return *this;
    }
    Point operator++(int) { // 후위형
        Point temp (*this); // 자기 자신의 복사형을 만듬

        ++(*this); // 전위형 호출
        // ++x;
        // ++y;

        return temp;
    }
    Point& operator=(const Point& p) // void로 하면 연속 연산이 안 됨
    {
        std::cout << "=" << std::endl;
        x = p.x;
        y = p.y;
        return *this;
    }
};

int main() {
    Point p(1, 1);
    ++p; // p.operator++()
    p.print();

    Point ret = p++; // p.operator++()
    ret.print();
    p.print();

    Point p2;
    p2 = p;
    p2.print();
}
