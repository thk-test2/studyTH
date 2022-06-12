#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth = 0;

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> v;
        if (root)
            calDepth(root, 0);

        for (int i = 0; i <= depth; ++i)
            v.push_back({});
        if (root)
            zorder(root, 0, v);
        return v;
    }

    void calDepth(TreeNode* node, int level) {
        if (node->left) {
            calDepth(node->left, level + 1);
        }
        if (node->right) {
            calDepth(node->right, level + 1);
        }
        depth = max(depth, level);
    }

    void zorder(TreeNode* node, int level, vector<vector<int>>& v) {
        if (level % 2 != 0) {
            v[level].insert(v[level].begin(), node->val);
        }
        else {
            v[level].push_back(node->val);
        }
        if (node->left)
            zorder(node->left, level + 1, v);

        if (node->right)
            zorder(node->right, level + 1, v);
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {

		cout << "#" << test << "\n";
	}

	return 0;
}