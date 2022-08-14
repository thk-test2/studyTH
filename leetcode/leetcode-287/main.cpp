#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for (int n : nums)
            {
                if (n <= mid) ++cnt;
            }

            // cout << low << ", " << high << ", " << mid << ", " << cnt << "\n";
            // binary search on right
            if (cnt <= mid)
                low = mid + 1;
            else
                // binary search on left
                high = mid - 1;

        }
        return low;
    }
};

int main() {
	
	return 0;
}