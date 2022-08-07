#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> memo(6, vector<int>(n + 1, -1));

        int ret = checknode(0, 0, n, memo);
        return ret;
    }

    int checknode(int cur, int level, int n, vector<vector<int>>& memo) {
        if (level == n) {
            return 1;
        }
        if (memo[cur][level] != -1) return memo[cur][level];

        int ret = 0;
        if (cur == 1) {
            ret += checknode(2, level + 1, n, memo); ret %= 1000000007;
        }
        else if (cur == 2) {
            ret += checknode(1, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(3, level + 1, n, memo); ret %= 1000000007;
        }
        else if (cur == 3) {
            ret += checknode(1, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(2, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(4, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(5, level + 1, n, memo); ret %= 1000000007;
        }
        else if (cur == 4) {
            ret += checknode(3, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(5, level + 1, n, memo); ret %= 1000000007;
        }
        else if (cur == 5) {
            ret += checknode(1, level + 1, n, memo); ret %= 1000000007;
        }
        else {
            ret += checknode(1, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(2, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(3, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(4, level + 1, n, memo); ret %= 1000000007;
            ret += checknode(5, level + 1, n, memo); ret %= 1000000007;
        }
        return memo[cur][level] = ret;
    }
};

int main() {
	
	return 0;
}