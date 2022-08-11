#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 1);

        int prod = 1;
        for (int i = 1; i < N; ++i)
        {
            prod = nums[i - 1] * prod;
            ans[i] = prod;
        }

        prod = 1;
        for (int i = N - 2; i >= 0; --i) {
            prod = prod * nums[i + 1];
            ans[i] *= prod;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}