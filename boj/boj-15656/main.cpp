#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[7];
int temp[7];
int N, M;

void combi(vector<int>& v, int level) {
	if (level == M) {
		for (auto itr : v)
			cout << itr << " ";
		cout << "\n";
		return;
	}
	for (int k = 0; k < N; ++k) {
		v.push_back(arr[k]);
		combi(v, level + 1);
		v.pop_back();
	}
}

void combine(int start, int mid, int end) {
	int l = start, r = mid + 1, k = start;

	while (l <= mid && r <= end) {
		if (arr[l] < arr[r]) {
			temp[k++] = arr[l++];
		}
		else if (arr[l] > arr[r]) {
			temp[k++] = arr[r++];
		}
	}

	while (l <= mid) {
		temp[k++] = arr[l++];
	}
	while (r <= end) {
		temp[k++] = arr[r++];
	}
	for (int k = start; k <= end; ++k) {
		arr[k] = temp[k];
	}
}

void mergesort(int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergesort(start, mid);
	mergesort(mid + 1, end);
	combine(start, mid, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	//sort(arr, arr + N);
	mergesort(0, N - 1);
	vector<int> v;
	combi(v, 0);
	return 0;
}