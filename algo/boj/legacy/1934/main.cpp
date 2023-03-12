#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int n;

    if (a < b)
        swap(a, b);

    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main()
{
    int T, A, B;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        int gc = gcd(A, B);
        cout << A * B / gc << endl;
    }
    return 0;
}
