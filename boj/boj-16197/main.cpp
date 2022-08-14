#include <iostream>

using namespace std;

using pos = pair<int, int>;

pos c1, c2;
char arr[21][21];
int N, M;
int min_cnt = 987654321;

int diri[] = { -1, 1, 0, 0 };
int dirj[] = { 0, 0, -1, 1 };

bool oneDropped(pos c1, pos c2) {
	if (c1.first < 0 || c1.first >= N || c1.second < 0 || c1.second >= M) {
		if (c2.first >= 0 && c2.first < N && c2.second >= 0 && c2.second < M)
			return true;
	} else if (c2.first < 0 || c2.first >= N || c2.second < 0 || c2.second >= M) {
		if (c1.first >= 0 && c1.first < N && c1.second >= 0 && c1.second < M)
			return true;
	}
	return false;
}

bool twoDropped(pos c1, pos c2) {
	if ((c1.first < 0 || c1.first >= N || c1.second < 0 || c1.second >= M)
		&& (c2.first < 0 || c2.first >= N || c2.second < 0 || c2.second >= M)) {
		return true;
	}
	return false;
}

void checknode(pos c1, pos c2, int cnt) {
	if (twoDropped(c1, c2)) return;
	else if (oneDropped(c1, c2)) {
		min_cnt = min(min_cnt, cnt);
		return;
	}
	if (cnt >= 10) return;

	for (int k = 0; k < 4; ++k) {
		pos nc1 = { c1.first + diri[k], c1.second + dirj[k] };
		pos nc2 = { c2.first + diri[k], c2.second + dirj[k] };

		if (arr[nc1.first][nc1.second] == '#' && arr[nc2.first][nc2.second] == '#') {
			checknode(c1, c2, cnt + 1);
		}
		else if (arr[nc1.first][nc1.second] == '#') {
			checknode(c1, { nc2.first, nc2.second }, cnt + 1);
		}
		else if (arr[nc2.first][nc2.second] == '#') {
			checknode({ nc1.first, nc1.second }, c2, cnt + 1);
		}
		else {
			checknode({ nc1.first, nc1.second }, { nc2.first, nc2.second }, cnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string t;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		for (int j = 0; j < M; ++j) {
			arr[i][j] = t[j];
			if (t[j] == 'o') {
				if (cnt == 0) {
					c1.first = i, c1.second = j;
					cnt++;
				}
				else {
					c2.first = i, c2.second = j;
				}
			}
		}
	}
	checknode(c1, c2, 0);
	if (min_cnt != 987654321)
		cout << min_cnt;
	else
		cout << -1;
	return 0;
}