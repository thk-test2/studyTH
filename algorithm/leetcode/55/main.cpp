#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>reachable) return false;
            else reachable = max(reachable, nums[i]+i);
        }
        return true;
    }
};

using namespace std;

int main()
{
    Solution S;
    //    vector<int> v = {2,3,1,1,4};
    vector<int> v = {3,2,1,0,4};
    cout << S.canJump(v);
    return 0;
}
