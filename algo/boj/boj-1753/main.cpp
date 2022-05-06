#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr auto INF = 987654321;

vector<pair<int, int>> adj[20001];
int V, E, start;

struct Less {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

vector<int> dijkstra(int start) {
	vector<int> dp(V + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Less> pq;
	dp[start] = 0;
	pq.push({ start, dp[start] });

	while (!pq.empty()) {
		pair<int, int> current = pq.top();
		pq.pop();

		if (dp[current.first] < current.second) continue;
		for (int i = 0; i < adj[current.first].size(); ++i) {
			int next = adj[current.first][i].first;
			int nextDistance = current.second + adj[current.first][i].second;
			if (dp[next] > nextDistance) {
				dp[next] = nextDistance;
				pq.push({ next, nextDistance });
			}
		}
	}
	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	cin >> start;
	int u, v, w;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	vector<int> result = dijkstra(start);
	for (int i = 1; i <= V; ++i) {
		if (result[i] == INF)
			cout << "INF" << "\n";
		else
			cout << result[i] << "\n";
	}
	return 0;
}