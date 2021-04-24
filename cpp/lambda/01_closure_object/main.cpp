#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

    //    sort(x, x+10, cmp);
    //    sort(x, x+10, less<int>());
    sort(x, x+10,
         [](int a, int b) {
        return a < b;
    });

    for(int i = 0; i< 10 ; i++) {
        cout << x[i] << ", ";
    }
    cout << endl;

    bool b = [](int a, int b) { return a < b; }(1, 2);
    cout << "b: " << b << endl;
    return 0;
}

//class ClosureType
//{
//public:
//    bool operator()(int a, int b) contst
//    {
//        return a < b;
//    }
//};
//sort(x, x+10, ClosureType());
