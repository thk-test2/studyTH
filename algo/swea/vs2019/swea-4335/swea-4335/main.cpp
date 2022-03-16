#include <iostream>
#include <cstring>

using namespace std;

int X[20], Y[20], Z[20];
int memo[20][1000000];
bool used[20];
int N;

void init() {
	memset(used, false, sizeof(used));
	memset(memo, -1, sizeof(memo));
}

// state = 0 -> 가로 세로가 바닥, // state = 1 -> 세로 높이가 바닥 // state = 2 -> 가로 높이가 바닥
bool canPut(int lastX, int lastY, int box, int state) {
	if (state == 0) {
		if (X[box] <= lastX && Y[box] <= lastY) return true;
		if (Y[box] <= lastX && X[box] <= lastY) return true;
	}
	else if (state == 1) {
		if (Y[box] <= lastX && Z[box] <= lastY) return true;
		if (Z[box] <= lastX && Y[box] <= lastY) return true;
	}
	else if (state == 2) {
		if (X[box] <= lastX && Z[box] <= lastY) return true;
		if (Z[box] <= lastX && X[box] <= lastY) return true;
	}
	return false;
}

int putBox(int boxIndex, int usedBit, int lastX, int lastY, int currentHeight) {
	if (memo[boxIndex][usedBit] != -1) return memo[boxIndex][usedBit];

	for (int i = 0; i < N; ++i) {
		if ((usedBit >> i) & 0x1) continue;
		int temp = 0;
		if (canPut(lastX, lastY, i, 0)) {
			usedBit |= (0x1 << i);
			temp = putBox(1, 0, X[i], Y[i], currentHeight + Z[i]);
			usedBit &= ~(0x1 << i);
			memo[boxIndex][usedBit] = max(memo[boxIndex][usedBit], temp);
		}

		if (canPut(lastX, lastY, i, 1)) {
			usedBit |= (0x1 << i);
			temp = putBox(1, 1, Y[i], Z[i], currentHeight + X[i]);
			usedBit &= ~(0x1 << i);
			memo[boxIndex][usedBit] = max(memo[boxIndex][usedBit], temp);
		}

		if (canPut(lastX, lastY, i, 2)) {
			usedBit |= (0x1 << i);
			temp = putBox(1, 2, X[i], Z[i], currentHeight + Y[i]);
			usedBit &= ~(0x1 << i);
			memo[boxIndex][usedBit] = max(memo[boxIndex][usedBit], temp);
		}
	}
	return memo[boxIndex][usedBit];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> X[i] >> Y[i] >> Z[i];
		}
		init();
		int ret = putBox(0, 0, 10000, 10000, 0);
		cout << test << " " << ret << "\n";
	}
	return 0;
}