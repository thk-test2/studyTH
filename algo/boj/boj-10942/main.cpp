#include <iostream>
#include <cstring>

using namespace std;

int arr[2001];
int memo[2001][2001];
int N, M;

int checknode(int S, int E) {
	if (memo[S][E] != -1) return memo[S][E];

	if (S == E) {
		memo[S][E] = 1;
	}
	else if (S == E - 1) {
		memo[S][E] = (arr[S] == arr[E] ? 1 : 0);
	}
	else if (S <= E - 2) {
		int ret = checknode(S + 1, E - 1);
		memo[S][E] = ((ret == 1 && arr[S] == arr[E]) ? 1 : 0);
	}
	return memo[S][E];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	memset(memo, -1, sizeof(memo));

	int S, E;
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> S >> E;
		cout << checknode(S, E) << "\n";
	}
	return 0;
}