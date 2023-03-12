#include <iostream>
#include <climits>

using namespace std;

int colorCost[1010][3];
int memo[1010][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int cost;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> cost;
			memo[i][j] = INT_MAX;
			colorCost[i][j] = cost;
			
		}
	}
	// 0 = R, 1 = G, 2 = B
	for (int i = 1; i <= N; ++i) {
		memo[i][0] = min(memo[i - 1][1], memo[i - 1][2]);
		memo[i][0] += colorCost[i][0];

		memo[i][1] = min(memo[i - 1][2], memo[i - 1][0]);
		memo[i][1] += colorCost[i][1];

		memo[i][2] = min(memo[i - 1][0], memo[i - 1][1]);
		memo[i][2] += colorCost[i][2];
	}

	cout << min(min(memo[N][0], memo[N][1]), memo[N][2]) << "\n";

	return 0;
}