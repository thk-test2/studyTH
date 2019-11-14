#include <iostream>

using namespace std;

class Test
{
public:
    Test()  { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
};

class Point
{
public:
    int x, y;

};

int main()
{
    Test(), cout << "X" << endl;
    cout << "Y" << endl;

    Point().x = 10;         // 1

    cout << &Point() << endl;   // 2

    Point& r1 = Point();        // 3

    const Point& r2 = Point();  // 4
}