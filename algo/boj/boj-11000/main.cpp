#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, s, t;
	cin >> N;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; ++i) {
		cin >> s >> t;
		v.push_back({ s, t });
	}
	sort(v.begin(), v.end());
	
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);
	int room = 1;
	for (int i = 1; i < N; ++i) {
		if (pq.top() > v[i].first) {
			pq.push(v[i].second);
		}
		else {
			pq.pop(); pq.push(v[i].second);
		}
	}
	cout << pq.size();
	return 0;
}