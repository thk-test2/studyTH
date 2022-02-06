#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int N;
int arr[101][101];
int dp[101][101] = {0};
int visited[101][101] = {false};
int minimum = INT_MAX;

int dir_i[4] = {-1, 1, 0, 0};
int dir_j[4] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    dp[0][0] = 0;

    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        int i = temp.first;
        int j = temp.second;
//        visited[i][j] = true;

        if (i == N-1 && j == N-1) {
            continue;
        }

        int sub_min;
        for (int index = 0; index<4; index++) {
            int ni = i + dir_i[index];
            int nj = j + dir_j[index];

//            if (visited[ni][nj])
//                continue;
            if (ni < 0 || ni >= N || nj < 0 || nj >= N)
                continue;

            int sub_min = dp[ni][nj];
            dp[ni][nj] = min(dp[ni][nj], dp[i][j] + arr[ni][nj]);
            if (dp[ni][nj] != sub_min) {
                q.push(make_pair(ni, nj));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int k = 0; k < T; k++) {
        cin >> N;
        minimum = INT_MAX;

        string t;
        for (int i = 0; i < N; i++) {
            cin >> t;
            for (int j = 0; j < N; j++) {
                arr[i][j] = t[j] - '0';
                dp[i][j] = 2000000000;
                visited[i][j] = false;
            }
        }
        bfs();
        cout << "#" << k+1 << " " << dp[N-1][N-1] << "\n";
    }
    return 0;
}
