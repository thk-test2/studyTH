#include <iostream>

using namespace std;

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
        // ......

    A a1, a2{};
    B b1, b2{};
    C c1, c2{};

    cout << a1.data << "," << a2.data << ", ";
    cout << b1.data << "," << b2.data << ", ";
    cout << c1.data << "," << c2.data << endl;
}
