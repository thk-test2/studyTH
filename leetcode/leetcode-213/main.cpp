#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N == 1) return nums[0];
        else if (N == 2) return nums[0] >= nums[1] ? nums[0] : nums[1];

        vector<int> memo(N, 0), memo_2(N, 0);
        memo[1] = nums[1];
        memo[2] = max(memo[1], nums[2]);

        memo_2[0] = nums[0];
        memo_2[1] = max(memo_2[0], nums[1]);

        for (int i = 2; i < N; ++i) {
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
            memo_2[i] = max(memo_2[i - 2] + nums[i], memo_2[i - 1]);
        }

        return memo[N - 1] >= memo_2[N - 2] ? memo[N - 1] : memo_2[N - 2];
    }
};

int main() {
	
	return 0;
}