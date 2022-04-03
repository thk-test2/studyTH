#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
constexpr auto MAX = 18; // roundup log(2, 100000)

int N, M;
int parent[100000][MAX]; // parent[i][k]: i�� 2^k ��° �θ�
int depth[100000]; // ������ ���� (��Ʈ�� ����: 0)
vector<int> adj[100000]; // ���� ����Ʈ

// dfs�� Ʈ�� �����ϸ� parent[i][0], depth �迭 ä��
void makeTreeByDFS(int curr) {
	for (auto& next : adj[curr]) {
		if (depth[next] == -1) {
			parent[next][0] = curr;
			depth[next] = depth[curr] + 1;
			makeTreeByDFS(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int u, v;
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// �迭 �ʱ�ȭ
	memset(parent, -1, sizeof(parent));
	fill(depth, depth + N, -1);
	depth[0] = 0;

	// Ʈ�� �����
	makeTreeByDFS(0);

	// parent �迭 ä��
	for (int j = 0; j < MAX - 1; ++j) {
		for (int i = 1; i < N; ++i) {
			if (parent[i][j] != -1)
				parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}

	// ���� �Է¹ޱ�
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		u--; v--;
		// depth[u] >= depth[v]�� �ǵ��� u, v�� ����
		if (depth[u] < depth[v]) swap(u, v);
		int diff = depth[u] - depth[v];

		// ���� ��(diff) �� ���ָ� u�� �̵���Ŵ
		for (int j = 0; diff; ++j) {
			if (diff % 2) u = parent[u][j];
			diff /= 2;
		}

		// u�� v�� �ٸ��� ���ÿ� ���� ���̸�ŭ ���� �̵���Ŵ
		if (u != v) {
			// ���� 2^17, 2^16, ... 2^2, 2^1, 2^0 ������ �õ�
			for (int j = MAX - 1; j >= 0; --j) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			// ������ �ٷ� �Ʒ� �ڽı��� �̵�������, �θ�� �ѹ� �� �÷���
			u = parent[u][0];
		}
		cout << u + 1 << "\n";
	}
	return 0;
}