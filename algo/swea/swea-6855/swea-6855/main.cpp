#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//int getCost(vector<int>& v, int start, int end) {
//	int cost = 0;
//
//	int mid = (start + end) / 2;
//	for (int i = start; i <= end; ++i) {
//		cost += abs(v[mid] - v[i]);
//	}
//	return cost;
//}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N, K, t;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N >> K;
		vector<int> v;

		for (register int i = 0; i < N; ++i) {
			cin >> t;
			v.push_back(t);
		}
		if (N <= K) {
			cout << "#" << test << " 0" << "\n";
			continue;
		}
		vector<int> len;
		for (int i = 0; i < N - 1; ++i) {
			len.push_back(v[i + 1] - v[i]);
		}
		sort(len.begin(), len.end());
		int sum = 0;
		for (int i = 0; i < N - K; ++i) {
			sum += len[i];
		}
		cout << "#" << test << " " << sum << "\n";
	}
	return 0;
}