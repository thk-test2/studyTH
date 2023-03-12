#include <iostream>

using namespace std;
constexpr auto SIZE = 100010;

struct Node {
	int val;
	int id;
};

Node arr[SIZE];
int tree[SIZE * 4];
int N, M;

int minIndex(Node a, Node b) {
	if (a.val < b.val)
		return a.id;
	else if (a.val == b.val)
		return min(a.id, b.id);
	else
		return b.id;
}

int initTree(int idx, int start, int end) {
	if (start == end) {
		return tree[idx] = arr[start].id;
	}
	int mid = (start + end) / 2;
	return tree[idx] = minIndex(arr[initTree(idx * 2, start, mid)],
		arr[initTree(idx * 2 + 1, mid + 1, end)]);
}

void update(int idx, int start, int end, int target, int val) {
	if (end < target || start > target) return;
	if (start == end) {	
		arr[start].val = val;
		tree[idx] = arr[start].id;
		return;
	}
	int mid = (start + end) / 2;
	update(idx * 2, start, mid, target, val);
	update(idx * 2 + 1, mid + 1, end, target, val);
	tree[idx] = minIndex(arr[tree[idx * 2]], arr[tree[idx * 2 + 1]]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> t;
		arr[i] = { t, i };
	}
	initTree(1, 1, N);
	cin >> M;
	int cmd, idx, v;
	for (int i = 0; i < M; ++i) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> idx >> v;
			update(1, 1, N, idx, v);
		}
		else if (cmd == 2) {
			cout << tree[1] << "\n";
		}
	}
	return 0;
}