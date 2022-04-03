#include <iostream>
#include <cstring>

using namespace std;

int memo[501][501];
int arr[501];
int K;

int travel(int start, int end) {
	if (memo[start][end] != 987654321) return memo[start][end];
	if (start == end)
		return 0;
	if (start == end - 1)
		return memo[start][end] = arr[start] + arr[end];

	int sum = 0;
	for (int i = start; i <= end; ++i)
		sum += arr[i];

	for (int i = start; i < end; ++i) {
		int memo1 = travel(start, i);
		int memo2 = travel(i + 1, end);

		memo[start][end] = min(memo[start][end], memo1 + memo2 + sum);
	}
	return memo[start][end];
}

void init() {
	memset(arr, 0, sizeof(arr));
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			memo[i][j] = 987654321;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> K;
		init();
		for (int i = 0; i < K; ++i) {
			cin >> arr[i];
		}
		cout << travel(0, K-1) << "\n";
	}
	return 0;
}
