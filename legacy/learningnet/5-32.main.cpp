

#include <iostream>

using namespace std;

int main()
{
    int v1 = 10;
    int v2 = 10;

    // auto f1 = [=](int a) mutable { v1 = a; };
    // auto f2 = [&](int a)         { v2 = a; };

    // f1(20);
    // f2(20);

    // cout << v1 << ", " << v2 << endl;

    auto f1 = [v1, &v2]() {};
    auto f2 = [v1, &]() {};
    auto f3 = [&v1, =]() {};
    auto f4 = [=, v2]() {}; 
}
