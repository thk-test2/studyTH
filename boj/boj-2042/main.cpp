#include <iostream>

using namespace std;

constexpr auto SIZE = 1000001;
using ll = long long;

ll arr[SIZE];
ll tree[SIZE * 4];
int N, M, K;

ll makeTree(int start, int end, int idx) {
	if (start == end) return tree[idx] = arr[start];
	int mid = (start + end) / 2;
	ll left = makeTree(start, mid, idx * 2);
	ll right = makeTree(mid + 1, end, idx * 2 + 1);
	return tree[idx] = left + right;
}

ll query(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];

	int mid = (start + end) / 2;
	ll leftVal = query(start, mid, idx * 2, left, right);
	ll rightVal = query(mid + 1, end, idx * 2 + 1, left, right);
	return leftVal + rightVal;
}

void update(int start, int end, int idx, int target, ll newVal) {
	if (start == end) {
		tree[idx] = newVal; return;
	}
	int mid = (start + end) / 2;
	if (target <= mid)
		update(start, mid, idx * 2, target, newVal);
	else
		update(mid + 1, end, idx * 2 + 1, target, newVal);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	makeTree(1, N, 1);
	int a, b;
	ll c;
	for (int i = 1; i <= M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, N, 1, b, c);
		}
		else {
			ll ret = query(1, N, 1, b, c);
			cout << ret << "\n";
		}
	}
	return 0;
}