#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[55][55];
int aCnt[55][55];
int memo[55][55][55][55];

void init() {
	memset(aCnt, 0, sizeof(aCnt));
	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			aCnt[i][j] = aCnt[i - 1][j] + aCnt[i][j - 1] - aCnt[i - 1][j - 1] + arr[i][j];
		}
	}
}

int getCnt(int y1, int y2, int x1, int x2) {
	int cnt = aCnt[y2][x2] - aCnt[y1 - 1][x2] - aCnt[y2][x1 - 1] + aCnt[y1 - 1][x1 - 1];
	return cnt;
}

int cutChoco(int y1, int y2, int x1, int x2) {
	if (y1 == y2 && x1 == x2) return 0;
	if (memo[y1][y2][x1][x2] != -1) return memo[y1][y2][x1][x2];

	int currentCnt = getCnt(y1, y2, x1, x2);
	memo[y1][y2][x1][x2] = 987654321;

	for (int i = y1; i < y2; ++i) {
		int temp1 = 0;
		temp1 += cutChoco(y1,     i, x1, x2);
		temp1 += cutChoco(i + 1, y2, x1, x2);
		memo[y1][y2][x1][x2] = min(memo[y1][y2][x1][x2], temp1 + currentCnt);
	}

	for (int j = x1; j < x2; ++j) {
		int temp2 = 0;
		temp2 += cutChoco(y1, y2, x1,     j);
		temp2 += cutChoco(y1, y2, j + 1, x2);
		memo[y1][y2][x1][x2] = min(memo[y1][y2][x1][x2], temp2 + currentCnt);
	}
	return memo[y1][y2][x1][x2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;

	for (int test = 1; test <= T; ++test) {
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				cin >> arr[i][j];
			}
		}
		init();
		int ret = cutChoco(1, N, 1, M);
		cout << "#" << test << " " << ret << "\n";
	}

	return 0;
}