#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M, D;
int map[15][15];
int total = 0;
int killed = 0;
int turn = 0;

int temp_map[15][15];
int temp_total = 0;
int temp_killed = 0;
int temp_turn = 0;

int max_killed = 0;

vector<bool> selected;
vector<int> position;
vector<int> archers;
pair<int, int> answer;

void move_enemy() {
	for (int j = 0; j < M; j++) {
		if (map[N-1][j] == 1) total--;
	}

	for (int i = N-1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			i >= turn ? map[i][j] = map[i - 1][j]
				     : map[i][j] = 0;
		}
	}
}

int dist(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

bool bfs_find_enemy(int a) {
	bool visited[15][15] = { false };
	visited[N - 1][a] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(N - 1, a));

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		int i = temp.first, j = temp.second;
		if (dist(i, j, N, a) <= D && map[i][j] == 1) {
			answer = temp; 
			return true;
		}
		
		if (j > 0 && dist(i, j - 1, N, a) <= D && !visited[i][j - 1]) {
			visited[i][j - 1] = true;
			q.push(make_pair(i, j - 1));
		}
		if (i > 0 && dist(i-1, j, N, a) <= D && !visited[i-1][j]) {
			visited[i - 1][j] = true;
			q.push(make_pair(i - 1, j));
		}
		if (j < M-1 && dist(i, j+1, N, a) <= D && !visited[i][j+1]) {
			visited[i][j+1] = true;
			q.push(make_pair(i, j+1));
		}
	}
	return false;
}

void save_map() {
	memcpy(temp_map, map, sizeof(map));
	temp_total = total;
	temp_killed = killed;
	temp_turn = turn;
}

void restore_map() {
	memcpy(map, temp_map, sizeof(temp_map));
	total = temp_total;
	killed = temp_killed;
	turn = temp_turn;
}

void attack_enemy() {
	vector<pair<int, int>> target_pos;
	for (int k = 0; k < 3; k++) {
		if (bfs_find_enemy(archers[k]))
			target_pos.push_back(answer);
	}
	bool attacked[15][15] = { false };
	for (auto& itr : target_pos) {
		int i = itr.first, j = itr.second;
		if (!attacked[i][j]) {
			total--; killed++;
			attacked[i][j] = true;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (attacked[i][j]) map[i][j] = 0;
		}
	}
}

void combi(int index, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < M; i++) {
			if (selected[i]) {
				archers.push_back(i);
			}
		}
		save_map();
		while (total > 0) {
			turn++;
			attack_enemy();
			move_enemy();
		}
		max_killed = max(max_killed, killed);
		restore_map();
		archers.clear();
		return;
	}
	for (int i = index; i < M; i++) {
		if (selected[i]) continue;
		selected[i] = true;

		combi(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &D);

	int t;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &t);
			map[i][j] = t;
			if (t == 1) total++;
		}
	}
	for (int i = 0; i < M; i++) {
		position.push_back(i);
		selected.push_back(false);
	}
	combi(0, 0);
	printf("%d", max_killed);

	return 0;
}