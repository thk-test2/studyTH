#include <iostream>
#include <cstring>

using namespace std;
constexpr auto MOD = 1000000007;

using ll = long long;

ll memo[2501][2501];
int N;

ll dp(int left, int right) {
	if (left < 0 || right < 0) return 0;
	if (left + right == 0)
		return !left && !right ? 1 : 0;

	ll& ret = memo[left][right];
	if (ret) return ret;

	ret = 0;
	ret += dp(left - 1, right);
	ret %= MOD;
	if (left < right) {
		ret += dp(left, right - 1);
		ret %= MOD;
	}
	return ret % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memo[1][1] = 1, memo[2][2] = 2;
	dp(2500, 2500);

	int t;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		if (t % 2 == 1) {
			cout << 0 << "\n";
		}
		else {
			cout << dp(t / 2, t / 2) << "\n";
		}
	}
	return 0;
}