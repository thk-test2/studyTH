#include <iostream>


inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

template<typename T> void foo(T op)
{
    bool b = op(1, 2);
}

int g = 0;

int main()
{
    // Less    f1;
    // Greater f2;

    // foo(cmp1);
    // foo(cmp2);
    // foo(f1);
    // foo(f2);

    // auto f1 = [](int a) { return 0; };
    // auto f2 = [](int a) { if (a == 1) return 0; else return 2; };
    // auto f3 = [](int a) { if (a == 1) return 0; else return 2.3; };
    // auto f4 = [](int a) { if (a == 1) return 1.2; else return 2.3; }; 

    int v1 = 10;
    int v2 = 10;

    auto f1 = [](int a) { return a + g; };      // 1
    auto f2 = [](int a) { return a + v1; };     // 2
    auto f3 = [=](int a) { return a + v1; };    // 3
    auto f4 = [=](int a) { v1 = a; };           // 4
}

