#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bool> visited[301];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i].push_back(false);
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    bfs(grid, visited, i, j, m, n);
                }
            }
        }
        return cnt;
    }

    void bfs(vector<vector<char>>& grid, vector<bool> visited[],
        int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({ i, j });
        visited[i][j] = true;

        while (!q.empty()) {
            int cI = q.front().first;
            int cJ = q.front().second;
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nI = cI + dirI[k];
                int nJ = cJ + dirJ[k];
                if (nI < 0 || nI >= m || nJ < 0 || nJ >= n) continue;
                if (grid[nI][nJ] == '0') continue;
                if (visited[nI][nJ]) continue;
                visited[nI][nJ] = true;
                q.push({ nI, nJ });
            }
        }
    }

    int dirI[4] = { -1, 1, 0, 0 };
    int dirJ[4] = { 0, 0, -1, 1 };
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    //vector<vector<char>> grid = {
    //    {'1','1','1','1','0'},
    //    {'1','1','0','1','0'},
    //    {'1','1','0','0','0'},
    //    {'0','0','0','0','0'} };
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'} };

    Solution s;
    cout << s.numIslands(grid);
	return 0;
}