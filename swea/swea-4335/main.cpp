#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Box {
	int x;
	int y;
	int z;
};

int memo[21][21][4];
Box input[21];
int N;

bool Compare(Box a, Box b) {
	if (a.x == b.x)
		if (a.y == b.y)
			return a.z > b.z;
		return a.y > b.y;
	return a.x > b.x;
}

void init() {
	memset(memo, 0, sizeof(memo));
	memset(input, 0, sizeof(input));
	input[0].x = 10001, input[0].y = 10001, input[0].z = 0;
}

// 0: 불가, 1: 가로 세로가 밑변, 2: 가로 높이가 밑변, 3: 세로 높이가 밑변
vector<int> canplace(int level, int lastLevel, int lastState) {
	vector<int> ret;
	if (lastState == 1) {
		if ((input[lastLevel].x >= input[level].x && input[lastLevel].y >= input[level].y)
			|| (input[lastLevel].y >= input[level].x && input[lastLevel].x >= input[level].y))
			ret.push_back(1);
		if ((input[lastLevel].x >= input[level].x && input[lastLevel].y >= input[level].z)
			|| (input[lastLevel].y >= input[level].x && input[lastLevel].x >= input[level].z))
			ret.push_back(2);
		if ((input[lastLevel].x >= input[level].y && input[lastLevel].y >= input[level].z)
			|| (input[lastLevel].y >= input[level].y && input[lastLevel].x >= input[level].z))
			ret.push_back(3);
	}
	else if (lastState == 2) {
		if ((input[lastLevel].x >= input[level].x && input[lastLevel].z >= input[level].y)
			|| (input[lastLevel].z >= input[level].x && input[lastLevel].x >= input[level].y))
			ret.push_back(1);
		if ((input[lastLevel].x >= input[level].x && input[lastLevel].z >= input[level].z)
			|| (input[lastLevel].z >= input[level].x && input[lastLevel].x >= input[level].z))
			ret.push_back(2);
		if ((input[lastLevel].x >= input[level].y && input[lastLevel].z >= input[level].z)
			|| (input[lastLevel].z >= input[level].y && input[lastLevel].x >= input[level].z))
			ret.push_back(3);
	}
	else if (lastState == 3) {
		if ((input[lastLevel].y >= input[level].x && input[lastLevel].z >= input[level].y)
			|| (input[lastLevel].z >= input[level].x && input[lastLevel].y >= input[level].y))
			ret.push_back(1);
		if ((input[lastLevel].y >= input[level].x && input[lastLevel].z >= input[level].z)
			|| (input[lastLevel].z >= input[level].x && input[lastLevel].y >= input[level].z))
			ret.push_back(2);
		if ((input[lastLevel].y >= input[level].y && input[lastLevel].z >= input[level].z)
			|| (input[lastLevel].z >= input[level].y && input[lastLevel].y >= input[level].z))
			ret.push_back(3);
	}
	return ret;
}

int checknode(int currentH, int level, int lastLevel, int lastState) {
	if (memo[level][lastLevel][lastState] != 0) return memo[level][lastLevel][lastState];
	if (level > N) return currentH;

	vector<int> ret = canplace(level, lastLevel, lastState);
	if (!ret.empty()) {
		for (auto& key : ret) {
			if (key == 1)
				memo[level][lastLevel][lastState] = max(memo[level][lastLevel][lastState],
					checknode(currentH + input[level].z, level + 1, level, key));
			else if (key == 2)
				memo[level][lastLevel][lastState] = max(memo[level][lastLevel][lastState],
					checknode(currentH + input[level].y, level + 1, level, key));
			else if (key == 3)
				memo[level][lastLevel][lastState] = max(memo[level][lastLevel][lastState],
					checknode(currentH + input[level].x, level + 1, level, key));
		}
	}
	memo[level][lastLevel][lastState] = max(memo[level][lastLevel][lastState],
			checknode(currentH, level + 1, lastLevel, lastState));
	return memo[level][lastLevel][lastState];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		init();
		for (int i = 1; i <= N; ++i) {
			cin >> input[i].x >> input[i].y >> input[i].z;
		}
		sort(input, input + N, Compare);
		int ret = checknode(0, 1, 0, 1);
		cout << "#" << test << " " << ret << "\n";
	}
	return 0;
}