#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::iterator it = find (nums.begin(), nums.end(), target);
        int ret = 0;
        
        if (it != nums.end()) 
        { 
            ret = it - nums.begin();
        } else {
            vector<int>::iterator itr = nums.begin();
            for (int i=0; i<nums.size() ; i++)
            {
                if ( i == nums.size() -1 && target > nums.at(i) )
                {
                    nums.push_back(target);
                    ret = i+1;
                    break;
                }
                else if (target < nums.at(i))
                {
                    nums.insert(itr+i, target);
                    ret = i;
                    break;
                } else if (target > nums.at(i) && target < nums.at(i+1)) {
                    nums.insert(itr+i+1, target);
                    ret = i+1;
                    break;
                }

            }
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

    int target;
    cin >> target;

    Solution sol;
    int ret = sol.searchInsert(vec, target);
    
    cout << ret << endl;

    // for (auto i : vec) // Use regular for loop if you can't use c++11/14
    //     cout << i << '\n';

    return 0;
}