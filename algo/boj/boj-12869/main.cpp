#include <iostream>

using namespace std;
constexpr auto INF = 987654321;

int memo[61][61][61];
int scv[3];
int N;

int sub(int x, int y) {
	return x >= y ? x - y : 0;
}

int checknode(int hp1, int hp2, int hp3) {
	if (!hp1 && !hp2 && !hp3) return 0;
	if (memo[hp1][hp2][hp3] != INF) return memo[hp1][hp2][hp3];
	
	if (hp1) {
		memo[hp1][hp2][hp3] = min(memo[hp1][hp2][hp3],
			checknode(sub(hp1, 9), sub(hp2, 3), sub(hp3, 1)) + 1);
		memo[hp1][hp2][hp3] = min(memo[hp1][hp2][hp3],
			checknode(sub(hp1, 9), sub(hp2, 1), sub(hp3, 3)) + 1);
	}
	if (hp2) {
		memo[hp1][hp2][hp3] = min(memo[hp1][hp2][hp3],
			checknode(sub(hp1, 3), sub(hp2, 9), sub(hp3, 1)) + 1);
		memo[hp1][hp2][hp3] = min(memo[hp1][hp2][hp3],
			checknode(sub(hp1, 1), sub(hp2, 9), sub(hp3, 3)) + 1);
	}
	if (hp3) {
		memo[hp1][hp2][hp3] = min(memo[hp1][hp2][hp3],
			checknode(sub(hp1, 3), sub(hp2, 1), sub(hp3, 9)) + 1);
		memo[hp1][hp2][hp3] = min(memo[hp1][hp2][hp3],
			checknode(sub(hp1, 1), sub(hp2, 3), sub(hp3, 9)) + 1);
	}
	return memo[hp1][hp2][hp3];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i <= 60; ++i)
		for (int j = 0; j <= 60; ++j)
			for (int k = 0; k <= 60; ++k)
				memo[i][j][k] = INF;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> scv[i];

	cout << checknode(scv[0], scv[1], scv[2]);
	return 0;
}