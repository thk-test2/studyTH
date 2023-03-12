#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // lambda 활용 1. 함수 인자로 사용
//    sort(x, x+10, [](int a, int b) { return a < b;});

    //[](int a, int b) { return a + b; } // 임시객체 생성
//    int n = [](int a, int b) { return a + b; }(1, 2);

    // lambda 활용 2. auto 변수에 담아서 함수처럼 사용
    auto f1 = [](int a, int b) { return a + b; };
    auto f2 = [](int a, int b) { return a + b; };

    // f2 = [](int a, int b) { return a + b; }; ERROR 모든 lambda는 다른 type임

    cout << f1(1, 2) << endl;

    cout << typeid (f1).name() << endl;
    cout << typeid (f2).name() << endl;
    return 0;
}
