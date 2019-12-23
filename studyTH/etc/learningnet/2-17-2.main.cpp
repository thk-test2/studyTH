#include <iostream>

struct Point1
{
    int x, y;
};

struct Point2
{
    int x, y;
    Point2() = default;
};

struct Point3
{
    int x, y;
    Point3() {}
};

struct Point4
{
    int x, y;
    void set(int a, int b) { x = a; y = b; };
};

int main() {
    Point1 p1 = {1,1};
    Point2 p2 = {1,1};
    // Point3 p3 = {1,1};
    Point4 p4 = {1,1}; 

        int x[3] = { 1,2,3 };

    auto a1 = x[0];     // 1
    decltype(x[0]) d1;  // 2
    auto        a2 = x; // 3
    decltype(auto) d2 = x;  // 4    

}