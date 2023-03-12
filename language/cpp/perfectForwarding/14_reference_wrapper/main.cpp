#include <iostream>
#include <functional>
using namespace std;

int main()
{
    int n1 = 10;
    int n2 = 20;

    // int& r1 = n1;
    // int& r2 = n2;
    // r1 = r2; // 가리키는 주소가 전달되느냐, 값이 전달되느냐
                // 참조는 가리키는 곳을 변경할 수 없으므로 값이 전달.

    reference_wrapper<int> r1(n1);
    reference_wrapper<int> r2(n2);

    cout << n1 << endl;
    cout << n2 << endl;
    cout << r1 << endl;
    cout << r2 << endl;

    // vector<int&> v(10); 진짜 참조가 아닌 reference_wrapper를 보관할 수 있다.
}

// 1. 일반 참조
// 대입시 참조가 아닌 값이 이동한다

// 2. reference_wrapper
// 값이 아닌 참조가 이동한다
