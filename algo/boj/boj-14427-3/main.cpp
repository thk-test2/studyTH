#include <iostream>

using namespace std;

constexpr auto SIZE = 100001;

struct Node {
	int val;
	int idx;
};

int heapIdx[SIZE];
Node heap[SIZE];
int hSize;

bool Comp(Node a, Node b) {
	if (a.val == b.val) {
		return a.idx < b.idx;
	}
	return a.val < b.val;
}

void insert(int val, int idx) {
	heap[++hSize] = { val, idx };
	heapIdx[idx] = hSize;

	for (int i = hSize; i > 1; i /= 2) {
		if (Comp(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);
		swap(heapIdx[heap[i / 2].idx], heapIdx[heap[i].idx]);
	}
}

void update(int target, int newVal) {
	int i = heapIdx[target];
	heap[i].val = newVal;

	for (; i > 1; i /= 2) {
		if (Comp(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);
		swap(heapIdx[heap[i / 2].idx], heapIdx[heap[i].idx]);
	}

	for (; i * 2 + 1<= hSize; ) {
		int child = Comp(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (Comp(heap[i], heap[child])) break;
		swap(heap[i], heap[child]);
		swap(heapIdx[heap[i].idx], heapIdx[heap[child].idx]);
		i = child;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, n;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> n;
		insert(n, i);
	}
	
	cin >> M;
	int cmd, target, newVal;
	for (int i = 0; i < M; ++i) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> target >> newVal;
			update(target, newVal);
		}
		else {
			cout << heap[1].idx << "\n";
		}
	}
	return 0;
}