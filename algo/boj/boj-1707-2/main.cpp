#include <iostream>
#include <cstring>

using namespace std;

constexpr auto SIZE = 200001;

struct Node {
	int val;
	Node* next;
};

Node Pool[SIZE * 3];
int pSize;

Node* bucket[20010];
int visited[20010];
int V, E;

Node* myAlloc(int val, Node* next) {
	Pool[pSize] = { val, next };
	return &Pool[pSize++];
}

void addNode(int from, int val) {
	bucket[from] = myAlloc(val, bucket[from]);
}

void dfs(int cur, int color) {
	Node* node = bucket[cur];
	for (; node; node = node->next) {
		if (visited[node->val] != 0) continue;
		visited[node->val] = color;
		dfs(node->val, 3 - color);
	}
}

void init() {
	pSize = 0;
	memset(visited, 0, sizeof(visited));
	memset(bucket, 0, sizeof(bucket));
}

bool simulation() {
	for (int i = 1; i <= V; ++i) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(i, 3 - 1);
		}
	}
	bool success = true;
	for (int i = 1; i <= V; ++i) {
		Node* node = bucket[i];
		for (; node; node = node->next) {
			if (visited[i] == visited[node->val]) {
				success = false; break;
			}
		}
	}
	return success;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, u, v;
	cin >> K;
	for (int test = 0; test < K; ++test) {
		cin >> V >> E;
		init();
		for (int i = 0; i < E; ++i) {
			cin >> u >> v;
			addNode(u, v);
			addNode(v, u);
		}
		simulation() ? cout << "YES\n"
                     : cout << "NO\n";
	}
	return 0;
}