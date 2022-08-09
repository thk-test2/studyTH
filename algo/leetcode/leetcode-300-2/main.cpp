#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& subseq, int num) {
        int start = 0, end = subseq.size() - 1;
        int mid = 0;

        // lower_bound
        while (start < end) {
            mid = (start + end) / 2;
            if (subseq[mid] < num) {
                start = mid+1;
            }
            else {
                end = mid;
            }
        }
        //cout << mid << "\n";
        return end;
    }

    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> subseq;

        subseq.push_back(nums[0]);
        for (int i = 0; i < N; ++i) {
            if (subseq.back() < nums[i]) {
                subseq.push_back(nums[i]);
            }
            else {
                subseq[search(subseq, nums[i])] = nums[i];
            }
        }
        return subseq.size();
    }
};

int main() {
    Solution s;
	vector<int> v{ 10,9,2,5,3,7,101,18 };

    cout << s.lengthOfLIS(v);
	return 0;
}