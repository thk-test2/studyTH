#include <iostream>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int I = grid.size(), J = grid[0].size();

        int max_cnt = 0;
        for (int i = 0; i < I; ++i) {
            for (int j = 0; j < J; ++j) {
                if (grid[i][j] == 0) continue;
                max_cnt = max(max_cnt, dfs(grid, i, j, I, J));
            }
        }
        return max_cnt;
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int I, int J) {
        int cnt = 1;

        if (i < 0 || i >= I || j < 0 || j >= J) return 0;
        if (grid[i][j] == 0) return 0;
        grid[i][j] = 0;
        cnt += dfs(grid, i - 1, j, I, J);
        cnt += dfs(grid, i + 1, j, I, J);
        cnt += dfs(grid, i, j - 1, I, J);
        cnt += dfs(grid, i, j + 1, I, J);

        return cnt;
    }
};

int main() {
	
	return 0;
}