#include <iostream>

using namespace std;

int arr[1025][1025];
long long sum[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}
	int x1, y1, x2, y2;
	for (int i = 0; i < M; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		long long answer = 0;
		answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
		cout << answer << "\n";
	}
	return 0;
}