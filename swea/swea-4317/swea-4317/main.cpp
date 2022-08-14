#include <iostream>

using namespace std;

struct Position {
	int x = 0;
	int y = 0;
};

Position zeroPos[2500];
int zeroCnt = 0;

int waper[10][25];
bool visited[10][25];
int W, H;
int max_cnt = 0;

void setVisited(int y, int x, bool val) {
	for (int i = y; i < y + 2; ++i) {
		for (int j = x; j < x + 2; ++j) {
			visited[i][j] = val;
		}
	}
}

bool canFill(int y, int x) {
	if (y >= H - 1 || x >= W - 1) return false;

	for (int i = y; i < y + 2; ++i) {
		for (int j = x; j < x + 2; ++j) {
			if (visited[i][j] || waper[i][j] == 1)
				return false;
		}
	}
	return true;
}

int dy[4] = { -2, 2, 0, 0 };
int dx[4] = { 0, 0, -2, 2 };

void dfs(int index, int cnt) {
	if (index >= zeroCnt) {
		max_cnt = max(max_cnt, cnt);
		return;
	}

	int i = zeroPos[index].x, j = zeroPos[index].y;

	if (visited[i][j])
		dfs(index + 1, cnt);
	
	if (canFill(i, j)) {
		setVisited(i, j, true);
		dfs(index+1, cnt + 1);
		setVisited(i, j, false);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> W >> H;
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> waper[i][j];
				visited[i][j] = false;

				if (waper[i][j] == 0) {
					zeroPos[zeroCnt++] = { i, j };
				}
			}
		}
		dfs(0, 0);

		cout << "#" << test << " " << max_cnt << "\n";
		max_cnt = 0; zeroCnt = 0;
	}

	return 0;
}