#include <iostream>
#include "Point.h"

using namespace std;

Point foo()
{
    // NRVO: 요즘 컴파일러는 이름있는 객체도 RVO를 사용하여 리턴
//    Point pt(1, 1); // 2. 생성자
//    return pt;      // return Point(pt) 임시객체 생성
//                    // 3. 복사 생성자
    // 임시 객체를 사용한 리턴. RVO (Return Value Optimization)
    return Point(1, 1);
}

int main()
{
    Point ret(0, 0); // 1. 생성자

    ret = foo();

    cout << "end" << endl;
    return 0;
}
