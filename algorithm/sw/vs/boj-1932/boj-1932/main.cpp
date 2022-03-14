#include <iostream>

using namespace std;

int tri[501][501];
int memo[501][501];
int N;

int travel(int i, int j) {
	if (i == N) return tri[i][j];
	if (memo[i][j] != -1) return memo[i][j];

	memo[i][j] = max(travel(i + 1, j) + tri[i][j], travel(i + 1, j + 1) + tri[i][j]);
	return memo[i][j];
}

void init() {
	for (int i = 1; i <= 500; ++i) {
		for (int j = 1; j <= 500; ++j) {
			memo[i][j] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			cin >> tri[i][j];
		}
	}
	init();
	cout << travel(1, 1);

	return 0;
}