#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
constexpr auto INF = 987654321;

bool visited[51][51];
bool selected[21];
int arr[51][51];
int temp[51][51];
int N, M, virus_cnt, zero_cnt;

int min_time = INF;

int di[] = { -1, 1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };

struct Node {
	pair<int, int> pos;
	int time;
};

bool isVirus(pair<int, int> pos, vector<pair<int, int>>& candidates) {
	for (auto& itr : candidates)
		if (itr == pos) return true;
	return false;
}

void bfs(pair<int, int> pos, vector<pair<int, int>>& candidates) {
	queue<Node> q;
	q.push({ pos, 0 });
	memset(visited, false, sizeof(visited));

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int ni = cur.pos.first + di[k], nj = cur.pos.second + dj[k];
			if (ni < 0 || ni >= N || nj < 0 || nj >= N 
				|| (ni == pos.first && nj == pos.second)) continue;
			if (visited[ni][nj]) continue;
			if (arr[ni][nj] == 0 || arr[ni][nj] > cur.time + 1 || isVirus({ni, nj}, candidates)) {
				visited[ni][nj] = true;
				arr[ni][nj] = cur.time + 1;
				q.push({ {ni, nj}, arr[ni][nj] });
			}
		}
	}
}

int getMaxTime(vector<pair<int, int>>& candidates) {
	int max_time = 0;
	for (auto& pos : candidates)
		arr[pos.first][pos.second] = -1;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (arr[i][j] == 0) return INF;
			max_time = max(max_time, arr[i][j]);
		}
	}
	return max_time;
}

void selectVirus(int idx, int cnt, vector<pair<int, int>>& candidates) {
	if (cnt == M) {
		memcpy(temp, arr, sizeof(arr));

		for (int k = 0; k < virus_cnt; ++k) {
			if (!selected[k]) continue;
			//cout << candidates[k].first << ", " << candidates[k].second << "\n";
			bfs(candidates[k], candidates);
		}
		int temp_max = getMaxTime(candidates);
		if (temp_max != INF)
			min_time = min(min_time, temp_max);
		memcpy(arr, temp, sizeof(arr));

		//cout << "\n";
		return;
	}

	for (int i = idx; i < virus_cnt; ++i) {
		if (selected[i]) continue;
		selected[i] = true;
		selectVirus(i, cnt + 1, candidates);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	vector<pair<int, int>> candidates;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				zero_cnt++;
			}
			else if (arr[i][j] == 2) {
				candidates.push_back({ i, j });
			}
		}
	}
	if (!zero_cnt) {
		cout << 0 << "\n";
		return 0;
	}

	virus_cnt = candidates.size();
	selectVirus(0, 0, candidates);
	cout << (min_time != INF ? min_time : -1) << "\n";
	return 0;
}