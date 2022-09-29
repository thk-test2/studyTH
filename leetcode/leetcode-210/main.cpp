#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> answer;

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
            int curr = q.front(); 
            q.pop(); n--;
            answer.push_back(curr);

            for (auto next : adj[curr])
                if (--degree[next] == 0) {
                    q.push(next);
                }
        }
        if (n == 0) {
            return answer;
        }
        else {
            return {};
        }
    }
};

int main() {
	
	return 0;
}