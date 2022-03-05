#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 101;

int heap[MAX_SIZE];
int heapIdx[MAX_SIZE];
int hSize = 0;

bool isMin(int a, int b) {
	return a < b;
}

void push(int val) {
	heap[++hSize] = val;
	heapIdx[val] = hSize;

	for (register int i = hSize; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;

		heapIdx[heap[i]] = i / 2;
		heapIdx[heap[i / 2]] = i;

		swap(heap[i / 2], heap[i]);
	}
}

int pop() {
	if (hSize <= 0) return 0;
	int val = heap[1];
	heap[1] = heap[hSize--];

	for (register int i = 1; i * 2 <= hSize; ) {
		int child = isMin(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;

		if (isMin(heap[i], heap[child])) break;

		heapIdx[heap[i]] = child;
		heapIdx[heap[child]] = i;

		swap(heap[i], heap[child]);

		i = child;
	}
	return val;
}

void deleteVal(int val) {
	int dIdx = heapIdx[val];
	heap[dIdx] = 0;
	heapIdx[heap[dIdx]] = dIdx;

	for (int i = dIdx; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;

		heapIdx[heap[i]] = i / 2;
		heapIdx[heap[i / 2]] = i;

		swap(heap[i / 2], heap[i]);
	}
	pop();
}

void updateVal(int from, int to) {
	int uIdx = heapIdx[from];
	heap[uIdx] = to;
	heapIdx[to] = uIdx;

	/* 위로 교체 */
	for (int i = uIdx; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;
		heapIdx[heap[i]] = i / 2;
		heapIdx[heap[i / 2]] = i;
		swap(heap[i / 2], heap[i]);
	}

	/* 아래로 교체 */
	/* i * 2 => i * 2 + 1이 된다. pop을 하지 않기 때문에 update이므로 index 관리가 필요. */
	for (int i = uIdx; i * 2 + 1 <= hSize; ) {
		int child = isMin(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (isMin(heap[i], heap[child])) break;

		heapIdx[heap[child]] = i;
		heapIdx[heap[i]] = child;
		swap(heap[i], heap[child]);
		i = child;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, t;
	cin >> T;
	for (register int test = 1; test <= T; ++test) {
		cin >> N;
		for (register int i = 0; i < N; ++i) {
			cin >> t;
			push(t);
		}
		
		//deleteVal(1);
		//deleteVal(13);

		updateVal(1, 9);
		updateVal(13, 3);

		cout << "#" << test << " ";
		for (register int i = 0; i < N; ++i) {
			cout << pop() << " ";
		}
		cout << "\n";
		hSize = 0;
	}

	return 0;
}