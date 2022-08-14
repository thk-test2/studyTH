#include <iostream>

using namespace std;
constexpr auto SIZE = 100010;

struct Data {
	int num;
	int idx;
};

bool isPrior(Data& a, Data& b) {
	if (a.num == b.num) {
		return a.idx < b.idx;
	}
	return a.num < b.num;
}

Data heap[SIZE];
int heapIdx[SIZE];
int hSize = 0;

void insert(Data temp) {
	heap[++hSize] = temp;
	heapIdx[hSize] = hSize;

	for (int i = hSize; i > 1; i /= 2) {
		if (isPrior(heap[i / 2], heap[i])) return;
		swap(heap[i / 2], heap[i]);
		swap(heapIdx[heap[i / 2].idx], heapIdx[heap[i].idx]);
	}
}

void update(int idx, int val) {
	int i = heapIdx[idx];
	heap[i].num = val;

	for (; i > 1; i /= 2) {
		if (isPrior(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);
		swap(heapIdx[heap[i / 2].idx], heapIdx[heap[i].idx]);
	}

	for (; i * 2 + 1 <= hSize; ) {
		int child = isPrior(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (isPrior(heap[i], heap[child])) break;
		swap(heap[i], heap[child]);
		swap(heapIdx[heap[i].idx], heapIdx[heap[child].idx]);
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
		insert({ t, i });
	}

	cin >> M;
	int cmd, idx, v;
	for (int i = 0; i < M; ++i) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> idx >> v;
			update(idx, v);
		}
		else if (cmd == 2) {
			cout << heap[1].idx << "\n";
		}
	}
	return 0;
}