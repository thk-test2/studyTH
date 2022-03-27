#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 100001;

int nums[MAX_SIZE];
int tree[MAX_SIZE * 4];

int makeTree(int start, int end, int idx) {
	if (start == end) {
		return tree[idx] = nums[start];
	}
	int mid = (start + end) / 2;
	return tree[idx] = makeTree(start, mid, idx * 2) + makeTree(mid + 1, end, idx * 2 + 1);
}

int getSum(int start, int end, int idx, int left, int right) {
	if (end < left || start > right) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return getSum(start, mid, idx * 2, left, right) + getSum(mid + 1, end, idx * 2 + 1, left, right);
}

void update(int start, int end, int idx, int target, int val) {
	if (start > target || end < target) return;
	if (start == end) {
		tree[idx] = nums[start] = val;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, idx * 2, target, val);
	update(mid + 1, end, idx * 2 + 1, target, val);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> nums[i];
	}
	makeTree(1, N, 1);

	int left, right;
	for (int i = 1; i <= M; ++i) {
		cin >> left >> right;
		cout << getSum(1, N, 1, left, right) << "\n";
	}
	return 0;
}