#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int memo[4][65536];

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int N = matchsticks.size();
        if (N < 4) return false;

        memset(memo, -1, sizeof(memo));
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        int ret = checknode(0, 0, 0, sum / 4, 0, matchsticks);
        return ret == 1 ? true : false;
    }

    int checknode(int level, int groups, int curlen, int targetlen, int bitstate,
        vector<int>& matchsticks) {
        if (level == matchsticks.size()) {
            return (groups == 4 && curlen == 0) ? 1 : 0;
        }
        if (groups >= 4) return 0;
        if (memo[groups][bitstate] != -1) return memo[groups][bitstate];

        int ret = 0;
        for (int k = 0; k < matchsticks.size(); ++k) {
            if (bitstate & (1 << k)) continue;
            bitstate |= (1 << k);
            if (curlen + matchsticks[k] < targetlen && ret != 1)
                ret = checknode(level + 1, groups, curlen + matchsticks[k], targetlen, bitstate, matchsticks);
            else if (curlen + matchsticks[k] == targetlen && ret != 1)
                ret = checknode(level + 1, groups + 1, 0, targetlen, bitstate, matchsticks);
            bitstate &= ~(1 << k);
        }
        return memo[groups][bitstate] = ret;
    }
};

int main() {
    Solution s;
    //vector<int> v = { 1,2,3,4,5,6,7,8,9,10,5,4,3,2,1 };
    //vector<int> v = { 1,1,2,2,2 };
    //vector<int> v = { 3,3,3,3,4 };
    vector<int> v = { 5,5,5,5,4,4,4,4,3,3,3,3 };
    //vector<int> v = { 14,17,2,10,2,19,11,1,16,7,13,16,11,3,9 };
    cout << s.makesquare(v);

	return 0;
}