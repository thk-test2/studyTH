#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
//    Point p1(1, 1); // 이름: p1, 파괴: 함수{}을 벗어날 때.
                      // named object
//    Point(1, 1); // 이름 없음. 파괴: 문장의 끝(;)
                   // unnamed object
                   // 임시객체: 클래스이름(),
    Point(1, 1), cout << "X" << endl;

    cout << "end" << endl;
    return 0;
}
