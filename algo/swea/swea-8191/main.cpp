#include <iostream>

using namespace std;

int S[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, a;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> a;
			S[a] = i;
		}
		int cnt = 1;
		for (int i = 2; i <= N; ++i) {
			if (S[i] < S[i - 1]) cnt++;
		}
		cout << "#" << test << " " << cnt << "\n";
	}
	return 0;
}