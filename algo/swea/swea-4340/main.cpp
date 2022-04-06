#include <iostream>

using namespace std;

int arr[53][53];
bool visited[53][53];
int N;
int minLength = 987654321;

int dirI_A[] = { 0, 0, 1, -1 };
int dirJ_A[] = { 1, -1, 0, 0 };

int dirI_B[] = {-1, 1, 0, 0};
int dirJ_B[] = {0, 0, 1, -1};
int inputDirB[2][4] = { { 3, 2, 0, 1 }, { 2, 3, 1, 0 } };

int memo[53][53][4];

struct Node {
	int i, j, inputDir;
};
Node path[3000];

void savePath(int length) {
	for (int k = 0; k < length; ++k) {
		int di = path[k].i;
		int dj = path[k].j;
		int inputDir = path[k].inputDir;
		memo[di][dj][inputDir] = k + 1;
	}
}

void travel(int i, int j, int length, int inputDir) {
	int left = N * 2 - i - j + 1;
	if (length + left >= minLength) return;

	if (length > memo[i][j][inputDir]) return;
	if (i == N && j == N + 1) {
		minLength = length;
		savePath(length);
		return;
	}

	int current = arr[i][j];
	if (current == 0) return;
	else if (current <= 2) {
		int nI = i + dirI_A[inputDir], nJ = j + dirJ_A[inputDir];
		if (!visited[nI][nJ]) {
			visited[nI][nJ] = true;
			path[length] = { nI, nJ, inputDir };
			travel(nI, nJ, length + 1, inputDir);
			visited[nI][nJ] = false;
		}
	}
	else if (current >= 3) {
		int nI = i + dirI_B[inputDir], nJ = j + dirJ_B[inputDir];
		if (!visited[nI][nJ]) {
			visited[nI][nJ] = true;
			path[length] = { nI, nJ, inputDirB[0][inputDir] };
			travel(nI, nJ, length + 1, inputDirB[0][inputDir]);
			visited[nI][nJ] = false;
		}

		nI = i - dirI_B[inputDir], nJ = j - dirJ_B[inputDir];
		if (!visited[nI][nJ]) {
			visited[nI][nJ] = true;
			path[length] = { nI, nJ, inputDirB[1][inputDir] };
			travel(nI, nJ, length + 1, inputDirB[1][inputDir]);
			visited[nI][nJ] = false;
		}
	}
}

void init() {
	minLength = 987654321;
	for (int i = 0; i < 53; ++i) {
		for (int j = 0; j < 53; ++j) {
			arr[i][j] = 0;
			visited[i][j] = false;
			for (int k = 0; k < 4; ++k)
				memo[i][j][k] = 987654321;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		init();
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> arr[i][j];
			}
			arr[N][N + 1] = 1;
			visited[1][1] = true;
		}
		travel(1, 1, 0, 0);
		cout << "#" << test << " " << minLength << "\n";
	}
	return 0;
}