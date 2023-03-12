#include <iostream>
#include <queue>
#include <vector>

using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int N, M, n;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> n;
		pq.push(n);
	}

	for (int i = 0; i < M; ++i) {
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();

		pq.push(x + y);
		pq.push(x + y);
	}
	ll sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << "\n";
	return 0;
}