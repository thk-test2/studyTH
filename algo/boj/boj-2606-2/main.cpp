#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int val;
	Node* next;
};

Node* head[101];
Node Pool[101 * 10];
int pSize;
bool visited[101];

Node* myAlloc(int val, Node* next) {
	Pool[pSize] = { val, next };
	return &Pool[pSize++];
}

void addNode(int from, int val) {
	head[from] = myAlloc(val, head[from]);
}

int travel() {
	queue<int> q;
	q.push(1);
	visited[1] = true;

	int answer = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		Node* node = head[cur];
		for (; node; node = node->next) {
			if (visited[node->val]) continue;
			visited[node->val] = true;
			q.push(node->val);
			answer++;
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;
	int from, to;
	for (int i = 0; i < M; ++i) {
		cin >> from >> to;
		addNode(from, to);
		addNode(to, from);
	}
	cout << travel();
	return 0;
}