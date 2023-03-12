#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int cost[10][10];
int memo[1 << 16][10];
//vector<vector<int>> memo;
int N;

int travel(int mask, int now) {
	if (mask == (1<<N)-1) {
		return cost[now][0] != 0 ? cost[now][0] : 987654321;
	}
	if (memo[mask][now] != 987654321)
		return memo[mask][now];
	
	//bitset<16> b = mask;
	for (int i = 0; i < N; ++i) {
		//if (b[i] == 0 && cost[now][i] != 0) {
		if (((mask >> i) & 1) == 0 && cost[now][i] != 0) {
			memo[mask][now] = min(memo[mask][now], travel(mask | (1 << i), i) + cost[now][i]);
		}
	}
	return memo[mask][now];
}

void init() {
	int limit = 1 << N;
	for (int i = 0; i < limit; ++i) {
		for (int j = 0; j < N; ++j) {
			memo[i][j] = 987654321;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> cost[i][j];
		}
	}
	init();
	//memo.assign(1<<N, vector<int>(N, 987654321));
	cout << travel(1 << 0, 0);
	return 0;
}