#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 101;
constexpr auto DUMMY = 987654321;

int heap[MAX_SIZE];
int heapIdx[MAX_SIZE];
int hSize = 0;

bool compare(int a, int b) {
	return a < b;
}

void push(int val) {
	heap[++hSize] = val;
	heapIdx[val] = hSize;

	for (register int i = hSize; i > 1; i /= 2) {
		if (compare(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);

		heapIdx[heap[i]] = i;
		heapIdx[heap[i / 2]] = i / 2;
	}
}

int pop() {
	if (hSize <= 0) return 0;

	int val = heap[1];
	heap[1] = heap[hSize];
	heap[hSize--] = DUMMY;

	for (register int i = 1; i * 2 <= hSize; ) {
		int child = compare(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (compare(heap[i], heap[child])) break;
		swap(heap[i], heap[child]);

		heapIdx[heap[i]] = i;
		heapIdx[heap[child]] = child;

		i = child;
	}
	return val;
}

int findIdx(int val) {
	int i;
	for (i = 1; i <= hSize; i++) {
		if (heap[i] == val) break;
	}
	return i;
}

void deleteVal(int val) {
	//int i = findIdx(val); // 지울 값을 찾는데 O(N)의 시간이 걸림
	int i = heapIdx[val]; // idx를 배열에 저장하여 O(1)의 시간으로 단축. 배열 크기는 고민
	heap[i] = 0;
	heapIdx[i] = heapIdx[val];

	for (; i > 1; i /= 2) {
		if (compare(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);

		heapIdx[heap[i]] = i;
		heapIdx[heap[i / 2]] = i / 2;
	}
	pop();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, t;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> t;
			push(t);
		}

		deleteVal(1);
		deleteVal(13);

		cout << "#" << test << " ";
		for (int i = 0; i < N; i++) {
			cout << pop() << " ";
		}
		cout << "\n";
		hSize = 0;
	}
	return 0;
}