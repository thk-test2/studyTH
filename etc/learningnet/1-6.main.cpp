#include <iostream>

int square(int a)
{
    return a * a;
}
double square(double a)
{
    return a * a;
}
int main()
{
    printf("%p\n", &square);    // 1
    auto p1 = square;       // 2
    int(&r1)(int) = square;     // 3
    int(*p2)(int) = square;     // 4
}
