#include <iostream>
#include <climits>

using namespace std;

constexpr auto SIZE = 100100;
int heap[SIZE];
int hSize = 0;

void push(int val) {
	heap[++hSize] = val;

	for (int i = hSize; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i]) return;
		swap(heap[i / 2], heap[i]);
	}
}

int pop() {
	int ret = heap[1];
	heap[1] = heap[hSize];
	heap[hSize--] = INT_MAX;

	for (int i = 1; i * 2 <= hSize; ) {
		int child = heap[i * 2] < heap[i * 2 + 1] ? i * 2 : i * 2 + 1;
		if (heap[i] < heap[child]) break;
		swap(heap[i], heap[child]);
		i = child;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, n;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> n;
		push(n);
	}

	int t1, t2;
	int sum = 0;
	int prev_sum = sum;
	int cnt = 0;
	while (true) {
		if (cnt == N - 1) break;
		t1 = pop();
		t2 = pop();
		prev_sum = sum;
		sum += (t1 + t2);

		push(sum - prev_sum);
		cnt++;
	}
	cout << sum;
	return 0;
}