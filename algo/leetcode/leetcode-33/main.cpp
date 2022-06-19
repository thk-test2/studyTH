#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = 0;
        if (nums[0] > nums[nums.size() - 1])
            pivot = findPivot(nums);

        int target_idx = 0;
        if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {
            target_idx = binarySearch(nums, pivot, nums.size() - 1, target);
            // cout << "11: " << pivot << ", " << target << ", " << target_idx << "\n";
        }
        else {
            target_idx = binarySearch(nums, 0, pivot - 1, target);
            // cout << "22: " << pivot << ", " << target << ", " << target_idx << "\n";
        }
        return target_idx;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target) {
        int mid, answer;
        while (start <= end) {
            mid = (start + end) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                answer = mid;
                break;
            }
        }
        return start <= end ? answer : -1;
    }

    int findPivot(vector<int>& nums) {
        int N = nums.size();
        int start = 0, end = N - 1;
        int mid, answer;

        while (start <= end) {
            mid = (start + end) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                answer = mid;
                break;
            }
            else {
                if (nums[mid] > nums[N - 1]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return answer;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}