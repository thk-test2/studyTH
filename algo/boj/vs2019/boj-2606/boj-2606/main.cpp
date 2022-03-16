#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int val;
	Node* next;
};

Node Pool[1000];
int pCnt = 0;

Node* bucket[101];

Node* myAlloc(int val, Node* next) {
	Pool[pCnt] = { val, next };
	return &Pool[pCnt++];
}

void addNode(int from, int val) {
	bucket[from] = myAlloc(val, bucket[from]);
}

int bfs() {
	queue<int> q;
	q.push(1);

	bool visited[101] = { false };
	visited[1] = true;
	int cnt = -1;

	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cnt++;

		for (Node* nd = bucket[temp]; nd != nullptr; nd = nd->next) {
			if (!visited[nd->val]) {
				visited[nd->val] = true;
				q.push(nd->val);
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, T, f, t;
	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		cin >> f >> t;
		addNode(f, t);
		addNode(t, f);
	}
	cout << bfs();

	return 0;
}