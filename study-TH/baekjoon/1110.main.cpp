#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);

    unsigned N;
    cin >> N;

    // a는 1의 자리수, b는 10의 자리수
    unsigned a = 0;
    unsigned b = 0;

    unsigned N2 = N;

    int count = 0;
    while ( 1 ) {
        count++;

        a = N2%10;
        b = N2/10;

        N2 = 10*a + (a+b)%10;

        if (N2 == N)
            break;
    }
    cout << count << "\n";

    return 0;
}