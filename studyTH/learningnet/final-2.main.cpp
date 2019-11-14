#include <iostream>

using namespace std;

int main()
{
    auto f = [](auto a, auto b) { return a + b; };

    cout << f(1, 2)     << endl; // 3
    cout << f(1.1, 2.2) << endl; // 3.3
}