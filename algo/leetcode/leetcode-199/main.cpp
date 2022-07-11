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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root)
            travel(root, 1);

        vector<int> rightside;
        for (int i = 1; i <= max_height; ++i)
            rightside.push_back(um[i]);
        return rightside;
    }

    void travel(TreeNode* node, int height) {
        um[height] = node->val;
        max_height = max(max_height, height);
        if (node->left)
            travel(node->left, height + 1);
        if (node->right)
            travel(node->right, height + 1);
    }

    int max_height = 0;
    unordered_map<int, int> um;
};

int main() {
	
	return 0;
}