#include <iostream>

using namespace std;

int T, N, B, t;
int H[10000] = { 0 };

void combi(int idx, int height, int& minimum, bool Select[]) {
	if (height >= B) {
		minimum = min(minimum, height - B);
		return;
	}
	for (int i = idx; i < N; i++) {
		if (Select[i]) continue;
		Select[i] = true;
		combi(i, height + H[i], minimum, Select);
		Select[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int test = 1; test <= T; test++) {
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> t;
			H[i] = t;
		}
		bool Select[10000] = { false };
		int minimum = 987654321;
		combi(0, 0, minimum, Select);

		cout << "#" << test << " " << minimum << "\n";
	}

	return 0;
}