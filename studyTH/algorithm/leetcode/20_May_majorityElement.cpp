class Solution {
public:
    int majorityElement(vector<int>& nums) {
 
        std::vector<pair<int, int>> count;
        int result;
        
        if (nums.size() == 1)
            return nums.front();
        
        for (const auto & itr : nums) {

            auto it = std::find_if( count.begin(), count.end(),
            [&itr](const std::pair<int, int>& count){ return count.first == itr;});
            
            if (it != count.end()) {
                it->second++;
                if (it->second > nums.size()/2) {
                    cout << itr << endl;
                    result = itr;
                    break;
                }
            } else {
                count.push_back(make_pair(itr, 1));
            }
        }
        return result;
    }
};
