#include <iostream>

using namespace std;

int Partition(int arr[], int start, int end) {
	int pivot = start, i = start + 1, j = end;
	while (i < j) {
		while (arr[pivot] > arr[i]) i++;
		while (arr[pivot] < arr[j]) j--;
		if (i > j) break;
		swap(arr[i], arr[j]);
	}
	swap(arr[pivot], arr[j]);
	pivot = j;
	return pivot;
}

void QuickSort(int arr[], int start, int end) {
	if (start < end) {
		int pivot = Partition(arr, start, end);
		QuickSort(arr, start, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

void Combine(int arr[], int temp[], int start, int mid, int end) {
	int k = start, i = start, j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= end) temp[k++] = arr[j++];

	for (int k = start; k <= end; ++k) {
		arr[k] = temp[k];
	}
}

void MergeSort(int arr[], int temp[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		MergeSort(arr, temp, start, mid);
		MergeSort(arr, temp, mid + 1, end);
		Combine(arr, temp, start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int arr[10] = { 4, 8, 2, 3, 9, 7, 1, 6, 10, 5 };
	int temp[10] = { 0, };

	QuickSort(arr, 0, 9);
	//MergeSort(arr, temp, 0, 9);

	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << "\n";
	}
	return 0;
}