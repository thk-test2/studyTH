#include <iostream>

using namespace std;

int arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int sum = 0, maximum = -10000001;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (i < K) {
			sum += arr[i];
		}
		else {
			maximum = max(maximum, sum);
			sum = sum - arr[i - K] + arr[i];
		}
	}
	maximum = max(maximum, sum);
	cout << maximum;
	return 0;
}