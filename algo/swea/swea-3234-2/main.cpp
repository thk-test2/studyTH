#include <iostream>
#include <cstring>

using namespace std;

int chu[9];
bool used[9];
long memo[10][520][520];
int N;

long checknode(int level, int leftState, int rightState, int leftSum, int rightSum)
{
	if (memo[level][leftState][rightState] != 0) 
		return memo[level][leftState][rightState];
	if (level == N) return memo[level][leftState][rightState] = 1;

	int answer = 0;
	for (int i = 0; i < N; ++i) {
		if (used[i]) continue;
		used[i] = true;
		leftState |= (1 << i);
		answer +=
			checknode(level + 1, leftState, rightState, leftSum + chu[i], rightSum);
		leftState &= ~(1 << i);
		
		if (leftSum >= rightSum + chu[i]) {
			rightState |= (1 << i);
			answer +=
				checknode(level + 1, leftState, rightState, leftSum, rightSum + chu[i]);
			rightState &= ~(1 << i);
		}
		used[i] = false;
	}
	return memo[level][leftState][rightState] = answer;
}

void init() {
	memset(memo, 0, sizeof(memo));
	memset(chu, 0, sizeof(chu));
	memset(used, false, sizeof(used));
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
		cout << "#" << test << " " << checknode(0, 0, 0, 0, 0) << "\n";
	}
	return 0;
}