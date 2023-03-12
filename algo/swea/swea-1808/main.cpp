#include <iostream>
#include <cstring>

using namespace std;

int arr[10];
int made[1000001];
int N;

void init() {
	memset(made, 0, sizeof(made));
}

void makeNums(int current, int cnt) {
	if (cnt > 7) return;
	if (current > N) return;

	if (cnt > 0) {
		made[current] = cnt;
	}

	for (int i = 0; i < 10; ++i) {
		if (arr[i]) {
			makeNums(current * 10 + i, cnt + 1);
		}
	}
}

int calculate() {
	int answer = 0;
	int num = N;
	int pushCnt = 0;
	if (made[N]) return made[N] + 1;

	for (register int i = N / 2; i > 1; --i) {
		while (made[i] > 0) {
			if (num % i == 0) {
				pushCnt += (made[i] + 1);
				num /= i;
			}
			else {
				break;
			}
		}
		if (num == 1) {
			answer = pushCnt;
			break;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		init();
		for (int i = 0; i < 10; ++i) {
			cin >> arr[i];
		}
		cin >> N;
		makeNums(0, 0);

		int cnt = calculate();
		if (cnt)
			cout << "#" << test << " " << cnt << "\n";
		else
			cout << "#" << test << " " << -1 << "\n";
	}

	return 0;
}