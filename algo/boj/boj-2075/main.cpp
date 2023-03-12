#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	int t;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> t;
			if (pq.size() >= N) {
				if (t > pq.top()) {
					pq.pop(); pq.push(t);
				}
			}
			else
				pq.push(t);
		}
	}
	cout << pq.top();
	return 0;
}