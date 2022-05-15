#include <iostream>

using namespace std;

int memo[1001][10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	int cnt = 10, prev_cnt;
	memo[1][0] = memo[1][1] = memo[1][2] = memo[1][3] = memo[1][4]
		= memo[1][5] = memo[1][6] = memo[1][7] = memo[1][8] = memo[1][9] = 1;
	for (int i = 2; i <= N; ++i) {
		prev_cnt = cnt;
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k) {
				memo[i][j] += memo[i - 1][k];
				memo[i][j] %= 10007;
			}
			cnt += memo[i][j];
		}
		cnt -= prev_cnt;
		cnt %= 10007;
	}
	cout << cnt;
	return 0;
}