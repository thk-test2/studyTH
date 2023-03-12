#include <iostream>
#include <cstring>

using namespace std;

int arr[3][100001];
int memo[3][100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		for (int i = 1; i <= 2; ++i) {
			for (int j = 1; j <= N; ++j) {
				cin >> arr[i][j];
			}
		}
		memo[1][1] = arr[1][1], memo[2][1] = arr[2][1];

		memo[1][2] = arr[2][1] + arr[1][2];
		memo[2][2] = arr[1][1] + arr[2][2];
		for (int i = 3; i <= N; ++i) {
			memo[1][i] = max(memo[2][i - 1] + arr[1][i],
				memo[2][i - 2] + arr[1][i]);

			memo[2][i] = max(memo[1][i - 1] + arr[2][i],
				memo[1][i - 2] + arr[2][i]);
		}
		cout << max(memo[1][N], memo[2][N]) << "\n";

		memset(arr, 0, sizeof(arr));
		memset(memo, 0, sizeof(memo));
	}
	return 0;
}