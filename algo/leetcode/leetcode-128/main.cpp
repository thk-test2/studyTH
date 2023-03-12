#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (auto& itr : nums)
            num_set.insert(itr);

        int current_num = 0, current_len = 0, longest_len = 0;
        for (auto& num : num_set) {
            if (num_set.count(num - 1) == 0) {
                current_num = num;
                current_len = 1;

                while (num_set.count(current_num + 1) != 0) {
                    current_num++;
                    current_len++;
                }
                longest_len = max(longest_len, current_len);
            }
        }
        return longest_len;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}