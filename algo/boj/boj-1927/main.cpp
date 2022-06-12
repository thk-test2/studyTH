#include <iostream>

using namespace std;

constexpr auto SIZE = 100001;
int N;

int heap[SIZE];
int hSize;

void insert(int x) {
	heap[++hSize] = x;

	for (int i = hSize; i > 1; i /= 2) {
		if (heap[i / 2] <= heap[i]) break;
		swap(heap[i / 2], heap[i]);
	}
}

int pop() {
	if (hSize == 0) return 0;
	int ret = heap[1];
	heap[1] = heap[hSize--];
	for (int i = 1; i * 2 <= hSize; ) {
		int child = heap[i * 2] <= heap[i * 2 + 1] ? i * 2 : i * 2 + 1;
		if (heap[i] <= heap[child]) break;
		swap(heap[i], heap[child]);
		i = child;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	int x;
	for (int i = 0; i < N; ++i) {
		cin >> x;
		if (x) {
			insert(x);
		}
		else {
			cout << pop() << "\n";
		}
	}
	return 0;
}