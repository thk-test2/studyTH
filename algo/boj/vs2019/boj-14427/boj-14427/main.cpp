#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 200100;

struct Node {
	int val;
	int id;
};

Node heap[MAX_SIZE];
int heapIdx[MAX_SIZE];
int hSize = 0;

bool isMin(Node a, Node b) {
	if (a.val < b.val) return true;
	else if (a.val == b.val && a.id < b.id) return true;

	return false;
}

void push(int idx, int val) {
	heap[++hSize].val = val;
	heap[hSize].id = idx;
	heapIdx[idx] = hSize;

	for (register int i = hSize; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;

		heapIdx[heap[i].id] = i / 2;
		heapIdx[heap[i / 2].id] = i;

		swap(heap[i / 2], heap[i]);
	}
}

void updateVal(int from, int to) {
	int uIdx = heapIdx[from];
	heap[uIdx].val = to;
	//heapIdx[to] = uIdx;

	/* 위로 교체 */
	for (int i = uIdx; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;
		heapIdx[heap[i].id] = i / 2;
		heapIdx[heap[i / 2].id] = i;
		swap(heap[i / 2], heap[i]);
	}

	/* 아래로 교체 */
	for (int i = uIdx; i * 2 <= hSize; ) {
		int child = isMin(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (isMin(heap[i], heap[child])) break;

		heapIdx[heap[i].id] = child;
		heapIdx[heap[child].id] = i;
		
		swap(heap[i], heap[child]);
		i = child;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, a;
	cin >> N;
	for (register int i = 1; i <= N; ++i) {
		cin >> a;
		push(i, a);
	}
	
	int M, cmd, from, to;
	cin >> M;
	for (register int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 2) {
			cout << heap[1].id << "\n";
		}
		else {
			cin >> from >> to;
			updateVal(from, to);
		}
	}
	return 0;
}