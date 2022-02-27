#include <iostream>
#include <set>
#include <queue>

using namespace std;

int N, M, L;
int island_num = 0, island_connected = 0;
int Map[10][10] = { 0 };
int dirI[4] = { -1, 1, 0, 0 };
int dirJ[4] = { 0, 0, -1, 1 };
int Parent[6] = { -1 };
int total_length = 0;

set <pair<int, int>> islands[6];
set <pair<int, pair<int, int>>> edges;

void bfs_make_island(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	bool visited[10][10] = { false };
	visited[i][j] = true;

	while (!q.empty()) {
		auto temp = q.front();
		q.pop();
		islands[island_num].insert(make_pair(temp.first, temp.second));

		for (int idx = 0; idx < 4; idx++) {
			int ni = temp.first + dirI[idx], nj = temp.second+dirJ[idx];
			if (ni >= 0 && ni < N && nj >= 0 && nj < M && !visited[ni][nj] && Map[ni][nj] == 1) {
				visited[ni][nj] = true;
				q.push(make_pair(ni, nj));
			}
		}
	}
}

int point_included_island(int i, int j) {
	int num = -1;
	for (int k = 0; k < 6; k++) {
		if (islands[k].find(make_pair(i, j))
			!= islands[k].end()) {
			num = k;
		}
	}
	return num;
}

void find_islands() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Map[i][j] == 1) {
				if (point_included_island(i, j) != -1) continue;
				bfs_make_island(i, j);
				island_num++;
			}
		}
	}
}

void dfs_find_bridge(int start, int idx, int i, int j, int length) {
	if (Map[i][j] == 1) {
		if (length >= 2) {
			int destination = point_included_island(i, j);
			if (start > destination) swap(start, destination);
			edges.insert(make_pair(length, make_pair(start, destination)));
		}
		return;
	}
	int ni = i + dirI[idx], nj = j + dirJ[idx];
	if (ni >= 0 && ni < N && nj >= 0 && nj < M)
		dfs_find_bridge(start, idx, ni, nj, length + 1);
}

void find_bridge_candidates() {
	for (int k = 0; k < island_num; k++) {
		for (auto& itr : islands[k]) {
			for (int idx = 0; idx < 4; idx++) {
				int ni = itr.first + dirI[idx], nj = itr.second + dirJ[idx];
				if (ni >= 0 && ni < N && nj >= 0 && nj < M && Map[ni][nj] == 0) {
					dfs_find_bridge(k, idx, ni, nj, 0);
				}
			}
		}
	}
}

int find_parent(int x) {
	if (Parent[x] == x) return x;
	return Parent[x] = find_parent(Parent[x]);
}

bool same_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	return x == y ? true : false;
}

void Union(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	if (x != y) {
		Parent[y] = x;
	}
}

void kruskal_for_bridges() {
	for (int k = 0; k < island_num; k++) {
		Parent[k] = k;
	}

	for (auto& edge: edges) {
		int weight = edge.first;
		int x = edge.second.first, y = edge.second.second;
		if (same_parent(x, y)) continue;
		Union(x, y);
		total_length += weight;
		island_connected++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> t;
			Map[i][j] = t;
		}
	}
	find_islands();
	find_bridge_candidates();
	kruskal_for_bridges();

	cout << (island_connected != island_num-1 ? -1 : total_length);
	return 0;
}