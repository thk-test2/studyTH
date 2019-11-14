#include <iostream>
using namespace std;

int x = 10;

class Test
{
public:
    int value1 = ++x;
    int value2;

    Test() = default;
};

int main()
{
    int y[10];
    
    Test t1;
    Test t2{};
    
    cout << t1.value1 << endl;
    cout << t1.value2 << endl;
    cout << t2.value1 << endl;
    cout << t2.value2 << endl;
    cout << x << endl;
}