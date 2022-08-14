#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

constexpr auto MAX = 201;

int K, idx;
unordered_map<string, int> um;
vector<int> v[MAX];
int visit[MAX];

void init() {
	idx = 0;
	um.clear();
	for (int i = 0; i < MAX; ++i) {
		v[i].clear();
		visit[i] = 0;
	}
}

void dfs(int current, int color) {
	visit[current] = color;

	for (int i = 0; i < v[current].size(); ++i) {
		int next = v[current][i];
		if (visit[next] == 0) {
			dfs(next, 3 - color);
		}
	}
}

string simulation() {
	for (int i = 0; i < idx; ++i) {
		if (visit[i] == 0) {
			dfs(i, 1);
		}
	}
	for (int i = 0; i < idx; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (visit[i] == visit[v[i][j]]) {
				return "No";
			}
		}
	}
	return "Yes";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		init();
		cin >> K;
		string a, b;
		for (int i = 0; i < K; ++i) {
			cin >> a >> b;
			if (um.count(a) == 0) um[a] = idx++;
			if (um.count(b) == 0) um[b] = idx++;
			v[um[a]].push_back(um[b]);
			v[um[b]].push_back(um[a]);
		}
		cout << "#" << test << " " << simulation() << "\n";
	}
}