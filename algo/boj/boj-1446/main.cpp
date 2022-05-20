#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[10001];
int dist[10001] = { 0 };
int N, D;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> D;
	for (int i = 0; i <= D; ++i)
		dist[i] = i;

	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > D) continue;
		if (b - a <= c) continue;
		adj[a].push_back({ b, c });
	}
	int prev = -1;
	for (int i = 0; i <= D; ++i) {
		if (i != 0)
			prev = dist[i - 1];
		dist[i] = min(dist[i], prev + 1);

		for (auto next : adj[i]) {
			if (dist[next.first] > dist[i] + next.second)
				dist[next.first] = dist[i] + next.second;
		}
	}
	cout << dist[D];
	return 0;
}