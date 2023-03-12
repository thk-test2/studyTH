#include <iostream>

using namespace std;

int main()
{
    int(*f)(int, int) = [](int a, int b)
    {
        return a + b;
    };

    int v = 0;

    // capture 구문을 사용하면
    // 함수포인터로 암시적 변환될 수 없다.
    int(*f1)(int, int) = [v](int a, int b)
    {
        return a + b + v;
    };
    return 0;
}

class ClosureType
{
public:
    int operator()(int a, int b) const // 괄호 연산자는 static이 될 수 없음.
    {
        return a + b + v;
    }
    static int method(int a, int b) // 컴파일러가 별도의 static 함수를 만듬
    {
        return a + b + v; // ??
    }
    typedef int(*F)(int, int); // 컴파일러가 변환 연산자 제공하여 함수 포인터에 담을 수 있음

    operator F()
    {
//        return &ClosureType::operator(); 멤버함수 포인터인데 일반 함수 포인터에 담을 수 없음
        return &ClosureType::method;
    }
};
