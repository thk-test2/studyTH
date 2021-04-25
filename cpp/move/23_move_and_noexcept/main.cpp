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
    Test* p2 = new Test[4];

    for (int i = 0; i< 2; i++) {
        p2[i] = move(p1[i]); // move로 옮길 때는 예외 안정성을 보장해야 한다.
    }

    Test t1;
    Test t2 = t1;       // copy
    Test t3 = move(t2); // move

    bool b = is_nothrow_move_constructible<Test>::value;
    cout << b << endl;

    Test t4 = move_if_noexcept(t1);
}
