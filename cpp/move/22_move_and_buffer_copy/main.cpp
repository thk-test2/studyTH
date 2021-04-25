#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
    Test()  {}
    ~Test() {}
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

    for(int i = 0; i <2; i++) {
//        p2[i] = p1[i]; // copy 대입
        p2[i] = move(p1[i]);
    }

    vector<Test> v(2);
    v.resize(4); // 어떻게 구현되어 있길래 noexcept를 붙여야하고, Move 대입이 아닌 생성자가 불리는가
}
