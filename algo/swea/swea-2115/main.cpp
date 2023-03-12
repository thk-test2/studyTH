#include <iostream>
#include <cstring>

using namespace std;

int N, M, C;
int arr[10][10];

int getMaxVal(int I, int J) {
    int memo[6][31];
    memset(memo, 0, sizeof(memo));

    for (int k = 1; k <= M; ++k) {
        for (int c = 1; c <= C; ++c) {
            if (c >= arr[I][J + k - 1]) memo[k][c] = max(memo[k - 1][c],
                memo[k - 1][c - arr[I][J + k - 1]] + arr[I][J + k - 1] * arr[I][J + k - 1]);
            else
                memo[k][c] = memo[k - 1][c];
        }
    }
    return memo[M][C];
}

int checknode() {
    int retA = 0, retB = 0;
    int maxAB = 0;
    for (int ay = 0; ay < N; ay++) {
        for (int ax = 0; ax <= N - M; ax++) {
            retA = getMaxVal(ay, ax);

            int start = ax + M;
            for (int by = ay; by < N; by++) {
                for (int bx = start; bx <= N - M; bx++) {
                    retB = getMaxVal(by, bx);
                    maxAB = max(maxAB, retA + retB);
                }
                start = 0;
            }
        }
    }
    return maxAB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> N >> M >> C;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> arr[i][j];
            }
        }
        cout << "#" << test << " " << checknode() << "\n";
    }
    return 0;
}