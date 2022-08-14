#include <iostream>

using namespace std;
constexpr auto INF = 999;

int numbers[10];
int op[4];
int best[1000];
int N, O, M, W;

int same_result[1000];
int converted_num[1000];
int converted_cnt;

void init() {
	converted_cnt = 0;
	for (int i = 0; i < 1000; ++i) {
		best[i] = INF;
	}
}

void sortNumbers() {
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (numbers[j] < numbers[i])
				swap(numbers[j], numbers[i]);
		}
	}
}

void makeNum(int level, int target_level, string str) {
	if (level == target_level) {
		int num = str[0] - '0';
		for (int i = 1; i < str.size(); ++i) {
			num *= 10;
			num += (str[i] - '0');
		}
		if (best[num] == INF) {
			best[num] = level;
			converted_num[converted_cnt++] = num;
		}
		return;
	}
	for (int i = 0; i < N; ++i) {
		str += (numbers[i] + '0');
		makeNum(level + 1, target_level, str);
		str.pop_back();
	}
}

void checknode(int cnt, int currentVal) {
	for (int j = 0; j < O; ++j) {
		for (int i = 0; i < converted_cnt; ++i) {
			int num = converted_num[i];
			int nextCnt = cnt + best[num] + 1;
			if (nextCnt > M - 1) break;

			int nextVal = currentVal;
			if (op[j] == 1) {
				nextVal += num;
			}
			else if (op[j] == 2) {
				nextVal -= num;
			}
			else if (op[j] == 3) {
				nextVal *= num;
			}
			else {
				if (num == 0) continue;
				nextVal /= num;
			}
			if (op[j] == 1 && nextVal > 999) break;
			if (op[j] == 2 && nextVal < 0) break;
			if (op[j] == 3 && nextVal > 999) break;
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
			cin >> numbers[i];
		}
		sortNumbers();
		for (int k = 1; k <= 3; ++k) {
			makeNum(0, k, "");
		}

		for (int i = 0; i < O; ++i) {
			cin >> op[i];
		}
		cin >> W;
		if (best[W] != INF) {
			cout << "#" << test << " " << best[W] << "\n";
			continue;
		}
		
		for (int i = 0; i < converted_cnt; ++i)
			checknode(best[converted_num[i]], converted_num[i]);
		
		cout << "#" << test << " ";
		if (best[W] != INF)
			cout << best[W] + 1 << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}