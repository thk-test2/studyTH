#include <iostream>
#include <vector>
#include <queue>

using namespace std;
constexpr auto SIZE = 51;

vector<int> adj[SIZE];
int N;
int answer = 0;

int checknode(int currentPos) {
	priority_queue<int> pq;

	for (int i = 0; i < adj[currentPos].size(); ++i) {
		int next = adj[currentPos][i];
		pq.push(checknode(next));
	}
	int ret = 0;
	int W = 0;
	while (!pq.empty()) {
		int childCost = pq.top();
		pq.pop();
		ret = max(ret, childCost + W++);
	}
	return ret + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int t;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		if (i == 0) continue;
		adj[t].push_back(i);
	}
	cout << checknode(0) - 1;
	return 0;
}