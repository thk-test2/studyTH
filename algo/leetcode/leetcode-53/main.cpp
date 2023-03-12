#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, -10001);

        int ans = -10001;
        dp[0] = nums[0];
        for (int i = 1; i < N; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);

            // dp[i] = (dp[i-1] > 0 ? dp[i-1] : 0) + nums[i];
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(v);
	
	return 0;
}