#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	unsigned long long dp[101][101];
	memset(dp, 0, sizeof(dp));

	for (int j = 1; j < 10; ++j) {
		dp[1][j] = 1;
	}
	dp[1][0] = 0;

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	unsigned long long answer = 0;
	for (int j = 0; j < 10; ++j) {
		answer += dp[N][j];
	}
	cout << answer % 1000000000 << "\n";
	return 0;
}