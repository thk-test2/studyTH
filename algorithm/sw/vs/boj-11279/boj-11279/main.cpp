#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 100001;

int heap[MAX_SIZE];
int heapSize = 0;

void push(int val) {
	if (heapSize + 1 >= MAX_SIZE)
		return;

	heap[++heapSize] = val;
	for (register int current = heapSize; current > 1; current /= 2) {
		if (heap[current] <= heap[current / 2]) break;
		swap(heap[current], heap[current / 2]);
	}
}

int pop() {
	if (heapSize <= 0) return 0;

	int val = heap[1];
	heap[1] = heap[heapSize];
	heap[heapSize--] = -1; // 비교의 편리함을 위해

	for (register int current = 1; current * 2 <= heapSize;) {
		int child = heap[current * 2] > heap[current * 2 + 1] ?
			current * 2 : current * 2 + 1;

		if (heap[current] >= heap[child]) break;
		swap(heap[current], heap[child]);
		current = child;
	}
	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, x;
	cin >> N;
	for (register int i = 0; i < N; ++i) {
		cin >> x;
		if (x != 0) {
			push(x);
		}
		else {
			cout << pop() << "\n";
		}
	}
	return 0;
}