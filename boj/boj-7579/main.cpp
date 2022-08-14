#include <iostream>

using namespace std;

int memory[101];
int cost[101];
int best[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, sum = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> memory[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = sum; j >= cost[i]; --j) {
			best[j] = max(best[j], best[j - cost[i]] + memory[i]);
		}
	}
	int i = 0;
	while (i < sum && best[i] < M) {
		++i;
	}
	cout << i;
	return 0;
}