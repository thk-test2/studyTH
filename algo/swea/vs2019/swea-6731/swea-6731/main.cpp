#include <iostream>

using namespace std;

int arr[1001][1001];
int candidate[1001][1001];
int N;

bool isSame() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (candidate[i][j] != arr[i][j])
				return false;
		}
	}
	return true;
}

void flip(int I, int J) {
	for (int j = 0; j < N; ++j) {
		candidate[I][j] = !candidate[I][j];
	}
	for (int i = 0; i < N; ++i) {
		if (i == I) continue;
		candidate[i][J] = !candidate[i][J];
	}
}

int minimum = 987654321;
bool selected[1001][1001];

void init() {
	minimum = 987654321;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			selected[i][j] = false;
			candidate[i][j] = 0;
		}
	}
}

void travel(int I, int J, int cnt) {
	if (isSame()) {
		minimum = min(minimum, cnt);
		return;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (selected[i][j]) continue;
			selected[i][j] = true;
			flip(i, j);
			travel(i, j, cnt + 1);
			selected[i][j] = false;
			flip(i, j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		string str;
		for (int i = 0; i < N; ++i) {
			cin >> str;
			for (int j = 0; j < N; ++j) {
				arr[i][j] = str[j] == 'W' ? 0 : 1;
			}
		}
		init();
		travel(0, 0, 0);
		cout << "#" << test << " " << minimum << "\n";
	}
	return 0;
}