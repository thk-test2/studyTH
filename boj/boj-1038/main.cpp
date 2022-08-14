#include <iostream>
#include <cstring>

using namespace std;

bool selected[10];
int N, cnt;
long long answer = -1;

void checknode(long long now, int level, int target) {
	if (now > 9876543210) return;
	if (answer != -1) return;
	if (level == target) {
		if (++cnt == N) answer = now;
		//cout << now << "\n";
		return;
	}
	for (int i = 0; i < 10; ++i) {
		if (target > 0 && level == 0 && i == 0) continue;
		if (now != 0 && now % 10 <= i) continue;
		long long nextNum = now * 10 + i;

		if (selected[i]) continue;
		selected[i] = true;
		checknode(nextNum, level + 1, target);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	if (N == 0) {
		cout << N << "\n"; return 0;
	}
	for (int i = 1; i < 11; ++i) {
		checknode(0, 0, i);
		memset(selected, false, sizeof(selected));
	}
	cout << answer << "\n";
	answer = -1, cnt = 0;
	return 0;
}