#include <iostream>

using LREF = int&;
using RREF = int&&;

int main()
{
    int n = 10;

    // LREF&  r1 = n; // 1
    // LREF&& r2 = n;  // 2
    // RREF&  r3 = n;  // 3
    RREF&& r4 = n;  // 4
}