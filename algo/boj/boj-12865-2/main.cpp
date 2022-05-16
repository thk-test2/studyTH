#include <iostream>

using namespace std;

int memo[101][100001];
int W[101], V[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> W[i] >> V[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= K; ++j) {
			if (W[i] <= j) {
				memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - W[i]] + V[i]);
			}
			else {
				memo[i][j] = memo[i - 1][j];
			}
		}
	}
	cout << memo[N][K];
	return 0;
}