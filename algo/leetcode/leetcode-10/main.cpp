#include <iostream>

using namespace std;

class Solution {
    int memo[21][31];
public:
    bool isMatch(string s, string p) {
        memset(memo, -1, sizeof(memo));
        return isMatch(s, p, 0, 0);
    }

    bool isMatch(string s, string p, int i, int j) {
        if (j >= p.size())
            return memo[i][j] = (i == s.size() ? 1 : 0);

        if (memo[i][j] != -1) return memo[i][j];

        if (p.size() - j >= 2 && p[j + 1] == '*') {
            if (isMatch(s, p, i, j + 2)) return memo[i][j] = 1;

            int index = i;
            while (index < s.size() && (s[index] == p[j] || p[j] == '.')) {
                if (isMatch(s, p, ++index, j + 2))
                    return memo[i][j] = 1;
            }
            return memo[i][j] = 0;
        }
        else {
            if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
                return memo[i][j] = isMatch(s, p, i + 1, j + 1);
            else
                return memo[i][j] = 0;
        }
    }
};

int main() {
    Solution s;
    //cout << s.isMatch("aa", "a");
    //cout << s.isMatch("aa", "a*");
    //cout << s.isMatch("ab", ".*");
    //cout << s.isMatch("aab", "c*a*b");
    cout << s.isMatch("ab", ".*c");
	return 0;
}