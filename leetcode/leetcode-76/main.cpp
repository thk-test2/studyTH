#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, int> s_m;
    unordered_map<char, int> t_m;
public:
    bool nowSubstr() {
        for (auto& p : t_m) {
            if (s_m[p.first] < p.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (char c : t) t_m[c]++;

        int l = 0, r = 0, Size = s.size();
        s_m[s[r]]++;

        string ans, sub;
        while (l <= r && r < Size) {
            if (nowSubstr()) {
                sub = s.substr(l, r - l + 1);
                if (ans.empty() || ans.size() > sub.size()) ans = sub;
                s_m[s[l++]]--;
            }
            else {
                s_m[s[++r]]++;
            }
        }
        return ans;
    }
};

int main() {
    string s("ab"), t("a");
    Solution so;
    so.minWindow(s, t);
	return 0;
}