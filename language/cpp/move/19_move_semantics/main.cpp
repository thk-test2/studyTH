#include <iostream>

using namespace std;

class Test
{
    int* resource;
public:
    Test()  {}  // 자원 할당
    ~Test() {}  // 자원 해제

    // 복사 생성자: 깊은복사 또는 참조계수
    // 인자로 lvalue와 rvalue를 모두 받을 수 있다
    Test(const Test& t) { cout << "Copy" << endl; }

    // Move 생성자: 소유권 이전(자원 전달)
    // rvalue만 전달 받을 수 있다.
    Test(Test&& t)      { cout << "Move" << endl; }
};

Test foo()
{
    Test t;
    return t;
}
// The two move constructor calls are:
//   Move the temporary created by Foo("Hello") into the return value.
//   Move the temporary returned by the f() call into myObject.

int main()
{
    Test t1;
    Test t2 = t1;     // 복사 생성자
//    Test t3 = Test(); // Move 생성자. Move를 만들지 않으면 복사 생성자가 호출될 것. 하지만 낭비
//                      // 컴파일러가 최적화 해버려서 Copy 하나만 나옴
//                      //   g++ move3.cpp -fno-elide-constructors
    Test t4 = foo();
}
