#include <iostream>

using namespace std;
// 92681

int main()
{
    long S = 0;
    cin >> S;
    long bottom = 0, top = S;
    long n = 0, mid = 0;

    while (bottom <= top) {
        mid = (bottom + top) / 2;

        if (mid*(mid+1)/2 > S)
            top = mid - 1;
        else {
            n = mid;
            bottom = mid + 1;
        }
    }
    cout << n << endl;
    return 0;
}
