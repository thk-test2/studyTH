#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;

        int prev = 0, cur = 0;
        while ((cur = s.find(' ', prev)) != string::npos) {
            string substr = s.substr(prev, cur - prev);
            for (auto c = substr.rbegin(); c != substr.rend(); ++c)
                ans += *c;
            ans += ' ';
            prev = cur + 1;
        }
        string substr = s.substr(prev, cur - prev);
        for (auto c = substr.rbegin(); c != substr.rend(); ++c)
            ans += *c;

        return ans;
    }
};

int main() {
	
	return 0;
}