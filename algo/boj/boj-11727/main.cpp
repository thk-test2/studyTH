#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	long long memo[1001];
	memset(memo, 0, sizeof(memo));

	memo[1] = 1; memo[2] = 3;
	for (int i = 3; i <= N; ++i) {
		memo[i] = memo[i - 1] + memo[i - 2] * 2;
		memo[i] %= 10007;
	}
	cout << memo[N];
	return 0;
}