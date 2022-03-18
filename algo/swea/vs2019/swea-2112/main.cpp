#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int film[13][20];
int answer = 99;
int D, W, K;

bool check() {
	bool result = true;
	for (int j = 0; j < W; ++j) {
		int cnt = 1;
		for (int i = 1; i < D; ++i) {
			if (film[i][j] == film[i - 1][j]) {
				cnt++;
				if (cnt == K) break;
			}
			else {
				cnt = 1;
			}
		}
		if (cnt < K) {
			result = false;
			break;
		}
	}
	return result;
}

void testColumn(int index, int level) {
	if (check()) {
		if (answer > level) answer = level;
		return;
	}
	if (answer - 1 <= level) return;
	
	int temp[20];
	for (int i = index; i < D; ++i) {
		memcpy(temp, &film[i][0], sizeof(int) * W);
		for (int j = 0; j < 2; ++j) {
			fill(&film[i][0], &film[i][0]+W, j);
			testColumn(i + 1, level + 1);
		}
		memcpy(&film[i][0], temp, sizeof(int) * W);
		//if (answer <= level + 1) return;
	}
}

void init() {
	memset(film, 0, sizeof(film));
	answer = 99;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		init();
		cin >> D >> W >> K;
		for (int i = 0; i < D; ++i) {
			for (int j = 0; j < W; ++j) {
				cin >> film[i][j];
			}
		}
		testColumn(0, 0);
		if (answer != 99)
			cout << "#" << test << " " << answer << "\n";
		else
			cout << "#" << test << " " << 0 << "\n";
	}

	return 0;
}