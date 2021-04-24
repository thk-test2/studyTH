#include <iostream>
#include "Point.h"

using namespace std;

// 임시객체와 함수 인자
void foo(const Point& p)
// void foo(Point& p) // 임시객체를 전달 받을 수 없다.
{
}

int main()
{
//    Point pt(1, 1);
//    foo(pt);

    // 임시객체를 사용한 인자 전달
    foo( Point(1, 1) );

//    sort(x, x+10, greater<int>());

    cout << "end" << endl;
    return 0;
}
