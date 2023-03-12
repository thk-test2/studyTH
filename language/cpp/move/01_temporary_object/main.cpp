#include <iostream>

using namespace std;

// 컴파일러가 임시로 만든 메모리 공간이 temporary object(전통적 관점)

int main()
{
    int a = 1, b = 2, c = 3;

    int sum = a + b + c; // a + b를 어딘가에 임시 저장. int temp = a + b;
                         // int sum = temp + c;

    return 0;
}
