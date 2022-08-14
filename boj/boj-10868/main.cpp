#include <iostream>

using namespace std;

constexpr auto SIZE = 100001;

int arr[SIZE];
int tree[SIZE * 4];
int N, M;

int makeTree(int start, int end, int idx) {
	if (start == end) return tree[idx] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[idx] = min(makeTree(start, mid, 2 * idx),
		makeTree(mid + 1, end, 2 * idx + 1));
}

int query(int start, int end, int idx, int left, int right) {
	if (left > end || right < start) return 1000000001;
	if (start >= left && end <= right) return tree[idx];

	int mid = (start + end) / 2;
	return min(query(start, mid, 2 * idx, left, right),
		query(mid + 1, end, 2 * idx + 1, left, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	makeTree(1, N, 1);

	int left, right;
	for (int i = 0; i < M; ++i) {
		cin >> left >> right;
		cout << query(1, N, 1, left, right) << "\n";
	}
	return 0;
}