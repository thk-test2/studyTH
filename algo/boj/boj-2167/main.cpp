#include <iostream>

using namespace std;

int arr[301][301];
int sum[301][301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, K;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + arr[i][j] - sum[i - 1][j - 1];
		}
	}

	cin >> K;
	int i, j, x, y;
	for (int k = 1; k <= K; ++k) {
		cin >> i >> j >> x >> y;
		cout << sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] << "\n";
	}
	return 0;
}