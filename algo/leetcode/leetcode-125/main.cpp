#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.length();

        int l = 0, r = N - 1;
        while (l < r) {
            while (l <= r && s[l] < 'a' || s[l] > 'z') {
                if (s[l] >= 'A' && s[l] <= 'Z') {
                    s[l] = s[l] + 32;
                    break;
                }
                else {
                    l++;
                }
            }
            while (l <= r && s[r] < 'a' || s[r] > 'z') {
                if (s[r] >= 'A' && s[r] <= 'Z') {
                    s[r] = s[r] + 32;
                    break;
                }
                else {
                    r--;
                }
            }
            if (l >= r) break;
            else if (s[l] == s[r]) {
                l++; r--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {

    //string s = "A man, a plan, a canal: Panama";
    //string s = " ";
    string s = ".,";
    Solution so;
    cout << so.isPalindrome(s);
	
	return 0;
}