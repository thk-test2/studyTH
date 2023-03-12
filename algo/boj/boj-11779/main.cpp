#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

constexpr auto CITY = 1001;
constexpr auto INF = LONG_MAX / 2;

int N, M;
int from, to, val;
long dist[CITY];
int before[CITY];
vector<pair<int, int>> arr[CITY];
vector<int> path;

struct Less {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void input() {
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; ++i) dist[i] = INF;
	for (int i = 0; i < M; ++i) {
		cin >> from >> to >> val;
		arr[from].push_back({ val, to });
	}
	cin >> from >> to;
}

void dijkstra(int from, int to) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, Less> pq;
	pq.push({ from, 0 });
	dist[from] = 0;

	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		//cout << cost << ", " << cur << "\n";
		if (dist[cur] < cost) continue;
		for (int i = 0; i < arr[cur].size(); ++i) {
			int next = arr[cur][i].second;
			int nextCost = arr[cur][i].first;

			if (dist[next] > cost + nextCost) {
				before[next] = cur;
				dist[next] = cost + nextCost;
				pq.push({ next, dist[next] });
			}
		}
	}

	cout << dist[to] << "\n";
	int idx = to;
	while (idx != 0) {
		path.push_back(idx);
		idx = before[idx];
	}
	cout << path.size() << "\n";
	for (auto itr = path.rbegin(); itr != path.rend(); ++itr)
		cout << *itr << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	dijkstra(from, to);
	return 0;
}