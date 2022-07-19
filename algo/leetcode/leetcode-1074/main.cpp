#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int memo[100][100][100][100];

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int I = matrix.size(), J = matrix[0].size();
        memset(memo, -1, sizeof(memo));

        int sum = 0;
        for (int i = 0; i < I; ++i) {
            for (int j = 0; j < J; ++j) {
                sum += dfs(i, j, i, j, (matrix[i][j] == target ? 1 : 0),
                    matrix[i][j], matrix, target);
            }
        }
        return sum;
    }

    int dfs(int x1, int y1, int x2, int y2, int prev_cnt, int prev_sum,
        vector<vector<int>>& matrix, int target) {
        cout << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << prev_cnt << "\n";
        if (x2 >= matrix.size() || y2 >= matrix[0].size()) return 0;

        if (memo[x1][y1][x2][y2] != -1) return 0;
        if (x2 == matrix.size() - 1 && y2 == matrix[0].size() - 1) {
            cout << "END condition: " << x1 << ", " << y1
                << ", " << x2 << ", " << y2 << ", " << prev_cnt << "\n";
            return memo[x1][y1][x2][y2] = prev_cnt;
        }

        int ret = 0;

        if (y2 < matrix[0].size() - 1) {
            // Move one step to right
            int right_side = 0;
            for (int nx = x1; nx <= x2; ++nx) right_side += matrix[nx][y2 + 1];
            if (prev_sum + right_side == target)
                ret += dfs(x1, y1, x2, y2 + 1, prev_cnt + 1, prev_sum + right_side, matrix, target);
            else
                ret += dfs(x1, y1, x2, y2 + 1, prev_cnt, prev_sum + right_side, matrix, target);
        }

        if (x2 < matrix.size() - 1) {
            // Move one step to down
            int down_side = 0;
            for (int ny = y1; ny <= y2; ++ny) down_side += matrix[x2 + 1][ny];
            if (prev_sum + down_side == target)
                ret += dfs(x1, y1, x2 + 1, y2, prev_cnt + 1, prev_sum + down_side, matrix, target);
            else
                ret += dfs(x1, y1, x2 + 1, y2, prev_cnt, prev_sum + down_side, matrix, target);
        }
        return memo[x1][y1][x2][y2] = ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix{ {0,1,0},{1,1,1},{0,1,0} };
    cout << s.numSubmatrixSumTarget(matrix, 0);
	return 0;
}