#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> visited(matrix.size(),
            vector<bool>(matrix[0].size(), false));
        vector<int> ans;

        visited[0][0] = true;
        ans.push_back(matrix[0][0]);
        dfs(0, 0, matrix, visited, ans);

        return ans;
    }

    void dfs(int i, int j, vector<vector<int>>& matrix,
        vector<vector<bool>>& visited, vector<int>& ans) {

        int ni = i, nj = j;
        if (j < matrix[0].size() - 1 && !visited[i][j + 1] 
            && ((i == 0) || (i > 0 && visited[i-1][j]))) {
            nj = j + 1;
        }
        else if (i < matrix.size() - 1 && !visited[i + 1][j]) {
            ni = i + 1;
        }
        else if (j > 0 && !visited[i][j - 1]) {
            nj = j - 1;
        }
        else if (i > 0 && !visited[i - 1][j]) {
            ni = i - 1;
        }
        else {
            return;
        }
        visited[ni][nj] = true;
        ans.push_back(matrix[ni][nj]);
        dfs(ni, nj, matrix, visited, ans);
    }
};

int main() {
    Solution s;
    //vector<vector<int>> v{ {1, 2, 3},{4, 5, 6},{7, 8, 9 }};
    //vector<vector<int>> v{ {1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    vector<vector<int>> v{ {1,2,3,4 }, { 5,6,7,8 }, { 9,10,11,12 }, { 13,14,15,16 } };
    s.spiralOrder(v);
	return 0;
}