#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> A, dp;
	int N, t;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		A.push_back(t);
		dp.push_back(t);
	}

	int answer = dp[0];
	for (int i = 0; i < N-1; ++i) {
		for (int j = i+1; j < N; ++j) {
			if (A[j] > A[i]) {
				dp[j] = max(dp[j], dp[i] + A[j]);
				answer = max(answer, dp[j]);
			}
		}
	}
	cout << answer;
	return 0;
}