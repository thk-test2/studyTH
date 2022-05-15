#include <iostream>

using namespace std;

int arr[20];
int N;

int binary_search(int target) {
	int start = 0, end = N - 1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] > target) {
			end = mid - 1;
		}
		else if (arr[mid] < target) {
			start = mid + 1;
		}
		else break;
	}
	return mid;
}

int lower_bound(int target) {
	int start = 0, end = N - 1;
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] >= target) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return start;
}

int upper_bound(int target) {
	int start = 0, end = N - 1;
	int mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] <= target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return end + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int target;
	cin >> target;

	cout << binary_search(target) << "\n";
	cout << lower_bound(target) << "\n";
	cout << upper_bound(target) << "\n";
	return 0;
}