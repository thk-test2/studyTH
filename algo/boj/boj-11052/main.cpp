#include <iostream>

using namespace std;

int P[10001];
int memo[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}

	memo[1] = P[1];
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			memo[i] = max(memo[i], P[j] + memo[i - j]);
		}
	}
	cout << memo[N];
	return 0;
}