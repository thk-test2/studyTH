#include <iostream>

using namespace std;

class Test
{
public:
    Test()  { cout << "Test()" << endl; }
    ~Test() { cout << "~Test()" << endl; }
    Test(const Test& t) { cout << "Copy" << endl; }
    Test(Test&& t) noexcept { cout << "Move" << endl; }

    Test& operator=(const Test& t)
    {
        cout << "Copy=" << endl;
        return *this;
    }
    Test& operator=(Test&& t) noexcept
    {
        cout << "Move=" << endl;
        return *this;
    }
};

int main()
{
    Test* p1 = new Test[2];

//    Test* p2 = new Test[4];

    // 1. 신규 버퍼는 메모리만 할당 해준다.
    Test* p2 = static_cast<Test*>(
                operator new(sizeof(Test) * 4));

    for (int i = 0; i< 2; i++) {
//        p2[i] = move(p1[i]); // move 대입이다.
//        new(&p2[i]) Test; // 디폴트 생성자 호출
//        new(&p2[i]) Test(p1[i]); // 복사 생성자 호출. placement new
//        new(&p2[i]) Test(move(p1[i])); // move 생성자
        new(&p2[i]) Test(move_if_noexcept(p1[i]));
    }

    // 2. 새로운 객체는 디폴트 생성자 호출
    for (int i = 2; i<4 ; i++) {
        new(&p2[i]) Test; // 디폴트 생성자 호출.
    }
}
