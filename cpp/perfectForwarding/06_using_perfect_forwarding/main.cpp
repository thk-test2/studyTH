#include <iostream>
#include <vector>
using namespace std;

class Point
{
    int x, y;
public:
    Point(int a, int b, int &n) { cout << "Point()" << endl; }
    ~Point()            { cout << "~Point()" << endl; }
    Point(const Point&)
    {
        cout << "Point(const Point&)" << endl;
    }
};

int main()
{
    vector<Point> v;

    Point p(1, 2);
    v.push_back(p);

    // 소멸자 호출 횟수 : 2

    int n = 10;
    v.emplace_back(1, 2, n);
    // 소멸자 호출 횟수 : 1
}
