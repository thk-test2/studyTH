#include <iostream>
#include <vector>
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

//int main()
//{
//    vector<Test> v(2);
//    v.resize(4);
//    cout << "--" << endl;
//}

int main()
{
//    Test* p1 = new Test[2];
    Test* p1 = static_cast<Test*>(
                operator new(sizeof(Test) * 2));
    for (int i = 0; i< 2; i++)
        new(&p1[i]) Test;
    //---------------------placement new를 활용. 기본 생성자가 없을 수도 있으니

    Test* p2 = static_cast<Test*>(
                operator new(sizeof(Test) * 4));

    for (int i = 0; i< 2; i++) {
        new(&p2[i]) Test(move_if_noexcept(p1[i]));
    }

    for (int i = 2; i<4 ; i++) {
        new(&p2[i]) Test;
    }
    //----------------------------
    // 최초 버퍼 파괴
    for(int i = 1; i>=0; i--)
        p1[i].~Test();

    operator delete(p1);
    cout << "---" << endl;
    //----------------------------
    for(int i = 3; i>=0; i--)
        p2[i].~Test();

    operator delete(p2);
}
