#include <iostream>

using namespace std;

constexpr auto MAX_CPU = 5;
constexpr auto MAX_PACKET = 1010;

int heap[MAX_CPU+1];
int hSize;

int T[MAX_PACKET];
int L[MAX_PACKET];

bool isMin(int a, int b) {
	return a < b;
}

bool push(int val) {
	if (hSize >= 5) return false;

	heap[++hSize] = val;
	for (int i = hSize; i > 1; i /= 2) {
		if (isMin(heap[i / 2], heap[i])) break;
		swap(heap[i / 2], heap[i]);
	}
	return true;
}

int pop() {
	if (hSize <= 0) return 0;
	int ret = heap[1];
	heap[1] = heap[hSize--];

	for (int i = 1; i * 2 <= hSize;) {
		int child = isMin(heap[i * 2], heap[i * 2 + 1]) ? i * 2 : i * 2 + 1;
		if (isMin(heap[i], heap[child])) break;

		swap(heap[i], heap[child]);
		i = child;
	}
	return ret;
}

int max_cpu = 0;

bool simul(int N) {
	for (register int i = 1; i <= N; ++i) {
		if (i == 1 || hSize == 0) {
			int endTime = T[i] + L[i];
			push(endTime);
			continue;
		}
		int Ttotal;
		int leastEndTime = heap[1];

		while (hSize > 0 && leastEndTime < T[i]) {
			leastEndTime = pop();
		}

		T[i] > leastEndTime ? Ttotal = L[i]
			: Ttotal = (leastEndTime - T[i]) + L[i];

		if (Ttotal > 10) {
			// 다른 CPU에 넣어봄 (ERROR:다른 CPU의 endTime에 더해줘야 함)
			if (!push(L[i])) return false;
			max_cpu = max(max_cpu, hSize);
			continue;
		}
		// 현재 CPU 개수에서 처리될 수 있음. 아까 pop() 안 했으니 해줌.
		pop();
		leastEndTime = max(leastEndTime, T[i]) + L[i];
		if (!push(leastEndTime)) return false;
		max_cpu = max(max_cpu, hSize);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, N, t, l;
	cin >> K;
	for (register int test = 1; test <= K; ++test) {
		cin >> N;
		for (register int i = 1; i <= N; ++i) {
			cin >> t >> l;
			T[i] = t; L[i] = l;
		}

		if (simul(N))
			cout << "#" << test << " " << max_cpu << "\n";
		else
			cout << "#" << test << " " << -1 << "\n";
		hSize = 0; max_cpu = 0;
	}
	return 0;
}