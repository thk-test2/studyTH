#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (!digits.size()) return {};
        vector<string> v = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        string temp = "";
        vector<string> answer;
        checknode(0, temp, digits, answer, v);
        return answer;
    }

    void checknode(int level, string& temp, string& digits, vector<string>& answer,
        vector<string>& v) {
        if (level == digits.size()) {
            answer.push_back(temp);
            return;
        }

        int k = digits[level] - '0' - 2;
        for (int j = 0; j < v[k].size(); ++j) {
            temp += v[k][j];
            checknode(level + 1, temp, digits, answer, v);
            temp.pop_back();
        }
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    Solution s;
    string digits = "23";
    vector<string> ret = s.letterCombinations(digits);

	return 0;
}