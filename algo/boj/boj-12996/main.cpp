#include <iostream>
#include <cstring>

using namespace std;

constexpr auto MOD = 1000000007;
int memo[51][51][51][51];
int arr[3];

int checknode(int S, int s1, int s2, int s3) {
	if (S == 0) {
		if (s1 == 0 && s2 == 0 && s3 == 0)
			return 1;
		else
			return 0;
	}
	if (s1 < 0 || s2 < 0 || s3 < 0) return 0;
	if (memo[S][s1][s2][s3] != -1) return memo[S][s1][s2][s3];

	int ret = 0;
	ret += checknode(S - 1, s1 - 1, s2, s3); ret %= MOD;
	ret += checknode(S - 1, s1, s2 - 1, s3); ret %= MOD;
	ret += checknode(S - 1, s1, s2, s3 - 1); ret %= MOD;
	ret += checknode(S - 1, s1 - 1, s2 - 1, s3); ret %= MOD;
	ret += checknode(S - 1, s1 - 1, s2, s3 - 1); ret %= MOD;
	ret += checknode(S - 1, s1, s2 - 1, s3 - 1); ret %= MOD;
	ret += checknode(S - 1, s1 - 1, s2 - 1, s3 - 1); ret %= MOD;
	return memo[S][s1][s2][s3] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int S;
	cin >> S;
	for (int i = 0; i < 3; ++i) {
		cin >> arr[i];
	}
	if (S > arr[0] + arr[1] + arr[2]) {
		cout << 0;
		return 0;
	}
	memset(memo, -1, sizeof(memo));
	int ret = checknode(S, arr[0], arr[1], arr[2]);
	cout << ret;
	return 0;
}