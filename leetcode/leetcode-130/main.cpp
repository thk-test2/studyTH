#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int di[4] = { -1, 1, 0, 0 };
    int dj[4] = { 0, 0, -1, 1 };
public:
    void solve(vector<vector<char>>& board) {
        int M = board.size(), N = board[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));

        for (int i = 1; i < M - 1; ++i) {
            for (int j = 1; j < N - 1; ++j) {
                if (board[i][j] == 'X' || visited[i][j]) continue;
                bfs(i, j, board, visited);
            }
        }
    }

    void bfs(int i, int j, vector<vector<char>>& board,
        vector<vector<bool>>& visited) {
        int M = board.size(), N = board[0].size();

        queue<pair<int, int>> q;
        q.push({ i, j });
        visited[i][j] = true;

        vector<pair<int, int>> v;
        v.push_back({ i, j });
        bool captured = true;
        while (!q.empty()) {

            auto cur = q.front(); q.pop();
            if (cur.first == 0 || cur.first == M - 1
                || cur.second == 0 || cur.second == N - 1) {
                captured = false;
            }

            for (int k = 0; k < 4; ++k) {
                int ni = cur.first + di[k], nj = cur.second + dj[k];
                if (ni < 0 || ni >= M || nj < 0 || nj >= N) continue;
                if (visited[ni][nj] || board[ni][nj] == 'X') continue;

                visited[ni][nj] = true;
                q.push({ ni, nj });
                v.push_back({ ni, nj });
            }
        }
        if (captured) {
            for (auto& t : v) {
                board[t.first][t.second] = 'X';
            }
        }
    }
};

int main() {

    vector<vector<char>> v{ {'X', 'O', 'X', 'O', 'O', 'O', 'O'},{'X', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'X', 'O', 'O', 'O', 'O', 'X', 'O'},{'O', 'O', 'O', 'O', 'X', 'O', 'X'},
        {'O', 'X', 'O', 'O', 'O', 'O', 'O'},{'O', 'O', 'O', 'O', 'O', 'O', 'O'},{'O', 'X', 'O', 'O', 'O', 'O', 'O'}};

    Solution s;
    s.solve(v);
	
	return 0;
}