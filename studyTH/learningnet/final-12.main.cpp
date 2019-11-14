#include <iostream>
#include <functional>

using namespace std;

void foo(int& a) {  a = 30; }

int main()
{
    int n = 10;
    function<void()> f = bind(&foo, ref(n));

    f();

    cout << n << endl; // 30 이 나와야 합니다.
}