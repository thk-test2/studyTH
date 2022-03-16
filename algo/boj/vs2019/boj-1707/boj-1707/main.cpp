#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 600000;

struct Node {
	int val = 0;
	Node* next = nullptr;
};

Node Pool[MAX_SIZE];
int cnt = 0;

Node* Head[20010];
int visited[20010];

Node* myAlloc(int val, Node* next) {
	Pool[cnt] = { val, next };
	return &Pool[cnt++];
}

// 앞에 넣기
void addNode(int from, int val) {
	Head[from] = myAlloc(val, Head[from]);
}

bool dfs(int node, int color = 1) {
	visited[node] = color;

	for (Node* p = Head[node]; p; p = p->next) {
		if (visited[p->val] == color) return false;
		if (!visited[p->val]) {
			/* 3-1 = 2 , 3-2 = 1*/
			if (!dfs(p->val, 3 - color)) return false;
		}
	}

	//cout << "\n";
	return true;
}

 int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, V, E;
	cin >> K;
	for (int test = 1; test <= K; ++test) {
		cin >> V >> E;
		int from, val;
		for (register int i = 1; i <= E; ++i) {
			cin >> from >> val;
			addNode(from, val);
			addNode(val, from);
		}

		bool result = false;
		for (register int i = 1; i <= V; ++i) {
			if (!visited[i]) {
				result = dfs(i);
				if (!result) break;
			}
		}
		result ? cout << "YES\n"
			: cout << "NO\n";

		for (register int i = 1; i <= V; ++i) {
			Head[i] = nullptr; visited[i] = 0;
			cnt = 0;;
		}
	}
	return 0;
}