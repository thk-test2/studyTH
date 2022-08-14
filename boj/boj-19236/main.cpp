#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Fish {
	int i;
	int j;
	int dir;
	bool valid;
};

int arr[4][4]; // id만 보관한다.
Fish fish[17]; // fish의 정보는 다른 배열에. 물고기 이동을 1번부터 순서대로 하기 위함.
int dirI[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dirJ[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int maxFish = 0;

vector<int> searchFish(int dir, int y, int x) {
	vector<int> available;
	int i = y, j = x;
	while ((i >= 0 && i < 4) && (j >= 0 && j < 4)) {
		if (fish[arr[i][j]].valid)
			available.push_back(arr[i][j]);
		i += dirI[dir];
		j += dirJ[dir];
	}
	return available;
}

int searchWay(int& dir, int y, int x, int sy, int sx) {
	int ny, nx, k = 0;
	for (; k < 8; ++k) {
		ny = y + dirI[dir];
		nx = x + dirJ[dir];
		if ((ny < 0 || ny >= 4 || nx < 0 || nx >= 4) ||
			(ny == sy && nx == sx)) {
			dir++;
			if (dir == 9) dir = 1;
			continue;
		}
		else {
			break;
		}
	}
	return k == 8 ? -1 : arr[ny][nx];
}

void travel(int dir, int y, int x, int fishSum) {
	// Save original map
	int arrTemp[4][4];
	Fish fishTemp[17];
	memcpy(arrTemp, arr, sizeof(arr));
	memcpy(fishTemp, fish, sizeof(fish));

	// Move Fish
	for (int k = 1; k <= 16; ++k) {
		if (!fish[k].valid) continue;
		int next = searchWay(fish[k].dir, fish[k].i, fish[k].j, y, x);
		if (next != -1) {
			swap(arr[fish[k].i][fish[k].j], arr[fish[next].i][fish[next].j]);
			swap(fish[k].i, fish[next].i);
			swap(fish[k].j, fish[next].j);
		}
	}

	vector<int> avail = searchFish(dir, y, x);
	if (avail.empty()) {
		maxFish = max(maxFish, fishSum);
	}

	// Eat fish & travel shark
	for (auto& itr : avail) {
		fish[itr].valid = false;
		travel(fish[itr].dir, fish[itr].i, fish[itr].j, fishSum + itr);
		fish[itr].valid = true;
	}
	// Restore map
	memcpy(arr, arrTemp, sizeof(arrTemp));
	memcpy(fish, fishTemp, sizeof(fishTemp));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int f, d;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> f >> d;
			arr[i][j] = f;
			fish[f] = { i, j, d, true };
		}
	}
	fish[arr[0][0]].valid = false;
	travel(fish[arr[0][0]].dir, fish[arr[0][0]].i, fish[arr[0][0]].j, arr[0][0]);
	cout << maxFish;
	return 0;
}