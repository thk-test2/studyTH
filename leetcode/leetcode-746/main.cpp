#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N = cost.size();
        vector<int> memo(N + 1, 999999);

        memo[0] = memo[1] = 0;
        for (int i = 2; i <= N; ++i) {
            memo[i] = min(cost[i - 1] + memo[i - 1], cost[i - 2] + memo[i - 2]);
        }
        return memo[N];

        // return min(checknode(0, cost, memo), checknode(1, cost, memo));
    }

    //     int checknode(int index, vector<int>& cost, vector<int>& memo) {
    //         if (index == cost.size()) return 0;
    //         if (index > cost.size()) return 999999;
    //         if (memo[index] != 999999) return memo[index];

    //         memo[index] = min(memo[index], cost[index] + checknode(index+1, cost, memo));
    //         memo[index] = min(memo[index], cost[index] + checknode(index+2, cost, memo));

    //         return memo[index];
    //     }
};

int main() {
	
	return 0;
}