#include <iostream>

using namespace std;

unsigned A[9999] = {0,};

void not_self(unsigned N) {

    // cout << "N1:" << N << '\n';
    N = N + N/1000 + (N%1000)/100 + (N%100)/10 + N%10;
    // cout << "N2:" << N << '\n';

    if (N >= 10000)
        return;

    if ( A[N-1] != 0 )
        A[N-1] = 0;

    not_self(N);
}

int main() {
    for (int i=0; i< 9999; i++) {
        A[i] = i+1;
    }

    for (int i=0; i< 9999; i++) {
        not_self(i+1);
    }

    for (int i=0; i< 9999; i++) {
        if(A[i] != 0)
            cout << A[i] << '\n';
    }
    return 0;
}