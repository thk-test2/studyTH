#include <iostream>
#include <cstring>

using namespace std;
constexpr auto SIZE = 100001;

struct Node {
	int idx;
	int age;
	string name;
};

Node arr[SIZE];
Node sorted[SIZE];
int N;

bool compare(Node a, Node b) {
	if (a.age == b.age) {
		return a.idx < b.idx;
	}
	return a.age < b.age;
}

void merge(int start, int mid, int end) {
	//cout << start << ", " << mid << ", " << end << "\n";
	int i, j, k;
	i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end) {
		if (compare(arr[i], arr[j])) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	if (i > mid) {
		while (j <= end) {
			sorted[k++] = arr[j++];
		}
	}
	else {
		while (i <= mid) {
			sorted[k++] = arr[i++];
		}
	}
	for (int i = start; i <= end; ++i)
		arr[i] = sorted[i];
}

void merge_sort(int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, mid, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].idx = i;
	}
	merge_sort(0, N - 1);

	for (int i = 0; i < N; ++i) {
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
	return 0;
}