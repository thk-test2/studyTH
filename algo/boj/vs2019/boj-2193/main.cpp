#include <iostream>

using namespace std;

long long memo[91][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;

	memo[1][0] = 0, memo[1][1] = 1;
	memo[2][0] = 1, memo[2][1] = 0;
	for (int i = 3; i <= N; ++i) {
		memo[i][0] = memo[i - 1][0] + memo[i - 1][1];
		memo[i][1] = memo[i - 1][0];
	}
	cout << memo[N][0] + memo[N][1];
	return 0;
}