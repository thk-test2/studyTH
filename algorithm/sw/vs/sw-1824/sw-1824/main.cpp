#include <cstdio>
#include <queue>

using namespace std;

struct Node {
	int i, j, memory, direction;
};

int R, C;
char cmds[20][20];
int dI[4] = { 0, 0, -1, 1 };
int dJ[4] = { -1, 1, 0, 0 };

bool bfs() {
	bool visited[20][20][16][4] = { false };
	queue<Node> q;
	q.push({ 0, 0, 0, 1});
	visited[0][0][0][1] = true;

	while (!q.empty()) {
		Node t = q.front();
		q.pop();
		visited[t.i][t.j][t.memory][t.direction] = true;

		char cmd = cmds[t.i][t.j];
		int next_memory = t.memory;
		int next_dir = t.direction;

		if (cmd == '<') next_dir = 0;
		else if (cmd == '>') next_dir = 1;
		else if (cmd == '^') next_dir = 2;
		else if (cmd == 'v') next_dir = 3;
		else if (cmd == '_') next_dir = (next_memory == 0 ? 1 : 0);
		else if (cmd == '|') next_dir = (next_memory == 0 ? 3 : 2);
		else if (cmd >= '0' && cmd <= '9') next_memory = cmd - '0';
		else if (cmd == '+') next_memory == 15 ? next_memory = 0 : next_memory++;
		else if (cmd == '-') next_memory == 0 ? next_memory = 15 : next_memory--;
		else if (cmd == '@') return true;
		else if (cmd == '?') {
			for (int k = 0; k < 4; k++) {
				int nI = t.i + dI[k], nJ = t.j + dJ[k];
				if (nI == R) nI = 0;
				else if (nI == -1) nI = R - 1;
				if (nJ == C) nJ = 0;
				else if (nJ == -1) nJ = C - 1;
				if (!visited[nI][nJ][next_memory][k]) {
					visited[nI][nJ][next_memory][k] = true;
					q.push({ nI, nJ, next_memory, k });
				}
			}
		}
		int nI = t.i + dI[next_dir], nJ = t.j + dJ[next_dir];
		if (nI == R) nI = 0;
		else if (nI == -1) nI = R - 1;
		if (nJ == C) nJ = 0;
		else if (nJ == -1) nJ = C - 1;

		if (!visited[nI][nJ][next_memory][next_dir]) {
			visited[nI][nJ][next_memory][next_dir] = true;
			q.push({ nI, nJ, next_memory, next_dir });
		}
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		scanf("%d %d", &R, &C);
		char cmd[21] = { false };
		for (int i = 0; i < R; i++) {
			scanf("%s", cmd);
			for (int j = 0; j < C; j++) {
				cmds[i][j] = cmd[j];
			}
		}
		bfs() ? printf("#%d YES\n", test)
			: printf("#%d NO\n", test);
	}
	return 0;
}