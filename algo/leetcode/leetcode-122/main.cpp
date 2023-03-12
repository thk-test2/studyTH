#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, N = prices.size();
        for (int i = 0; i < N - 1; ++i) {
            profit += max(prices[i + 1] - prices[i], 0);
        }
        return profit;
    }
};

int main() {
    vector<int> v{2,1,2,0,1};

    Solution s;
    s.maxProfit(v);
	
	return 0;
}