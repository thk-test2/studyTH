#include <iostream>

using namespace std;

class Solution {
private:
    int lo = 0, maxren = 0;

public:
    string longestPalindrome(string s) {
        int N = s.size();
        if (N <= 1) return s;

        for (int i = 0; i < N - 1; ++i) {
            checkPalindrome(s, i, i);
            checkPalindrome(s, i, i + 1);
        }

        return s.substr(lo, maxren);
    }
    void checkPalindrome(string s, int j, int k) {
        while (j >= 0 && k < s.size() && s[j] == s[k]) {
            j--; k++;
        }
        if (maxren < k - j - 1) {
            lo = j + 1;
            maxren = k - j - 1;
        }
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}