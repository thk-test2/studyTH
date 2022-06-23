#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr auto INF = 987654321;

vector<pair<int, int>> v[1001];
int N, M;

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

vector<int> dijkstra(int start) {
	vector<int> best(N + 1, INF);
	best[1] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	pq.push({ start, 0 });

	vector<int> path;
	for (int i = 0; i <= N; ++i)
		path.push_back(i);

    while (!pq.empty()) {
		pair<int, int> cur = pq.top();
		pq.pop();

		for (int k = 0; k < v[cur.first].size(); ++k) {
			int next = v[cur.first][k].first;
			int nextDistance = v[cur.first][k].second;
			if (best[next] > cur.second + nextDistance) {
				path[next] = cur.first;

				best[next] = cur.second + nextDistance;
				pq.push({ next, cur.second + nextDistance });
			}
		}
	}
	return path;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	vector<int> path = dijkstra(1);
	
	cout << N - 1 << "\n";
	for (int i = 2; i <= N; ++i) {
		cout << i << " " << path[i] << "\n";
	}
	return 0;
}