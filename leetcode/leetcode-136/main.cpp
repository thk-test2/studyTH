#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int prev = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (prev != nums[i]) {
                if (cnt == 1) break;
                prev = nums[i];
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        return prev;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}