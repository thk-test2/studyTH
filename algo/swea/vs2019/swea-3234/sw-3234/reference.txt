#include <iostream>

using namespace std;

int T, N, t, Sum = 0;
long long answer = 0;
bool Select[9] = { false };
int Arr[9] = { 0 };
long long Exp[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
long long Factorial[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

void dfs(int Cnt, int leftSum, int rightSum) {
	if (Cnt == N) {
		answer++;
		return;
	}
	if (leftSum >= Sum - leftSum)
	{
		answer = answer + Exp[N - Cnt] * Factorial[N - Cnt];
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (Select[i]) continue;
		Select[i] = true;
		dfs(Cnt + 1, leftSum + Arr[i], rightSum);
		if (rightSum + Arr[i] <= leftSum)
			dfs(Cnt + 1, leftSum, rightSum + Arr[i]);
		Select[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> t;
			Arr[i] = t;
			Sum += t;
		}
		dfs(0, 0, 0);

		cout << "#" << test << " " << answer << "\n";
		answer = 0; Sum = 0;
	}

	return 0;
}