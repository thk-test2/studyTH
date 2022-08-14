#include <iostream>

using namespace std;
constexpr auto SIZE = 100001;

struct Node {
	int val;
	int id;
};

Node heap[SIZE];
int hSize;
int heapIdx[SIZE];

bool Compare(Node a, Node b) {
	if (a.val == b.val) return a.id < b.id;
	return a.val < b.val;
}

void insert(int val) {
	hSize++;
	heap[hSize] = { val, hSize };
	heapIdx[hSize] = hSize;

	for (int i = hSize; i > 1; i /= 2) {
		if (Compare(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);
		swap(heapIdx[heap[i].id], heapIdx[heap[i / 2].id]);
	}
}

void query(int idx, int newVal) {
	int target = heapIdx[idx];
	heap[target].val = newVal;

	for (int i = target; i > 1; i /= 2) {
		if (Compare(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);
		swap(heapIdx[heap[i].id], heapIdx[heap[i / 2].id]);
	}

	for (int i = target; i * 2 + 1 <= hSize; ) {
		int child = (Compare(heap[i * 2], heap[i * 2 + 1])) ? i * 2 : i * 2 + 1;
		if (Compare(heap[i], heap[child])) break;
		swap(heap[i], heap[child]);
		swap(heapIdx[heap[child].id], heapIdx[heap[i].id]);
		i = child;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, t;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> t;
		insert(t);
	}

	cin >> M;
	int cmd, idx, v;
	for (int i = 1; i <= M; ++i) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> idx >> v;
			query(idx, v);
		}
		else {
			cout << heap[1].id << "\n";
		}
	}
	return 0;
}