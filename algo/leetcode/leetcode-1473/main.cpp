#include <iostream>
#include <vector>

using namespace std;

int memo[101][101][21];

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo, -1, sizeof(memo));
        int ret = checknode(0, 0, 0, houses, cost, target);
        return ret != 987654321 ? ret : -1;
    }

    int checknode(int idx, int ncount, int prev,
        vector<int>& houses, vector<vector<int>>& cost, int target) {
        
        if (idx == houses.size())
            return ncount == target ? 0 : 987654321;
        else if (idx > houses.size())
            return 987654321;

        if (memo[idx][ncount][prev] != -1) return memo[idx][ncount][prev];

        int ret = 987654321;
        if (houses[idx] != 0) {
            if (houses[idx] != prev)
                ret = min(ret, checknode(idx + 1, ncount + 1, houses[idx], houses, cost, target));
            else
                ret = min(ret, checknode(idx + 1, ncount, houses[idx], houses, cost, target));
        }
        else {
            for (int j = 0; j < cost[idx].size(); ++j) {
                if (j+1 != prev)
                    ret = min(ret, cost[idx][j] + checknode(idx + 1, ncount + 1, j+1, houses, cost, target));
                else
                    ret = min(ret, cost[idx][j] + checknode(idx + 1, ncount, j+1, houses, cost, target));
            }
        }
        return memo[idx][ncount][prev] = ret;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    Solution s;
    vector<int> houses = { 0,0,0,0,0 };
    //vector<int> houses = { 0,2,1,2,0 };
    vector<vector<int>> cost = { {1,10},{10,1},{10,1},{1,10},{5,1} };
    cout << s.minCost(houses, cost, 5, 2, 3);

    //vector<int> houses = { 3,1,2,3 };
    //vector<vector<int>> cost = { {1,1,1},{1,1,1},{1,1,1},{1,1,1} };
    //cout << s.minCost(houses, cost, 4, 3, 3);

	return 0;
}