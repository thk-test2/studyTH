#include <iostream>

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

class Solution {
public:
    TreeNode* pruneTree(TreeNode* node) {
        if (node && node->left) {
            node->left = pruneTree(node->left);
        }
        if (node && node->right) {
            node->right = pruneTree(node->right);
        }

        if (node && !node->left && !node->right) {
            if (node->val == 0)
                node = nullptr;
        }
        return node;
    }
};

int main() {
	
	return 0;
}