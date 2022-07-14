#include <iostream>
#include <cstring>

using namespace std;
constexpr auto SIZE = 200001;

struct Node {
	int val = 0;
	Node* next = nullptr;
};

Node* adj[20001];
Node Pool[SIZE * 3];
int pSize;
int K, V, E;

int visited[SIZE];

Node* myAlloc(int val, Node* next) {
	Pool[pSize] = { val, next };
	return &Pool[pSize++];
}

void addNode(int start, int end) {
	adj[start] = myAlloc(end, adj[start]);
}

void checknode(int v, int prev_color) {
	Node* node = adj[v];
	for (; node; node = node->next) {
		if (visited[node->val] != 0) continue;
		visited[node->val] = 3 - prev_color;
		checknode(node->val, 3 - prev_color);
	}
}

bool isBinaryGraph() {
	for (int i = 1; i <= V; ++i) {
		if (visited[i] != 0) continue;
		visited[i] = 1;
		checknode(i, 1);
	}

	for (int i = 1; i <= V; ++i) {
		Node* node = adj[i];
		for (; node; node = node->next) {
			if (visited[i] == visited[node->val]) {
				return false;
			}
		}
	}
	return true;
}

void init() {
	memset(visited, 0, sizeof(visited));
	memset(adj, NULL, sizeof(adj));
	pSize = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K;
	for (int test = 1; test <= K; ++test) {
		init();
		cin >> V >> E;
		int v, e;
		for (int i = 0; i < E; ++i) {
			cin >> v >> e;
			addNode(v, e);
			addNode(e, v);
		}
		cout << (isBinaryGraph() ? "YES" : "NO") << "\n";
	}
	return 0;
}