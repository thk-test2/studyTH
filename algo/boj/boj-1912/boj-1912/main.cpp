#include <iostream>

using namespace std;

int arr[100000];
int best[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	
	int maximum = best[0] = arr[0];
	for (int i = 1; i < N; ++i) {
		best[i] = arr[i];
		best[i] = max(best[i], best[i - 1] + arr[i]);
		maximum = max(maximum, best[i]);
	}
	cout << maximum;
	return 0;
}