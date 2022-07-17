#include <iostream>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo, -1, sizeof(memo));
        return dfs(m, n, maxMove, startRow, startColumn);
    }

    int dfs(int m, int n, int maxMove, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n)
            return 1;
        if (maxMove <= 0) return 0;
        if (memo[maxMove][row][col] != -1) return memo[maxMove][row][col];

        int ret = 0;
        ret += dfs(m, n, maxMove - 1, row - 1, col); ret %= 1000000007;
        ret += dfs(m, n, maxMove - 1, row + 1, col); ret %= 1000000007;
        ret += dfs(m, n, maxMove - 1, row, col - 1); ret %= 1000000007;
        ret += dfs(m, n, maxMove - 1, row, col + 1); ret %= 1000000007;
        return memo[maxMove][row][col] = ret;
    }

    int memo[51][51][51];
};

int main() {
	
	return 0;
}