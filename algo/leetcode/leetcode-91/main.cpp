#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        vector<int> dp(N + 1, 0);

        dp[N] = 1;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] != '0')
                dp[i] += dp[i + 1];
            if (i < N - 1) {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
                    dp[i] += dp[i + 2];
            }
        }
        return s.empty() ? 0 : dp[0];
    }

    //     int numDecodings(string s) {
    //         int N = s.size();
    //         vector<int> memo(N + 1, -1);
    //         memo[N] = 1;

    //         return s.empty() ? 0 : checknode(0, s, memo);
    //     }
    //     int checknode(int i, string& s, vector<int>& memo) {
    //         if (s[i] == '0') return 0;
    //         if (memo[i] != -1) return memo[i];

    //         int res = checknode(i+1, s, memo);
    //         if (i < s.size()-1 && s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6'))
    //             res += checknode(i+2, s, memo);
    //         return memo[i] = res;
    //     }
};

int main() {
    string str("12");
    //string str("11");
    //string str("2101");
    //string str("10011");

    Solution s;
    cout << s.numDecodings(str);
	return 0;
}