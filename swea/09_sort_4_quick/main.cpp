#include <iostream>

using namespace std;

int arr[100];

int partition(int left, int right) {
	int pivot_value = left;
	int store_index = pivot_value;

	for (int i = left + 1; i <= right; ++i) {
		if (arr[pivot_value] > arr[i]) {
			store_index++;
			swap(arr[i], arr[store_index]);
		}
	}
	swap(arr[pivot_value], arr[store_index]);
	pivot_value = store_index;
	return pivot_value;
}

void quicksort(int left, int right) {
	if (left < right) {
		int pivot = partition(left, right);
		quicksort(left, pivot - 1);
		quicksort(pivot + 1, right);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	quicksort(0, N - 1);

	for (int i = 0; i < N; ++i) {
		cout << arr[i] << "\n";
	}
	return 0;
}