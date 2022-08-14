#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> temp;
            combi(0, i, temp, nums, ans);
        }
        return ans;
    }

    void combi(int idx, int target, vector<int>& temp,
        vector<int>& nums, vector<vector<int>>& ans) {
        if (temp.size() == target) {
            ans.push_back(temp);
            return;
        }

        for (int k = idx; k < nums.size(); ++k) {
            temp.push_back(nums[k]);
            combi(k + 1, target, temp, nums, ans);
            temp.pop_back();
        }
    }
};

int main() {
	
	return 0;
}