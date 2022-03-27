#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int node_num;
int parent[100001][18];
int depth[100001];
int max_height;
vector<int> adj[100001];

void findBirthParent(int par, int now, int dep) {
	if (adj[now].size() == 0) return;

	parent[now][0] = par;
	depth[now] = dep;

	for (int i = 0; i < adj[now].size(); ++i) {
		if (adj[now][i] == par) continue;
		findBirthParent(now, adj[now][i], dep + 1);
	}
}

void findGrandParents() {
	int temp = node_num, cnt = 0;
	for (; temp > 1; temp >>= 1) {
		++cnt;
	}
	max_height = cnt;
	for (int k = 1; k <= max_height; ++k) {
		for (int idx = 2; idx <= node_num; ++idx) {
			if (parent[idx][k - 1] == 0) continue;
			parent[idx][k] = parent[parent[idx][k - 1]][k - 1];
		}
	}
}

int findLCA(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b])
			swap(a, b);

		int dif = depth[a] - depth[b];
		for (int i = 0; dif > 0; ++i) {
			if (dif % 2 == 1) a = parent[a][i];
			dif >>= 1;
		}
	}

	if (a != b) {
		for (int k = max_height; k >= 0; --k) {
			if (parent[a][k] != 0 && parent[a][k] != parent[b][k]) {
				a = parent[a][k];
				b = parent[b][k];
			}
		}
		a = parent[a][0];
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> node_num;
	int a, b;
	for (int i = 0; i < node_num - 1; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	findBirthParent(0, 1, 0);
	findGrandParents();

	int pair_num;
	cin >> pair_num;
	for (int i = 0; i < pair_num; ++i) {
		cin >> a >> b;
		cout << findLCA(a, b) << "\n";
	}
	return 0;
}