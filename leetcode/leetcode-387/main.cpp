#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> um;

        int N = s.size();
        for (int i = 0; i < N; ++i) {
            if (um.count(s[i]) != 0) {
                um[s[i]].second++;
                continue;
            }
            um[s[i]] = { i, 1 };
        }

        int ans = 987654321;
        for (auto& itr : um) {
            if (itr.second.second == 1)
                ans = min(ans, itr.second.first);
        }
        return ans == 987654321 ? -1 : ans;
    }
};

int main() {
    string s("aabb");
    Solution so;
    so.firstUniqChar(s);
	
	return 0;
}