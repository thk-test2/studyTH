#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (find(nums.begin(), nums.end(), target) == nums.end())
            return { -1, -1 };

        auto lb = lower_bound(nums.begin(), nums.end(), target);
        auto ub = upper_bound(nums.begin(), nums.end(), target);

        // cout << *lb << ", " << *ub << "\n";

        int ld = distance(nums.begin(), lb);
        int ud = distance(nums.begin(), ub);

        return { ld, ud - 1 };
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	return 0;
}