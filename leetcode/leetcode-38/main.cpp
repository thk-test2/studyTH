#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        return checknode(n);
    }

    string checknode(int n) {
        if (n == 1) return "1";

        string str = checknode(n - 1);

        string ret;
        char prev = str[0];
        int cnt = 1;
        for (int i = 1; i < str.size(); ++i) {
            // cout << ret << ", " << i << ", " << cnt << ", " << prev << "\n";
            if (str[i] == prev) {
                cnt++;
            }
            else {
                ret += (cnt + '0');
                ret += prev;
                cnt = 1;
                prev = str[i];
            }
        }
        ret += (cnt + '0');
        ret += prev;

        return ret;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}