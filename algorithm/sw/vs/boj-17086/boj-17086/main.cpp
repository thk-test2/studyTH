#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct Node {
	int i, j, cnt;
};
int N, M;
int Map[50][50];
int Minimum = INT_MAX;
queue<Node> q;

int di[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dj[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

void bfs(int i, int j) {
	q.push({ i, j, 0 });
	bool Visited[50][50] = { false };
	Visited[i][j] = true;

	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		if (Map[temp.i][temp.j] == 1) {
			Minimum = min(Minimum, temp.cnt);
			break;
		}
		for (int k = 0; k < 8; k++) {
			int ni = temp.i + di[k], nj = temp.j + dj[k];
			if (ni >= 0 && ni < N && nj >= 0 && nj < M && !Visited[ni][nj]) {
				Visited[ni][nj] = true;
				q.push({ ni, nj, temp.cnt + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> t;
			Map[i][j] = t;
		}
	}

	int Max_safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			bfs(i, j);
			Max_safe = max(Max_safe, Minimum);
			Minimum = INT_MAX;
		}
	}
	cout << Max_safe;
	return 0;
}