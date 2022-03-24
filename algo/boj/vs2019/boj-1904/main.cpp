#include <iostream>

using namespace std;

long long memo[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	
	memo[0] = 1;
	memo[1] = 2;
	memo[2] = 3;
	memo[3] = 5;

	for (int i = 4; i < N; ++i) {
		memo[i] = memo[i - 1] + memo[i - 2];
		memo[i] %= 15746;
	}
	cout << memo[N - 1];
	return 0;
}