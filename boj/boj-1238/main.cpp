#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr auto INF = 987654321;
constexpr auto SIZE = 1001;

vector<pair<int, int>> adj[SIZE];
int N, M, X;

int dijkstra(int start, int end)
{
    vector<int> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int from = pq.top().second;
        pq.pop();

        if (dist[from] < cost) continue;
        for (int i = 0; i < adj[from].size(); ++i) {
            int to = adj[from][i].first;
            int nextDist = cost + adj[from][i].second;
            if (dist[to] > nextDist) {
                dist[to] = nextDist;
                pq.push({ -nextDist, to });
            }
        }
    }
    return dist[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> X;

    int from, to, cost;
    for (int i = 1; i <= M; ++i) {
        cin >> from >> to >> cost;
        adj[from].push_back({ to, cost });
    }

    int maximum = 0;
    for (int i = 1; i <= N; ++i) {
        int phase1 = dijkstra(i, X);
        int phase2 = dijkstra(X, i);
        if (phase1 + phase2 > maximum) {
            maximum = phase1 + phase2;
        }
    }
    cout << maximum;
	return 0;
}