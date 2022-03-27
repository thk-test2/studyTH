#include <iostream>

using namespace std;

int N, O, M, target;
int numbers[10];
int op[4];

int best[1000];
int sameResult[1000];

int make_num[10];
int make_cnt = 0;

int converted_num[1000];
int converted_cnt = 0;

void init() {
	for (int i = 0; i < 1000; ++i) {
		best[i] = 99;
		converted_num[i] = 0;
		sameResult[i] = 0;
	}
	make_cnt = 0;
	converted_cnt = 0;
}

void permut(int cnt, int total) {
	if (cnt == total) {
		int temp = 0;
		for (int i = total - 1; i >= 0; --i) {
			int exp = 1;
			for (int j = i; j > 0; --j) {
				exp *= 10;
			}
			temp += (make_num[total - 1 - i] * exp);
		}
		if (temp > 999) return;
		best[temp] = min(best[temp], total);
		return;
	}
	for (int i = 0; i < N; ++i) {
		make_num[make_cnt++] = numbers[i];
		permut(cnt + 1, total);
		make_num[make_cnt--] = 0;
	}
}

int getNextVal(int current, int cmd, int num) {
	if (cmd == 2) {
		return current - num;
	}
	else if (cmd == 3) {
		return current * num;
	}
	else if (cmd == 4) {
		return current / num;
	}
	return current + num;
}

void getResult(int cnt, int current) {
	for (int j = 0; j < O; ++j) {
		for (int i = 0; i < converted_cnt; ++i) {
			int num = converted_num[i];
			int nextCnt = cnt + best[num] + 1;
			if (nextCnt > M - 1) break;
			
			int cmd = op[j];
			if (cmd == 4 && num == 0) continue;

			int next = getNextVal(current, cmd, num);
			if (cmd == 1 && next > 999) break;
			if (cmd == 2 && next < 0) break;
			if (cmd == 3 && next > 999) break;
			if (sameResult[next] == 1) continue;
			if (best[next] <= nextCnt) continue;

			best[next] = nextCnt;
			sameResult[next] = 1;
			getResult(nextCnt, next);
			sameResult[next] = 0;
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
		for (int i = 0; i < N; ++i) {
			cin >> numbers[i];
			make_num[i] = 0;
		}
		for (int i = 0; i < O; ++i) {
			cin >> op[i];
		}
		cin >> target;

		init();
		for (int i = 1; i <= 3; ++i) {
			permut(0, i);
		}
		for (int i = 0; i < 1000; ++i) {
			if (best[i] != 99) {
				converted_num[converted_cnt++] = i;
			}
		}

		if (best[target] != 99) {
			cout << "#" << test << " " << best[target] << "\n";
			continue;
		}

		for (int i = 0; i < converted_cnt; ++i) {
			getResult(best[converted_num[i]], converted_num[i]);
		}

		if (best[target] != 99)
			cout << "#" << test << " " << best[target] + 1 << "\n";
		else
			cout << "#" << test << " " << -1 << "\n";
	}

	return 0;
}