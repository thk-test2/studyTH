#include <iostream>

class Test
{
public:
    explicit Test(int n) {}
    explicit Test(int a, int b) {}
};

int main()
{
    Test t1{ 1 };     // 1
    // Test t2 = { 1 };  // 2
    // Test t3{ 1,2 };   // 3
    Test t4 = { 1,2 };// 4
}