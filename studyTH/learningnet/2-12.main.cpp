#include <iostream>
#include <vector>

using namespace std;

template<typename T> void print_first_element(T& c)
{
    auto p = &c; 

    cout << *p << endl;  // c의 첫번째 요소인 1이 출력되어야 합니다.
}

int main()
{
    int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
    print_first_element(x);

    vector<int> v(x, x + 10);
    print_first_element(v);
}