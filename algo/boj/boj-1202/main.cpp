#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

using jewel = pair<int, int>;
using ull = unsigned long long;

struct Less {
	bool operator() (jewel a, jewel b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first > b.first;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, m, v;
	cin >> N >> K;

	priority_queue<jewel, vector<jewel>, Less> pq;
	for (int i = 0; i < N; ++i) {
		cin >> m >> v;
		pq.push({ m, v });
	}

	int c;
	vector<int> bag;
	for (int i = 0; i < K; ++i) {
		cin >> c;
		bag.push_back(c);
	}
	sort(bag.begin(), bag.end());

	ull sum = 0;
	int idx = 0;
	priority_queue<int> possible;
	for (int i = 0; i < K; ++i) {
		int cur_bag = bag[i];

		while (!pq.empty()) {
			int cur_weight = pq.top().first;
			int cur_price = pq.top().second;
			if (cur_weight <= cur_bag) {
				possible.push(cur_price);
			}
			else break;
			pq.pop();
		}

		if (!possible.empty()) {
			sum += possible.top();
			possible.pop();
		}
 	}
	cout << sum;
	return 0;
}