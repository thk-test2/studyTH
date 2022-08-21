#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        // calculate the index of the last element of the merged array

        // go from the back by nums1 and nums2 and compare and put to the nums1 element
        // which is larger
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        // if nums2 is longer than nums1 just copy the rest of nums2 to nums1 location,
        // otherwise no need to do anything
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

int main() {
	
	return 0;
}