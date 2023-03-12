#include <iostream>

using namespace std;

void foo(int a, int& b, double d) { b = 30; }
void goo() {}

template<typename F, typename ...Types>
decltype(auto) chronometry(F f, Types&& ... arg)
{
    return f(forward<Types>(arg)...);
}

int main()
{
    int x = 10;

    chronometry(&foo, 1, x, 3.4);
    chronometry(&goo);

    cout << x << endl; // 30
}
