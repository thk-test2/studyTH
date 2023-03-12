#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        using cell = pair<int, int>;
        priority_queue<cell, vector<cell>, greater<cell>> q;
        int I = height.size(), J = height[0].size();
        if (I == 0) return 0;

        vector<vector<bool>> visited(I, vector<bool>(J, false));
        for (int i = 0; i < I; ++i) {
            for (int j = 0; j < J; ++j) {
                if ((i > 0 && i < I - 1) && (j > 0 && j < J - 1)) continue;
                if (visited[i][j]) continue;
                visited[i][j] = true;
                q.push(cell(height[i][j], i * J + j));
            }
        }

        int dir[4][2] = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };
        int total = 0;
        while (!q.empty()) {
            cell cur = q.top();
            q.pop();
            int i = cur.second / J, j = cur.second % J;

            for (int k = 0; k < 4; ++k) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if (ni < 0 || ni >= I || nj < 0 || nj >= J || visited[ni][nj])
                    continue;

                visited[ni][nj] = true;
                total += max(0, cur.first - height[ni][nj]);
                q.push(cell(max(cur.first, height[ni][nj]), ni * J + nj));
            }
        }
        return total;
    }
};

int main() {

    Solution s;
    vector<vector<int>> v{ {12, 13, 1, 12},{13, 4, 13, 12},{13, 8, 10, 12},{12, 13, 12, 12},{13, 13, 13, 13 } };
    cout << s.trapRainWater(v);
	
	return 0;
}