#include <iostream>

// BOJ 2042

using namespace std;

constexpr auto SIZE = 1000010;
using ll = long long;

ll arr[SIZE];
ll tree[SIZE * 4];

int N, M, K;

ll init(int start, int end, int index) {
	if (start == end) return tree[index] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[index] = init(start, mid, index * 2) + init(mid + 1, end, index * 2 + 1);
}

void update(int start, int end, int index, int target, ll diff) {
	if (target < start || target > end) return;
	tree[index] += diff;

	if (start == end) return;
	
	int mid = (start + end) / 2;
	update(start, mid, index * 2, target, diff);
	update(mid + 1, end, index * 2 + 1, target, diff);
}

ll sum(int start, int end, int index, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[index];

	int mid = (start + end) / 2;
	return sum(start, mid, index * 2, left, right) + sum(mid + 1, end, index * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (register int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	init(1, N, 1);

	ll a, b, c;
	for (register int i = 1; i <= M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - arr[b];
			arr[b] = c;
			update(1, N, 1, b, diff);
		}
		else if (a==2) {
			ll result = sum(1, N, 1, b, c);
			cout << result << "\n";
		}
	}

	return 0;
}