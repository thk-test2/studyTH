#include <iostream>

using namespace std;

int arr[1001];
int memo[1001];
int memoR[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; ++i) {
		memo[i] = 1;
		for (int j = 1; j <= i; ++j) {
			if (arr[j] < arr[i] && memo[i] < memo[j] + 1) {
				memo[i] = memo[j] + 1;
			}
		}
	}

	for (int i = N; i >= 1; --i) {
		memoR[i] = 1;
		for (int j = N; j >= i; --j) {
			if (arr[j] < arr[i] && memoR[i] < memoR[j] + 1) {
				memoR[i] = memoR[j] + 1;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; ++i) {
		answer = max(answer, memo[i] + memoR[i] - 1);
	}
	cout << answer;
	return 0;
}