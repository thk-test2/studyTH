#include<iostream>

using namespace std;

using ll = long long;
constexpr auto SIZE = 1000010;
constexpr auto DIVIDER = 1000000007;

ll arr[SIZE];
ll tree[SIZE * 4];

ll init(int start, int end, int idx) {
	if (start == end) return tree[idx] = arr[start] % DIVIDER;
	int mid = (start + end) / 2;
	return tree[idx] = (init(start, mid, 2 * idx) 
		* init(mid + 1, end, 2 * idx + 1)) % DIVIDER;
}

ll query(int start, int end, int left, int right, int idx) {
	if (start > right || end < left) return 1;
	if (left <= start && right >= end) return tree[idx];
	int mid = (start + end) / 2;
	return (query(start, mid, left, right, 2 * idx) 
		* query(mid + 1, end, left, right, 2 * idx + 1)) % DIVIDER;
}

void change(int start, int end, int idx, int arr_idx, ll new_val) {
	if (start > arr_idx || end < arr_idx) return;
	if (start == end) { tree[idx] = new_val; return; }

	int mid = (start + end) / 2;
	change(start, mid, 2 * idx, arr_idx, new_val);
	change(mid + 1, end, 2 * idx + 1, arr_idx, new_val);
	tree[idx] = tree[idx * 2] * tree[idx * 2 + 1] % DIVIDER;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;

	for (register int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	init(1, N, 1);
	
	ll a, b, c;
	for (register int i = 1; i <= M+K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) 
			change(1, N, 1, b, c);
		else
			cout << query(1, N, b, c, 1) << "\n";
	}
}