#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int minNum = nums.at(0);
        int maxNum = nums.at(0);
        int ret = nums.at(0);

        for (int i = 1; i < nums.size(); i++) {
            int tmp = maxNum;
            maxNum = max( max(nums[i]*maxNum, nums[i]*minNum), nums[i] );
            minNum = min( min(nums[i]*tmp, nums[i]*minNum), nums[i] );
            ret = max(ret, maxNum);
        }

        return ret;    
    }
};

int main() {

    string line;
    string word;
    getline(cin, line);
    stringstream ss(line);

    vector<int> vec;
    while (getline(ss, word, ',')) {
        vec.emplace_back(stoi(word));
    }

    Solution sol;
    int ret = sol.maxProduct(vec);
    
    cout << ret << endl;

    return 0;
}