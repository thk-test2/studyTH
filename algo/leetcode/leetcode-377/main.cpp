#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // int combinationSum4(vector<int>& nums, int target) {
    //     memset(memo, -1, sizeof(memo));
    //     int ret = checknode(0, target, nums);
    //     return ret;        
    // }
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target + 1);
        dp[0] = 1;

        for (int cur = 1; cur <= target; ++cur) {
            for (auto& n : nums) {
                if (n <= cur) {
                    dp[cur] += dp[cur - n];
                }
            }
        }
        return dp[target];
    }

    int checknode(int cur, int target, vector<int>& nums)
    {
        if (cur >= target) {
            if (cur == target) return 1;
            else return 0;
        }
        if (memo[cur] != -1) return memo[cur];

        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret += checknode(cur + nums[i], target, nums);
        }
        return memo[cur] = ret;
    }

    int memo[1001];
};

int main() {
	
	return 0;
}