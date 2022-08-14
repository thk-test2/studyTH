#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;
using pos = pair<int, int>;

constexpr auto MAX = 21;

bool visited[MAX][MAX];
int arr[MAX][MAX];
int N, M;

int diri[] = { -1, 1, 0, 0 };
int dirj[] = { 0, 0, -1, 1 };

vector<pos> fishes;
vector<bool> fishes_alive;
pos baby;
int baby_size = 2;
int baby_eatcnt = 0;
int answer = 0;

vector<int> eatableFishes() {
	vector<int> ret;
	for (int i = 0; i < fishes.size(); ++i) {
		if (!fishes_alive[i]) continue;
		int fsize = arr[fishes[i].first][fishes[i].second];
		if (baby_size > fsize)
			ret.push_back(i);
	}
	return ret;
}

int calDistance(int idx) {
	memset(visited, false, sizeof(visited));
	visited[baby.first][baby.second] = true;

	queue<tuple<int, int, int>> q;
	q.push({ baby.first, baby.second, 0 });
	int distance = 987654321;
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front();
		q.pop();

		if (get<0>(cur) == fishes[idx].first && get<1>(cur) == fishes[idx].second) {
			distance = min(distance, get<2>(cur));
			continue;
		}

		for (int k = 0; k < 4; ++k) {
			int ni = get<0>(cur) + diri[k], nj = get<1>(cur) + dirj[k];
			if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
			if (distance < get<2>(cur) + 1) continue;
			if (visited[ni][nj] || arr[ni][nj] > baby_size) continue;
			visited[ni][nj] = true;
			q.push({ ni, nj, get<2>(cur) + 1 });
		}
	}
	return distance;
}

void selectTarget(int idx, int& target_idx, int& target_distance, int distance) {
	if (target_distance > distance) {
		target_distance = distance;
		target_idx = idx;
	}
	else if (target_distance == distance) {
		if (fishes[target_idx].first > fishes[idx].first) {
			target_idx = idx;
		}
		else if (fishes[target_idx].first == fishes[idx].first) {
			if (fishes[target_idx].second > fishes[idx].second) {
				target_idx = idx;
			}
		}
	}
}

void eatFish(int target_idx) {
	arr[baby.first][baby.second] = 0;
	baby.first = fishes[target_idx].first;
	baby.second = fishes[target_idx].second;

	//fishes.erase(fishes.begin() + target_idx);
	fishes_alive[target_idx] = false;
	arr[baby.first][baby.second] = 9;
	
	if (++baby_eatcnt == baby_size) {
		baby_eatcnt = 0;
		baby_size++;
	}
}

void travel(int time) {
	vector<int> eatable = eatableFishes();

	int target_idx = -1;
	int target_distance = 987654321;
	for (auto& idx : eatable) {
		int distance = calDistance(idx);
		//cout << distance << "\n";
		if (distance != target_distance)
			selectTarget(idx, target_idx, target_distance, distance);
	}

	if (target_idx == -1) {
		answer = time; return;
	}
    eatFish(target_idx);
	travel(time + target_distance);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				if (arr[i][j] == 9)
					baby.first = i, baby.second = j;
				else {
					fishes.push_back({ i, j });
					fishes_alive.push_back(true);
				}
			}
		}
	}
	travel(0);
	cout << answer;
	return 0;
}