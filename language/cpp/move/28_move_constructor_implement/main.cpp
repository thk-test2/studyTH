#include <iostream>
#include <memory.h>

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

class Buffer
{
    size_t sz;
    int* buf; // 사실 스마트 포인터를 쓰고 소멸자와 복사생성자, move생성자를 구현하지 않으면
              // 컴파일러가 알아서 move 생성자를 만들어 준다.
    string tag;
    Test test;
public:
    Buffer(size_t s, string t)
        : sz(s), tag(t), buf(new int[s]) {}
    ~Buffer() { delete[] buf; }

    // deep copy.
    Buffer(const Buffer& b) : sz(b.sz), tag(b.tag), test(b.test)
    {
        buf = new int[sz];
        memcpy(buf, b.buf, sizeof(int)*sz);
    }
    // move 생성자. 포인터만 복사하지 말고 모든 멤버들을 move로 옮기도록 작성한다.
    Buffer(Buffer&& b) noexcept
        : sz(move(b.sz)), tag(move(b.tag)), test(move(b.test))
    {
        buf = move(b.buf);
        b.buf = 0;   // 자원 release
    }
    // 대입 연산자 구현해보기.
    Buffer& operator=(const Buffer& b) {
        cout << "Buffer Copy=" << endl;
        sz = b.sz;
        tag = b.tag;
        test = b.test;
        return *this;
    }
    // move 대입 연산자 구현해보기.
    Buffer& operator=(Buffer&& b) {
        cout << "Buffer Move=" << endl;
        sz = move(b.sz);
        tag = move(b.tag);
        test = move(b.test);
        return *this;
    }
};

int main()
{
    Buffer b1(1024, "SHARED");
//    Buffer b2 = b1;  // copy

//    Buffer b2 = move(b1);

    Buffer b3(1024, "SHARED");
//    b3 = b1;
    b3 = move(b1);
}
