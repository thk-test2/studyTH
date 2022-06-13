#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr auto SIZE = 101;
constexpr auto INF = 987654321;

vector<pair<int, int>> adj[SIZE];
int item[SIZE];
int N, M, R;

struct Compare {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int travel() {
	int answer = 0;
	for (int i = 0; i < N; ++i) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
		vector<int> dp(N, INF);
		dp[i] = 0;

		pq.push({ i, 0 });
		while (!pq.empty()) {
			pair<int, int> cur = pq.top();
			pq.pop();

			for (int k = 0; k < adj[cur.first].size(); ++k) {
				int next = adj[cur.first][k].first;
				int nextD = cur.second + adj[cur.first][k].second;
				if (dp[next] > nextD) {
					dp[next] = nextD;
					pq.push({ next, nextD });
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			if (dp[i] <= M) sum += item[i];
		}
		answer = max(answer, sum);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;
	for (int i = 0; i < N; ++i) {
		cin >> item[i];
	}
	int a, b, l;
	for (int i = 0; i < R; ++i) {
		cin >> a >> b >> l;
		adj[a-1].push_back({ b-1, l });
		adj[b-1].push_back({ a-1, l });
	}
	int ret = travel();
	cout << ret;
	return 0;
}