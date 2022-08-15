#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) return nums[0];

        vector<int> memo(N, 0);
        memo[0] = nums[0];
        memo[1] = max(memo[0], nums[1]);
        for (int i = 2; i < N; ++i) {
            memo[i] = max(memo[i - 2] + nums[i], memo[i - 1]);
        }
        return memo[N - 1];
    }
};

int main() {
	
	return 0;
}