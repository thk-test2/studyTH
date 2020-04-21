/* April 2020, 30 days leetcode challenge day 1 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> compare;
        vector<int>::iterator it;
        
        for (const auto & itr : nums) {
            
            it = find(compare.begin(), compare.end(), itr);
            
            if(it != compare.end()) {
                compare.erase(it);
            } else {
                compare.push_back(itr);
            }
        }
        return compare.front();
    }
};
