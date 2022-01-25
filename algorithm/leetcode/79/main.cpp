#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool success = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    vector<bool> visited[n];
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                            visited[i].push_back(false);

                    dfs(board, word, visited, make_pair(i,j), make_pair(n,m), 0, success);
                }
                if (success)
                    break;
            }
        }

//        dfs(board, word, make_pair(0,0), make_pair(n,m), 0, success);
        return success;
    }
    void dfs(vector<vector<char>>& board, string word, vector<bool> visited[],
             pair<int,int> pos, pair<int,int> bound, int cnt, bool& success) {
        if (success)
            return;
        int i = pos.first;
        int j = pos.second;
        if (board[i][j] != word[cnt])
            return;
        if (board[i][j] == word[cnt]
                && cnt == word.size()-1) {
            success = true;
            return;
        }

        if (i < bound.first-1 && !visited[i+1][j]) {
            visited[i+1][j] = true;
            dfs(board, word, visited, make_pair(i+1, j), bound, cnt+1, success);
        }
        if (i > 0 && !visited[i-1][j]) {
            visited[i-1][j] = true;
            dfs(board, word, visited, make_pair(i-1, j), bound, cnt+1, success);
        }
        if (j < bound.second-1 && !visited[i][j+1]) {
            visited[i][j+1] = true;
            dfs(board, word, visited, make_pair(i, j+1), bound, cnt+1, success);
        }
        if (j > 0 && !visited[i][j-1]) {
            visited[i][j-1] = true;
            dfs(board, word, visited, make_pair(i, j-1), bound, cnt+1, success);
        }
    }

    void bfs(vector<vector<char>>& board, string word, int n, int m) {
        bool visited[n][m];
        bool success = false;

        queue<tuple<int,int,int>> q;
        q.push(make_tuple(0,0,0));
        visited[0][0] = true;

        while(!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int cnt = get<2>(q.front());
            q.pop();

            cout << i << ", " << j << ", " << cnt << endl;
            if (cnt == word.size()-1 && board[i][j] == word[cnt]) {
                success = true;
                cout << "SUCCESS: " << i << ", " << j << ", " << cnt << endl;
                break;
            }

            if (i < n-1 && !visited[i+1][j]) {
                visited[i+1][j] = true;
                q.push(make_tuple(i+1, j, cnt+1));
            }
            if (i > 0 && !visited[i-1][j]) {
                visited[i-1][j] = true;
                q.push(make_tuple(i-1, j, cnt+1));
            }
            if (j < m-1 && !visited[i][j+1]) {
                visited[i][j+1] = true;
                q.push(make_tuple(i, j+1, cnt+1));
            }
            if (j > 0 && !visited[i][j-1]) {
                visited[i][j-1] = true;
                q.push(make_tuple(i, j-1, cnt+1));
            }
        }
    }
};

int main()
{
    Solution S;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    string word2 = "SEE";
    string word3 = "ABCB";

    cout << S.exist(board, word) << endl;
    cout << S.exist(board, word2) << endl;
    cout << S.exist(board, word3) << endl;
    return 0;
}
