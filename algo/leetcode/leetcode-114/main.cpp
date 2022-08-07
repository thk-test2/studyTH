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
    TreeNode* listHead = new TreeNode();
    TreeNode* listTail = listHead;

    void flatten(TreeNode* root) {
        if (root)
            preorder(root);
        else
            return;

        root->left = nullptr;
        if (listHead != listTail)
            root->right = listHead->right->right;
    }

    void preorder(TreeNode* node) {
        listTail->right = new TreeNode(node->val);
        listTail = listTail->right;
        // cout << node->val << ", " << "\n";
        if (node->left) {
            preorder(node->left);
        }
        if (node->right) {
            preorder(node->right);
        }
    }

};

int main() {
	
	return 0;
}