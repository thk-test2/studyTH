#include <iostream>
#include <cstring>

using namespace std;

int N;
int chu[9];
bool used[9];
int memo[9][520][520];

int simulate(int level, int leftSum, int rightSum, int leftState, int rightState) {
	if (level == N) return 1;
	if (memo[level][leftState][rightState] != -1)
		return memo[level][leftState][rightState];

	int answer = 0;
	for (int i = 0; i < N; ++i) {
		if (used[i]) continue;
		used[i] = true;
		leftState |= (1 << i);
		answer += simulate(level + 1, leftSum + chu[i], rightSum, leftState, rightState);
		leftState &= ~(1 << i);

		if (leftSum >= rightSum + chu[i]) {
			rightState |= (1 << i);
			answer += simulate(level + 1, leftSum, rightSum + chu[i], leftState, rightState);
			rightState &= ~(1 << i);
		}
		used[i] = false;
	}
	return memo[level][leftState][rightState] = answer;
}

void init() {
	memset(used, false, sizeof(used));
	memset(memo, -1, sizeof(memo));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		init();
		for (int i = 0; i < N; ++i) {
			cin >> chu[i];
		}
		cout << "#" << test << " " << simulate(0, 0, 0, 0, 0) << "\n";
	}
	return 0;
}