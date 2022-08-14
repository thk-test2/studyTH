#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        if (!N || !wordDict.size()) return false;

        unordered_set<string> us;
        for (auto& itr : wordDict)
            us.insert(itr);

        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (!dp[j]) continue;

                string temp = s.substr(j, i - j);
                if (us.find(temp) != us.end()) {
                    // cout << "Found: " << temp << " ," << i << ", " << j << "\n";
                    dp[i] = true; break;
                }
            }
        }
        return dp[N];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}