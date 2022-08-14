#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        // vector<vector<int>> ans;
        // vector<int> temp;
        // permute_recur(0, nums, 0, temp, ans);
        return ans;
    }

    void permute_recur(int cnt, vector<int>& nums,
        int selected,
        vector<int>& temp,
        vector<vector<int>>& ans) {
        if (cnt == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int k = 0; k < nums.size(); ++k) {
            if (selected & (1 << k)) continue;
            selected |= (1 << k);
            temp.push_back(nums[k]);
            permute_recur(cnt + 1, nums, selected, temp, ans);

            selected &= ~(1 << k);
            temp.pop_back();
        }
    }
};

int main() {
	
	return 0;
}