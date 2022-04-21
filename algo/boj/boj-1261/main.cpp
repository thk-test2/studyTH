#include <iostream>
#include <queue>

using namespace std;

constexpr auto INF = 987654321;

int arr[101][101];
int dist[101][101];

int dirI[] = { -1, 1, 0, 0 };
int dirJ[] = { 0, 0, -1, 1 };
int N, M;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int i = cur.first, j = cur.second;
			int nI = i + dirI[k], nJ = j + dirJ[k];
			if (nI < 0 || nI >= N || nJ < 0 || nJ >= M) continue;

			if (arr[nI][nJ] == 1) {
				if (dist[nI][nJ] > dist[i][j] + 1) {
					dist[nI][nJ] = dist[i][j] + 1;
					q.push({ nI, nJ });
				}
			}
			else {
				if (dist[nI][nJ] > dist[i][j]) {
					dist[nI][nJ] = dist[i][j];
					q.push({ nI, nJ });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N;
	string input;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		for (int j = 0; j < M; ++j) {
			arr[i][j] = input[j] - '0';
			dist[i][j] = INF;
		}
	}
	bfs();
	cout << dist[N-1][M-1];
	return 0;
}