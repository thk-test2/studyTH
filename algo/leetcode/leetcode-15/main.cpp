#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3) return ans;

        sort(nums.begin(), nums.end()); //[-4,-1,-1,0,1,2]
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {

                int l = i + 1, h = nums.size() - 1, sum = 0 - nums[i];
                while (l < h) {
                    if (nums[l] + nums[h] == sum) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[h]);

                        ans.push_back(temp);
                        while (l < h && (nums[l] == nums[l + 1])) l++;
                        while (l < h && (nums[h] == nums[h - 1])) h--;
                        l++; h--;
                    }
                    else if ((nums[l] + nums[h]) < sum) {
                        l++;
                    }
                    else {
                        h--;
                    }
                }
            }
        }
        return ans;
    }
};

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {

		cout << "#" << test << "\n";
	}

	return 0;
}