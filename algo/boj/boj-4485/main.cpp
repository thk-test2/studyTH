#include <iostream>
#include <queue>

using namespace std;

constexpr auto SIZE = 126;
constexpr auto INF = 987654321;
using pos = pair<int, int>;

int arr[SIZE][SIZE];
int dist[SIZE][SIZE];
int N = 1;
int answer = INF;

int dirI[] = { -1, 1, 0, 0 };
int dirJ[] = { 0, 0, -1, 1 };

void bfs() {
	queue<pos> q;
	q.push({ 0, 0 });
	dist[0][0] = arr[0][0];

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();
		int i = cur.first, j = cur.second;

		for (int k = 0; k < 4; ++k) {
			int nI = i + dirI[k], nJ = j + dirJ[k];
			if (nI < 0 || nI >= N || nJ < 0 || nJ >= N) continue;
			if (dist[nI][nJ] > dist[i][j] + arr[nI][nJ]) {
				dist[nI][nJ] = dist[i][j] + arr[nI][nJ];
				q.push({ nI, nJ });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int test = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> arr[i][j];
				dist[i][j] = INF;
			}
		}
		bfs();
		cout << "Problem " << test << ": " << dist[N - 1][N - 1] << "\n";
		++test;
	}
	return 0;
}