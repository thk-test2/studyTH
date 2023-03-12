#include <iostream>

using namespace std;

int main()
{
    auto f1 = [](int a, int b) { return a + b; };

    auto f2 = [](int a, int b) -> int { return a + b; };

    auto f3 = [](int a, int b) { // 같은 type일 때는 굳이 return type 명시 안해도 컴파일러가 추론 가능
        if (a == 1)
            return a;
        else
            return b;
    };

    auto f4 = [](int a, double b) -> double {
        if (a == 1)
            return a;
        else
            return b;
    };

    return 0;
}
