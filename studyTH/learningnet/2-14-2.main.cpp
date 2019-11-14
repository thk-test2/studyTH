#include <iostream>

using namespace std;

void foo(string s)      { cout << s << endl; }
void foo(const char* s) {  }

int main()
{
    foo( "hello"s ); 
}