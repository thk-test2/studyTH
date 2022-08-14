#include <iostream>

using namespace std;

int memo[4][50001];
int presum[50001];
int arr[50001];
int N, S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		presum[i] = presum[i - 1] + arr[i];
	}

	cin >> S;

	for (int i = 1; i <= 3; ++i) {
		for (int j = i * S; j <= N; ++j) {
			memo[i][j] = max(memo[i][j - 1],
				memo[i - 1][j - S] + presum[j] - presum[j - S]);
		}
	}
	cout << memo[3][N];
	return 0;
}