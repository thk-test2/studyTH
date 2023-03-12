#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int memo[101][101];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                memo[i][j] = 0;
            }
        }

        memo[1][1] = 1, memo[2][1] = 1, memo[1][2] = 1, memo[2][2] = 2;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (memo[i][j]) continue;
                // cout << i << ", " << j << "\n";
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }

        return memo[m][n];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}