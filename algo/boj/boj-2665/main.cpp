#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr auto INF = 987654321;

int arr[51][51];
int dp[51][51];
int N;

int di[4] = { -1, 1, 0, 0 };
int dj[4] = { 0, 0, -1, 1 };

void dijkstra() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dp[0][0] = 0;

	while (!q.empty()) {
		int ci = q.front().first;
		int cj = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int ni = ci + di[k], nj = cj + dj[k];
			if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
			
			if (arr[ni][nj] == 0) {
				if (dp[ni][nj] > dp[ci][cj] + 1) {
					dp[ni][nj] = dp[ci][cj] + 1;
					q.push({ ni, nj });
				}
			}
			else {
				if (dp[ni][nj] > dp[ci][cj]) {
					dp[ni][nj] = dp[ci][cj];
					q.push({ ni, nj });
				}
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		for (int j = 0; j < N; ++j) {
			arr[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			dp[i][j] = INF;
		}
	}
	dijkstra();
	cout << dp[N - 1][N - 1];
	return 0;
}