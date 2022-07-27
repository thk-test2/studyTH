#include <iostream>

struct A
{
    int data;
};
struct B
{
    int data;
    B() = default;
};
struct C
{
    int data;
    C() {}
};

int main()
{
    A a1{ };
    A a2{ 1 };
    B b1{ };
    B b2{ 1 };
    C c1{ };
    // C c2{1};
}