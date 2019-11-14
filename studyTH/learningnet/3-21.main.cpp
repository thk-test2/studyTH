#include <iostream>

using namespace std;

void foo(int& a)       { cout << "int&" << endl; }
void foo(const int& a) { cout << "const int&" << endl; }
void foo(int&& a)      { cout << "int&&" << endl; }

int main()
{
    int n = 10;
    const int c = 10;
    
    int&  r1 = n;
    int&& r2 = 10;

    foo(n);
    foo(c);
    foo(r1);
    foo(r2);
}