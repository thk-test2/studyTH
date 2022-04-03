#include <iostream>
#include <cstring>

using namespace std;

int memo[501][501];
int arr[501];

int travel(int start, int end) {
	if (start == end) return memo[start][end] = arr[start];
	if (memo[start][end] != 0) return memo[start][end];

	int case1 = travel(start, end - 1);
	int case2 = travel(start + 1, end);

	if (start == end - 1) {
		memo[start][end] = arr[start] + arr[end];
	}
	else {
		int sum1 = 0, sum2 = 0;
		for (int i = start; i <= end - 1; ++i)
			sum1 += arr[i];
		for (int i = start + 1; i <= end; ++i)
			sum2 += arr[i];
		memo[start][end] = min(case1 + sum1 + arr[end], case2 + sum2 + arr[start]);
	}
	return memo[start][end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, K;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		memset(memo, 0, sizeof(memo));
		memset(arr, 0, sizeof(arr));
		cin >> K;
		for (int i = 0; i < K; ++i) {
			cin >> arr[i];
		}

		//for (int i = 0; i < K; ++i)
		//	memo[i][i] = v[i];

		//for (int i = 0; i < K; ++i) {
		//	for (int j = 0; j < K; ++j) {
		//		if (i == j) continue;
		//		memo[i][j] = min(memo[i][j - 1] + memo[i][j - 1] + v[j],
		//			memo[i+1][j] + memo[i+1][j] + v[i]);
		//	}
		//}
		cout << "#" << test << " " << travel(0, K-1) << "\n";
	}
	return 0;
}