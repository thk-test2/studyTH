#include <iostream>

int main() {

    int n = 10;

    auto f1 = [=](int a, int b) { return a + b + n; };
    auto f2 = [=] { return 0 + n; };
    int(*f3)() = [=] { return 0 + n; };
    int(*f4)() = []()->int { return 0; }; 
}