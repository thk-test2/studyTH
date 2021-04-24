#include <iostream>

using namespace std;

int g = 10;

int main()
{
    int v1 = 0, v2 = 0;

    auto f1 = [](int a) { return a + g; }; // ok.
               // class ClosureType{ };

//    auto f2 = [](int a) { return a + v1; }; // error.
    auto f3 = [v1](int a) { return a + v1; };
    auto f4 = [v1, v2](int a) { return a + v1 + v2; };

//    auto f5 = [v1](int a) { v1 = 10; return a + v1; }; // error
    auto f6 = [v1] (int a) mutable { v1 = 10; return a + v1; };

    auto f7 = [v1, v2](int a) { return a + v1 + v2; };

    cout << sizeof(f1) << endl;
    cout << sizeof(f7) << endl;

//    auto f8 = [v1, v2]() { v1 = 10; v2 = 20; };
    auto f9 = [v1, v2]() mutable { v1 = 10; v2 = 20; }; // operator()의 const를 제거
    f9();
    cout << v1 << ", " << v2 << endl; // 복사본을 변경한 것임(capture by copy)

    auto f10 = [&v1, &v2]() { v1 = 10; v2 = 20; };
    f10();
    cout << v1 << ", " << v2 << endl;

    return 0;
}
//class ClosureType
//{
//    int& v1;
//    int& v2;
//public:
//    ClosureType(int& a, int& b) : v1(a), v2(b) {}
//    int operator() const
//    {
//        v1 = 10;
//        v2 = 20;
//    }
//};
//auto f10 = ClosureType(v1, v2);

//class ClosureType
//{
//    int v1;
//    int v2;
//public:
//    ClosureType(int a, int b) : v1(a), v2(b) {}
//    int operator() const
//    {
//        return v1 + v2;
//    }
//};
//auto f7 = ClosureType(v1, v2);
