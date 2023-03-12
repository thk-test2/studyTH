#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = accumulate(nums.begin(), nums.end(), 0,
            [](int cur, int m) {
            return m % 2 == 0 ? cur + m : cur;
        });

        int N = nums.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            int idx = queries[i][1], val = queries[i][0];

            if (nums[idx] % 2 == 0) {
                evenSum -= nums[idx];
            }
            nums[idx] += val;
            if (nums[idx] % 2 == 0) {
                evenSum += nums[idx];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};

int main() {
	
	return 0;
}