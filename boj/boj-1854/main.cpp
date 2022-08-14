#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[1001];
int N, M, K;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> heap[1001];

void dijk_2() {
	pq.push({ 0, 1 });
	heap[1].push(0);

	while (!pq.empty()) {
		int cur_point = pq.top().second;
		int cur_distance = pq.top().first;
		pq.pop();

		for (auto& itr : adj[cur_point]) {
			int next_point = itr.first;
			int next_cost = cur_distance + itr.second;

			// 가장 최소값만 관리하는 것이 아니라 k번째 최단 경로까지 관리한다.
			// 해당 노드까지의 경로의 개수가 k개가 안 되면 그냥 삽입
			if (heap[next_point].size() < K) {
				heap[next_point].push(next_cost);
				pq.push({ next_cost, next_point });
			}
			else {
				// k개 이상이면 heap[next].top()과 비교해서 작으면 삽입, 크면 무시한다.
				if (heap[next_point].top() > next_cost) {
					heap[next_point].pop();
					heap[next_point].push(next_cost);
					pq.push({ next_cost, next_point });
				}
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (heap[i].size() >= K)
			cout << heap[i].top() << "\n";
		else
			cout << "-1\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M >> K;
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}
	dijk_2();
	return 0;
}