#include <iostream>
#include <vector>

using namespace std;


class Solution {
    // int di[4] = {-1, 1, 0, 0};
    // int dj[4] = {0, 0, -1, 1};
    // using Node = pair<int, int>;

    int dp[200][200]{};
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();

        int max_len = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                max_len = max(max_len, dfs(i, j, -1, matrix));
            }
        }
        return max_len;
    }

    int dfs(int ci, int cj, int prev,
        vector<vector<int>>& mat) {
        if (ci < 0 || ci >= m || cj < 0 || cj >= n || mat[ci][cj] <= prev) return 0;
        if (dp[ci][cj]) return dp[ci][cj];

        int temp_len = 1 + max({
            dfs(ci + 1, cj, mat[ci][cj], mat),
            dfs(ci - 1, cj, mat[ci][cj], mat),
            dfs(ci, cj + 1, mat[ci][cj], mat),
            dfs(ci, cj - 1, mat[ci][cj], mat),
            });
        return dp[ci][cj] = temp_len;
    }

    //     int dfs(int i, int j, int m, int n, 
    //             vector<vector<int>>& matrix) {
    //         stack<Node> st;
    //         st.push({i, j});

    //         int tmp_len = 0;
    //         while (!st.empty()) {
    //             Node cur = st.top();
    //             st.pop();

    //             tmp_len = max(tmp_len, dp[cur.first][cur.second]);
    //             for (int k = 0; k < 4; ++k) {
    //                 int ni = cur.first + di[k], nj = cur.second + dj[k];
    //                 if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
    //                 if (matrix[ni][nj] <= matrix[cur.first][cur.second]) continue;

    //                 if (dp[ni][nj] > dp[cur.first][cur.second]) continue;
    //                 dp[ni][nj] = dp[cur.first][cur.second] + 1;

    //                 st.push({ni, nj});
    //             }
    //         }
    //         return tmp_len;
    //     }
};

int main() {
	
	return 0;
}