#include <iostream>

using namespace std;

class Test
{
    int data = 0;
public:
    void foo() // Test* const this
    {
        int v = 0;
//        auto f = []() { data = 10; }; // error
        auto f1 = [this]() { this->data = 10; }; // 주소의 값이니까 실제 그 member
        f1();
        cout << data << endl; // 10

        // 멤버 데이터를 복사본으로 캡쳐 - C++ 17
        auto f2 = [*this]() mutable { data = 20; };
        f2();
        cout << data << endl;
    }
};

int main()
{
    Test t;
    t.foo();
    return 0;
}
