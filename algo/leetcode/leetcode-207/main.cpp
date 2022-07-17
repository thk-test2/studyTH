#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto& p : pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) q.push(i);
        while (!q.empty()) {
            int curr = q.front(); q.pop(); n--;
            for (auto next : adj[curr])
                if (--degree[next] == 0) q.push(next);
        }
        return n == 0;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v{ {0,1},{0,2},{1,2},{2,1} };
    s.canFinish(3, v);
	return 0;
}