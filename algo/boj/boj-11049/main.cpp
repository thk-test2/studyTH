#include <iostream>
#include <climits>

using namespace std;

int arr[501][2];
int memo[501][501];
int N;

int multi(int start, int end) {
	if (memo[start][end] != INT_MAX) return memo[start][end];
	if (start == end) return 0;
	if (start == end - 1) {
		return memo[start][end] = arr[start][0] * arr[start][1] * arr[end][1];
	}

	for (int i = start; i < end; ++i) {
		int memo1 = multi(start, i);
		int memo2 = multi(i + 1, end);
		int combine = arr[start][0] * arr[i][1] * arr[end][1];
		memo[start][end] = min(memo[start][end], memo1 + memo2 + combine);
	}
	return memo[start][end];
}

void init() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			memo[i][j] = INT_MAX;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	init();
	for (int i = 0; i < N; ++i) {
		cin >> arr[i][0] >> arr[i][1];
	}
	cout << multi(0, N - 1);
	return 0;
}