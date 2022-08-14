#include <iostream>
#include <cstring>

using namespace std;

constexpr auto SIZE = 100100;

struct Node {
	long n[3];
};

int arr[SIZE];
Node tree[SIZE * 4];

Node makeTree(int start, int end, int idx) {
	if (start == end) {
		int temp = arr[start];
		tree[idx].n[temp - 1] = 1;
		return tree[idx];
	}
	int mid = (start + end) / 2;
	Node leftNode = makeTree(start, mid, idx * 2);
	Node rightNode = makeTree(mid + 1, end, idx * 2 + 1);

	for (int i = 0; i < 3; ++i)
		tree[idx].n[i] = leftNode.n[i] + rightNode.n[i];
	return tree[idx];
}

Node query(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return Node{ 0, 0, 0 };
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	Node leftNode = query(start, mid, idx * 2, left, right);
	Node rightNode = query(mid + 1, end, idx * 2 + 1, left, right);

	Node ret{ 0, 0, 0 };
	for (int i = 0; i < 3; ++i)
		ret.n[i] = leftNode.n[i] + rightNode.n[i];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, Q;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		memset(arr, 0, sizeof(arr));
		memset(tree, 0, sizeof(tree));
		cin >> N >> Q;

		int n;
		for (int i = 1; i <= N; ++i) {
			cin >> n;
			arr[i] = n;
		}
		makeTree(1, N, 1);

		int left, right;
		cout << "#" << test << "\n";
		for (int i = 1; i <= Q; ++i) {
			cin >> left >> right;
			Node ret = query(1, N, 1, left, right);

			cout << ret.n[0] << " " << ret.n[1] << " " << ret.n[2] << "\n";
		}
	}
	return 0;
}