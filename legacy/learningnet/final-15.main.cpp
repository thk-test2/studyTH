#include <iostream>

class Point
{
public:
    Point(int a = 0, int b = 0) { }
};

int main()
{
    int a = 1;

    Point( 1 );     // 1
    Point( a );     // 2
    Point{ a };     // 3
    Point{ a, a };      // 4
}
