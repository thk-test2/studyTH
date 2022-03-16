#include <iostream>

using namespace std;

int N;
int chu[9];
bool used[9];
int memo[9][520][520];

int setState(int state, int n, bool on) {
	return on ? state |= (1 << n) : state ^= (1 << n);
}

int getResult(int stage, int lState, int rState, int lWeight, int rWeight) {
	if (stage >= N) return 1;

	if (memo[stage][lState][rState] != -1) return memo[stage][lState][rState];

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (used[i]) continue;
		used[i] = true;
		lState = setState(lState, i, true);
		cnt += getResult(stage + 1, lState, rState, lWeight + chu[i], rWeight);
		lState = setState(lState, i, false);
		used[i] = false;

		if (lWeight >= rWeight + chu[i]) {
			used[i] = true;
			rState = setState(rState, i, true);
			cnt += getResult(stage + 1, lState, rState, lWeight, rWeight + chu[i]);
			rState = setState(rState, i, false);
			used[i] = false;
		}
		
		memo[stage][lState][rState] = cnt;
	}
	return cnt;
}

void init() {
	int limit = (1 << N) + 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < limit; ++j) {
			for (int k = 0; k < limit; ++k) {
				memo[i][j][k] = -1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> chu[i];
			used[i] = false;
		}

		init();
		int ret = getResult(0, 0, 0, 0, 0);
		cout << "#" << test << " " << ret << "\n";
	}
	return 0;
}