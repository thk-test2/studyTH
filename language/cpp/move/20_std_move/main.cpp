#include <iostream>

using namespace std;

class Test
{
public:
    Test()  {}
    ~Test() {}
    Test(const Test& t) { cout << "Copy" << endl; }
    Test(Test&& t)      { cout << "Move" << endl; }

    // 복사 생성자를 만들면 복사 대입 연산자를 만들듯, Move 생성자를 만들면 Move 대입도 만들어야함
    Test& operator=(const Test& t) { return *this; } // 복사 대입 연산자
    Test& operator=(Test&& t)      { return *this; } // move 대입 연산자
};

int main()
{
    Test t1;
    Test t2 = t1;      // Copy
    Test t3 = Test();  // Move
    Test t4 = static_cast<Test&&>(t1);  // Move
                       // 복사가 아닌 move 생성자를 호출해 달라.
    Test t5 = move(t2); // move가 내부적으로 위처럼 캐스팅한다.

    Test t6;
    Test t7 = t6; // 초기화. 복사 생성자
    t7 = t6;      // 대입.  대입 연산자

    t7 = move(t6);
}
