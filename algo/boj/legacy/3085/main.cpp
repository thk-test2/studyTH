#include <iostream>

using namespace std;

void compare(char a[][50], int& maxCnt, int N, int i, int j) {
    int cnt = 1;
    for (int k = 0; k < N-1; k++) {
        if (a[i][k] == a[i][k+1])
            cnt++;
        else {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
        }
    }
    maxCnt = max(maxCnt, cnt);

    cnt = 1;
    for (int k = 0; k < N-1; k++) {
        if (a[k][j] == a[k+1][j])
            cnt++;
        else {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
        }
    }
    maxCnt = max(maxCnt, cnt);
}

int main()
{
    int N;
    cin >> N;
    char a[50][50];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int maxCnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j > 0) {
                swap(a[i][j], a[i][j-1]);
                compare(a, maxCnt, N, i, j);
                swap(a[i][j], a[i][j-1]);
            }
            if (j < N-1) {
                swap(a[i][j], a[i][j+1]);
                compare(a, maxCnt, N, i, j);
                swap(a[i][j], a[i][j+1]);
            }
            if (i > 0) {
                swap(a[i][j], a[i-1][j]);
                compare(a, maxCnt, N, i, j);
                swap(a[i][j], a[i-1][j]);
            }
            if (i < N-1) {
                swap(a[i][j], a[i+1][j]);
                compare(a, maxCnt, N, i, j);
                swap(a[i][j], a[i+1][j]);
            }
        }
    }
    cout << maxCnt;

    return 0;
}
