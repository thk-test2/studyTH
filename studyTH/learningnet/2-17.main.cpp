#include <iostream>
using namespace std;

class Test
{
public:
    Test(int a, int b)           { cout << "1" << endl; }
    Test(initializer_list<int> ) { cout << "2" << endl; }
};
int main()
{
    Test t1(1, 1);
    Test t2{ 1, 1 };
    Test t3 = { 1,1 };
}