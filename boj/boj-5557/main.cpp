#include <iostream>
#include <cstring>

using namespace std;

using ll = long long;

ll memo[101][21];
int arr[101];
int N;

ll checknode(int level, int currentVal) {
	if (memo[level][currentVal] != -1) return memo[level][currentVal];

	if (level == N - 1) {
		return memo[level][currentVal] = (currentVal == arr[N - 1] ? 1 : 0);
	}

	ll cnt = 0;
	int nextVal = currentVal + arr[level];
	if (nextVal <= 20) {
		cnt += checknode(level + 1, nextVal);
	}

	nextVal = currentVal - arr[level];
	if (nextVal >= 0) {
		cnt += checknode(level + 1, nextVal);
	}
	return memo[level][currentVal] = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	memset(memo, -1, sizeof(memo));
	cout << checknode(1, arr[0]);

	return 0;
}