#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 100;

int N;
int arr[MAX_SIZE];
int tree[MAX_SIZE * 4];

int initTree(int start, int end, int index) {
	if (start == end) {
		return tree[index] = arr[start];
	}
	int mid = (start + end) / 2;
	return tree[index] = initTree(start, mid, index * 2) + initTree(mid + 1, end, index * 2 + 1);
}

int sum(int start, int end, int index, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[index];
	int mid = (start + end) / 2;
	return sum(start, mid, index * 2, left, right) + sum(mid + 1, end, index * 2 + 1, left, right);
}

void update(int start, int end, int index, int target, int val) {
	if (target < start || target > end) return;
	if (start == end) {
		tree[index] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, index * 2, target, val);
	update(mid + 1, end, index * 2 + 1, target, val);
	tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	initTree(1, N, 1);
	cout << sum(1, N, 1, 2, 3) << "\n";
	cout << sum(1, N, 1, 1, 5) << "\n";
	cout << sum(1, N, 1, 4, 5) << "\n\n";

	update(1, N, 1, 2, 4);
	cout << sum(1, N, 1, 2, 3) << "\n";
	update(1, N, 1, 4, 6);
	cout << sum(1, N, 1, 4, 5) << "\n";
	return 0;
}