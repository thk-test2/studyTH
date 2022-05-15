#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const auto INF = 987654321;

vector<pair<int, int>> adj[10001];
int best[10001];

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int>b) {
		return a.second > b.second;
	}
};

void init(int N) {
	for (int i = 1; i <= N; ++i) {
		best[i] = INF;
		adj[i].clear();
	}
}

void dijkstra(int start) {
	best[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push({ start, best[start] });

	while (!pq.empty()) {
		int currentNode = pq.top().first;
		int currentDistance = pq.top().second;
		pq.pop();

		if (best[currentNode] < currentDistance) continue;
		for (int k = 0; k < adj[currentNode].size(); ++k) {
			int nextNode = adj[currentNode][k].first;
			int nextDistance = currentDistance + adj[currentNode][k].second;
			if (best[nextNode] > nextDistance) {
				best[nextNode] = nextDistance;
				pq.push({ nextNode, best[nextNode] });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, D, C;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N >> D >> C;
		init(N);

		int a, b, s;
		for (int i = 0; i < D; ++i) {
			cin >> a >> b >> s;
			adj[b].push_back({ a, s });
		}
		dijkstra(C);
		int cnt = 0, period = 0;
		for (int i = 1; i <= N; ++i) {
			if (best[i] != INF) {
				cnt++;
				period = max(period, best[i]);
			}
		}
		cout << cnt << " " << period << "\n";
	}
	return 0;
}