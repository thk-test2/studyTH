#include <iostream>

using namespace std;

// n+1Cr+1 = nCr + nCr+1
long int a[31][31];

int main() {
    int T;
    cin >> T;

    a[1][0] = 1;
    a[1][1] = 1;

    for (int i = 2; i<= 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else {
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
        }
    }

    for (int i = 0; i<T ; i++) {
        int N, M;
        cin >> N >> M;
        cout << a[M][N] << endl;
    }

    return 0;
}

//int main() {
//    int T, N, M;
//    cin >> T;
//    for (int i = 0; i< T; i++) {
//        cin >> N;
//        cin >> M;
//        long long sol = 1;
//        for (int j = M; j > M-N; j--) {
//            sol *= j;
//        }
//        for (int k = N; k > 0; k--) {
//            sol /= k;
//        }
//        cout << sol << endl;
//    }
//    return 0;
//}
