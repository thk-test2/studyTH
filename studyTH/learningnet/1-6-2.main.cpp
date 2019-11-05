#include <iostream>

using namespace std;

// template<typename T>
// void foo(T a)    { cout << "T" << endl; }   // 1
void foo(double) { cout << "double" << endl; }  // 2
// void foo(int)    { cout << "int" << endl; } // 3
void foo(...)    { cout << "..." << endl; } // 4

int main()
{
    foo(3);
}