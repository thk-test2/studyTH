#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string text, string pattern) {

        vector<int> table = makeTable(pattern);

        int textSize = text.size(), patternSize = pattern.size();
        int j = 0, ans = -1;

        for (int i = 0; i < textSize; ++i) {
            while (j > 0 && text[i] != pattern[j]) {
                j = table[j - 1];
            }
            if (text[i] == pattern[j]) {
                if (j == patternSize - 1) {
                    ans = i - j;
                    break;
                }
                else {
                    j++;
                }
            }
        }
        return ans;
    }

    vector<int> makeTable(string pattern) {
        int patternSize = pattern.size();
        vector<int> table(patternSize, 0);
        int j = 0;

        for (int i = 1; i < patternSize; ++i) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = table[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                table[i] = ++j;
            }
        }
        return table;
    }
};

int main() {
	
	return 0;
}