#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 100001;

struct Node {
	int val = 0;
	unsigned int uVal = 0;
};

Node heap[MAX_SIZE];
int hSize = 0;

bool isMin(Node a, Node b) {
	if (a.uVal < b.uVal) return true;
	else if (a.uVal == b.uVal) {
		return a.val < b.val;
	}
	return false;
}

void insert(int val) {
	Node temp;
	temp.val = val; temp.uVal = abs(val);

	heap[++hSize] = temp;
	for (int i = hSize; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) return;
		swap(heap[i / 2], heap[i]);
	}
}

Node pop() {
	if (hSize <= 0) return Node{ 0, 0 };

	Node result = heap[1];
	heap[1] = heap[hSize];
	heap[hSize--] = { 987654321, 987654321 };

	for (int i = 1; i * 2 <= hSize; ) {
		int child = isMin(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (isMin(heap[i], heap[child])) break;
		swap(heap[i], heap[child]);
		i = child;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, t;
	cin >> N;
	for (register int i = 0; i < N; ++i) {
		cin >> t;
		if (t != 0) {
			insert(t);
		}
		else {
			cout << pop().val << "\n";
		}
	}
	return 0;
}