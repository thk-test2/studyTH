#include <iostream>
#include <vector>

using namespace std;

int arr[1001][1001];
// int dp[1001];
int dir_i[4] = {1, -1, 0, 0};
int dir_j[4] = {0, 0, 1, -1};

int N;
int max_cnt = 0;

void dfs(int i, int j, int cnt) {
    for (int index = 0; index < 4; index++) {
        int ni = i + dir_i[index];
        int nj = j + dir_j[index];

        if (ni < 0 || ni >= N || nj < 0 || nj >= N)
            continue;

        if (arr[i][j] == arr[ni][nj] - 1) {
            dfs(ni, nj, cnt+1);
        }
    }
    max_cnt = max(max_cnt, cnt);
}

int main()
{
    int T;
    cin >> T;

    for (int k= 0; k < T; k++) {
        cin >> N;
        int t;
        int min_pos = 1001;
        int prev_max = 0; max_cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> t;
                arr[i][j] = t;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dfs(i, j, 1);
                if (prev_max < max_cnt) {
                    prev_max = max_cnt;
                    min_pos = arr[i][j];
                } else if (prev_max == max_cnt && arr[i][j] < min_pos) {
                    min_pos = arr[i][j];
                }
                max_cnt = 0;
            }
        }
        cout << "#" << k+1 << " "
             << min_pos << " "
             << prev_max << "\n";
    }

    return 0;
}
