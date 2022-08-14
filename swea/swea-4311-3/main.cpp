#include <iostream>

using namespace std;

int op[4];
int num[10];
int best[1000];
int same_result[1000];
int made_num[1000];
int mSize;
int N, O, M, W;

void init() {
	mSize = 0;
	for (int i = 0; i < 1000; ++i) {
		best[i] = 999;
	}
}

void sortNumbers() {
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (num[j] < num[i])
				swap(num[j], num[i]);
		}
	}
}

void makeNum(int cnt, int maxcnt, string tmp) {
	if (cnt == maxcnt) {
		int made = tmp[0] - '0';
		for (int i = 1; i < maxcnt; ++i) {
			made = made * 10 + (tmp[i] - '0');
		}
		//cout << made << "\n";
		if (best[made] == 999) {
			best[made] = cnt;
			made_num[mSize++] = made;
		}
		return;
	}
	for (int k = 0; k < N; ++k) {
		tmp += (num[k] + '0');
		makeNum(cnt + 1, maxcnt, tmp);
		tmp.pop_back();
	}
}

void checknode(int cnt, int cur) {
	for (int i = 0; i < O; ++i) {
		for (int j = 0; j < mSize; ++j) {
			int nextVal = cur;
			int nextCnt = cnt + best[made_num[j]] + 1;
			if (nextCnt > M - 1) break;

			if (op[i] == 1) {
				if (cur + made_num[j] > 999) break;
				nextVal = cur + made_num[j];
			}
			else if (op[i] == 2) {
				if (cur - made_num[j] < 0) break;
				nextVal = cur - made_num[j];
			}
			else if (op[i] == 3) {
				if (cur * made_num[j] > 999) break;
				nextVal = cur * made_num[j];
			}
			else if (op[i] == 4) {
				if (made_num[j] == 0) continue;
				nextVal = cur / made_num[j];
			}
			if (same_result[nextVal] == 1) continue;
			if (best[nextVal] <= nextCnt) continue;

			best[nextVal] = nextCnt;
			same_result[nextVal] = 1;
			checknode(nextCnt, nextVal);
			same_result[nextVal] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N >> O >> M;
		init();
		for (int i = 0; i < N; ++i) {
			cin >> num[i];
		}
		for (int i = 0; i < O; ++i) {
			cin >> op[i];
		}
		sortNumbers();
		for (int i = 1; i <= 3; ++i)
			makeNum(0, i, "");

		cin >> W;
		if (best[W] != 999) {
			cout << "#" << test << " " << best[W] << "\n";
			continue;
		}
		for (int i = 0; i < mSize; ++i)
			checknode(best[made_num[i]], made_num[i]);

		if (best[W] != 999)
			cout << "#" << test << " " << best[W] + 1 << "\n";
		else
			cout << "#" << test << " " << -1 << "\n";
	}
	return 0;
}