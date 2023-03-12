#include <iostream>

using namespace std;

int arr[1000];
int best[1000];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		best[i] = 1;
	}

	int maximum = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				best[i] = max(best[i], best[j] + 1);
			}
		}
		maximum = max(maximum, best[i]);
	}
	cout << maximum;
	return 0;
}