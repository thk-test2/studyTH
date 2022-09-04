#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;

        if (root)
            travel(root, 0, 0, m);

        vector<vector<int>> ans;
        for (auto& it : m) {
            sort(it.second.begin(), it.second.end(), Compare());

            vector<int> v;
            for (auto& n : it.second) {
                v.push_back(n.second);
            }
            ans.push_back(v);
        }
        return ans;
    }

    void travel(TreeNode* node, int row, int col, map<int, vector<pair<int, int>>>& m) {
        m[col].push_back({ row, node->val });

        if (node->left) {
            travel(node->left, row + 1, col - 1, m);
        }
        if (node->right) {
            travel(node->right, row + 1, col + 1, m);
        }
    }
};

int main() {
	
	return 0;
}