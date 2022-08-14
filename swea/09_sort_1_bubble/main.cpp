#include <iostream>

using namespace std;

constexpr auto SIZE = 10000;

int arr[SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < N-1; ++i) {
		for (int j = i+1; j < N; ++j) {
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);
		}
	}
	for (int i = 0; i < N; ++i)
		cout << arr[i] << "\n";
	return 0;
}