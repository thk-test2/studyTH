#include <iostream>
#include <vector>

using namespace std;

/*
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
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        if (nums.size() == 1)
            return true;

        int numSize = nums.size();
        vector<bool> visited(numSize, false);

        checknode(0, nums, visited);
        return visited[numSize - 1];
    }

    void checknode(int i, vector<int>& nums, vector<bool>& visited) {
        if (i >= nums.size() - 1 || visited[nums.size() - 1])
            return;

        for (int k = nums[i]; k > 0; --k) {
            if (i + k >= nums.size() - 1) {
                visited[nums.size() - 1] = true;
                break;
            }
            if (visited[i + k]) continue;
            visited[i + k] = true;
            checknode(i + k, nums, visited);
        }
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}