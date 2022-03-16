#include <iostream>
#include <stack>

using namespace std;

int arr[500][500];
int dp[500][500];
bool visited[500][500];
int M, N;

int dfs(int i, int j) {
    if (visited[i][j] == true)
        return dp[i][j];
    if (i == M-1 && j == N-1)
        return 1;

    if (j > 0) {
        if (arr[i][j-1] < arr[i][j]) {
            dp[i][j] += dfs(i, j-1);
        }
    }
    if (i > 0) {
        if (arr[i-1][j] < arr[i][j]) {
            dp[i][j] += dfs(i-1, j);
        }
    }
    if (j < N-1) {
        if (arr[i][j+1] < arr[i][j]) {
            dp[i][j] += dfs(i, j+1);
        }
    }
    if (i < M-1) {
        if (arr[i+1][j] < arr[i][j]) {
            dp[i][j] += dfs(i+1, j);
        }
    }
    visited[i][j] = true;
    return dp[i][j];
}

void dfs_s(stack<pair<int, int>>& s, int& cnt) {
    while (!s.empty()) {
        pair<int, int> t = s.top();
        s.pop();
        int i = t.first;
        int j = t.second;
//        cout << i << ", " << j << endl;

        if (i == M-1 && j == N-1)
            cnt++;

        if (j > 0) {
            if (arr[i][j-1] < arr[i][j] && !visited[i][j-1]) {
                s.push(make_pair(i, j-1));
                dfs_s(s, cnt);
//                visited[i][j-1] = true;
            }
        }
        if (i > 0) {
            if (arr[i-1][j] < arr[i][j] && !visited[i-1][j]) {
                s.push(make_pair(i-1, j));
                dfs_s(s, cnt);r
//                visited[i-1][j] = true;
            }
        }
        if (j < N-1) {
            if (arr[i][j+1] < arr[i][j] && !visited[i][j+1]) {
                s.push(make_pair(i, j+1));
                dfs_s(s, cnt);
//                visited[i][j+1] = true;
            }
        }
        if (i < M-1) {
            if (arr[i+1][j] < arr[i][j] && !visited[i+1][j]) {
                s.push(make_pair(i+1, j));
                dfs_s(s, cnt);
//                visited[i+1][j] = true;
            }
        }
    }
}

int main()
{
    int n;
    cin >> M >> N;

    for (int i=0; i < M; i++) {
        for (int j=0; j < N; j++) {
            cin >> n;
            arr[i][j] = n;
            dp[i][j] = 0;
            visited[i][j] = false;
        }
    }
//    dfs(0, 0);
//    cout << dp[0][0];

    stack<pair<int, int>> s;
    s.push(make_pair(0, 0));

    int cnt = 0;
    dfs_s(s, cnt);
    cout << cnt;

    return 0;
}
