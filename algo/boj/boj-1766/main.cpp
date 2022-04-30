#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int entry[32001] = { 0, };
vector<int> seq[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		entry[b]++;
		seq[a].push_back(b);
	}
	for (int i = 1; i <= N; ++i) {
		if (entry[i] == 0)
			pq.push(i);
	}

	while (!pq.empty()) {
		int problem = pq.top();
		pq.pop();

		cout << problem << " ";

		for (int i = 0; i < seq[problem].size(); ++i) {
			int next = seq[problem][i];
			entry[next]--;
			if (entry[next] == 0) {
				pq.push(next);
			}
		}
	}
	return 0;
}