#include <iostream>
#include <algorithm>

using namespace std;

bool visited[100][100];
char area[100][100];

void checkarea(int i, int j, int N, int M, int& cnt) {
    if (visited[i][j] == false && area[i][j] == '1') {
        visited[i][j] = true;
        cnt++;

        if (i < N-1)
            checkarea(i+1, j, N, M, cnt);
        if (j < M-1)
            checkarea(i, j+1, N, M, cnt);
        if (i > 0)
            checkarea(i-1, j, N, M, cnt);
        if (j > 0)
            checkarea(i, j-1, N, M, cnt);
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int r, c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = false;
            area[i][j] = '0';
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        area[r-1][c-1] = '1';
    }

    int max_cnt = 0;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            int cnt = 0;
            if (visited[i][j] == false && area[i][j] == '1') {
                checkarea(i, j, N, M, cnt);
                max_cnt = max(max_cnt, cnt);
            }
        }
    }
    cout << max_cnt;

    return 0;
}
