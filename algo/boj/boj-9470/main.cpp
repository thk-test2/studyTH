#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Strahler {
	int val;
	int temp[50];
};

vector<int> adj[1001];
Strahler Str[1001];
bool visited[1001];
int K, M, P;

void init() {
	memset(Str, 0, sizeof(Str));
	for (int i = 1; i <= M; ++i) {
		Str[i].val = 1;
		adj[i].clear();
		visited[i] = false;
	}
}

void travel() {
	for (int i = 1; i <= M; ++i) {
		if (visited[i]) continue;
		visited[i] = true;

		queue<pair<int, int>> q;
		q.push({ i, Str[i].val });
		while (!q.empty()) {
			int cn = q.front().first;
			int cv = q.front().second;
			q.pop();

			for (int j = 0; j < adj[cn].size(); ++j) {
				int neighbor = adj[cn][j];
				if (Str[neighbor].temp[cv] == 0) {
					if (Str[neighbor].val < cv) {
						Str[neighbor].val = cv;
						visited[neighbor] = true;
						q.push({ neighbor, Str[neighbor].val });
					}
					Str[neighbor].temp[cv]++;
				}
				else {
					if (Str[neighbor].val < cv + 1) {
						Str[neighbor].val = cv + 1;
						visited[neighbor] = true;
						q.push({ neighbor, Str[neighbor].val });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> K >> M >> P;
		init();
		int v, w;
		for (int i = 1; i <= P; ++i) {
			cin >> v >> w;
			adj[v].push_back(w);
		}
		travel();
		cout << test << " " << Str[M].val << "\n";
	}

	return 0;
}