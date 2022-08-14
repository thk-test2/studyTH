#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        // Reverse the first n - k numbers.
        // Index i (0 <= i < n - k) becomes n - k - i.
        reverse(nums.begin(), nums.begin() + n - k);

        // Reverse tha last k numbers.
        // Index n - k + i (0 <= i < k) becomes n - i.
        reverse(nums.begin() + n - k, nums.end());

        // Reverse all the numbers.
        // Index i (0 <= i < n - k) becomes n - (n - k - i) = i + k.
        // Index n - k + i (0 <= i < k) becomes n - (n - i) = i.
        reverse(nums.begin(), nums.end());
    }

    //     void rotate(vector<int>& nums, int k) {
    //         int temp = nums[0];
    //         int cnt = 0, N = nums.size(), i = 0, ni = 0;

    //         vector<bool> visited(N, false);
    //         while (cnt < N) {
    //             while (true) {
    //                 ni = (i + k) % N;
    //                 if (visited[ni]) {
    //                     i++;
    //                     temp = nums[i];
    //                 } else break;
    //             }
    //             swap(nums[ni], temp);
    //             visited[ni] = true;
    //             cnt++;

    //             i = ni;
    //         }
    //     }
};

int main() {
	
	return 0;
}