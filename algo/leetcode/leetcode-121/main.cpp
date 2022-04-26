#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int i, mi = prices[0], z = 0;
		for (i = 1; i < prices.size(); i++) {
			if (prices[i] < mi) mi = prices[i];
			else z = max(z, prices[i] - mi);
		}
		return z;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Solution s;
	int T, N, n;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		vector<int> prices;
		for (int i = 0; i < N; ++i) {
			cin >> n;
			prices.push_back(n);
		}
		cout << s.maxProfit(prices) << "\n";
	}
	return 0;
}