#include <iostream>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        memset(memo, -1, sizeof(memo));
        int ret = checknode(0, 0, 0, s1, s2, s3);
        return ret != 0 ? true : false;
    }

    int checknode(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (k == s3.size()) {
            return 1;
        }
        if (memo[i][j] != -1) return memo[i][j];

        int ret = 0;
        if (s1[i] == s3[k])
            ret = checknode(i + 1, j, k + 1, s1, s2, s3);
        if (ret == 0 && s2[j] == s3[k])
            ret = checknode(i, j + 1, k + 1, s1, s2, s3);

        return memo[i][j] = ret;
    }

    int memo[101][101];
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}