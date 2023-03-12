#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    vector<int> v[1000];
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return vector<vector<int>>();
        queue<pair<Node*, int>> q;
        q.push({ root, 0 });

        int max_height = -1;
        while (!q.empty()) {
            pair<Node*, int> cur = q.front();
            q.pop();

            if (!cur.first) continue;
            v[cur.second].push_back(cur.first->val);
            max_height = max(max_height, cur.second);

            for (auto& node : cur.first->children) {
                q.push({ node, cur.second + 1 });
            }
        }

        vector<vector<int>> ans(max_height + 1);
        for (int i = 0; i <= max_height; ++i)
            ans[i] = move(v[i]);

        return ans;
    }
};

int main() {
	
	return 0;
}