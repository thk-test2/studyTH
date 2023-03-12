#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0)
    {
        cout << "Point()" << endl;
    }
    Point(const Point&)
    {
        cout << "Point(const Point&)" << endl;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
};

#endif // POINT_H
