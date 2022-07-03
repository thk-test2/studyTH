#include <iostream>
#include <vector>

// Reference
// https://leetcode.com/problems/combination-sum-iii/discuss/60689/simple-c-backtracking-without-recursion

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> tmp(k);
        tmp[0] = 1;

        int l = 1, sum = 1;
        while (l > 0) // l is current length
        {
            if (l == k && sum == n) answer.push_back(tmp);

            if (l == k && tmp[l - 1] < 9) {
                ++tmp[l - 1];
                ++sum;
            }
            // last number is bad, forget it and increase the previous
            else if (l == k || tmp[l - 1] == 9 || sum > n) {
                if (l == 1) break; // we're going to remove the first one
                sum -= tmp[l - 1];

                --l;
                ++tmp[l - 1]; ++sum;
            }
            else {
                tmp[l] = tmp[l - 1] + 1;
                sum += tmp[l];
                ++l;
            }
        }
        return answer;
    }
};

//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<vector<int>> answer;
//         checknode(answer, {}, 1, 1, k, n);
//         return answer;
//     }
//     void checknode(vector<vector<int>>& answer, vector<int> tmp, int idx,
//                    int level, int k, int n) {
//         if (level == k+1) {
//             // cout << level << ", " << k << "\n";
//             auto sum = accumulate(tmp.begin(), tmp.end(), 0);
//             if (sum == n)
//                 answer.push_back(tmp);
//             return;
//         }

//         for (int i = idx; i < 10; ++i) {
//             tmp.push_back(i);
//             checknode(answer, tmp, i+1, level+1, k, n);
//             tmp.pop_back();
//         }
//     }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    Solution s;
    s.combinationSum3(3, 7);

	return 0;
}