#include <iostream>
#include <algorithm>

//void Swap(int* x, int* y)
//{
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}

//void Swap(int& x, int& y)
//{
//    int temp = x;
//    x = y;
//    y = temp;
//}

namespace Util {
    template<typename T>
    void Swap(T& x, T& y)
    {
        T temp = x;
        x = y;
        y = temp;
    }
}

int main()
{
    int a = 10, b = 20;
//    Swap(&a, &b);
//    Swap(a, b);
//    Swap<int>(a, b);
//    Util::Swap<int>(a, b);
    std::swap(a, b);
    std::cout << a << ", " << b << std::endl;
    return 0;
}
