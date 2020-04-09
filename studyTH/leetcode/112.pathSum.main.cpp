/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;
        
        sum_ = sum;
        scanTree(root, 0);
        
        return result_;
    }
    
    void scanTree(TreeNode* t, int partial_sum) {
        
        partial_sum += t->val;
        if (partial_sum == sum_ && (t->left == nullptr && t->right == nullptr))
            result_ = true;
        
        if (t->left)
            scanTree(t->left, partial_sum);
        if (t->right)
            scanTree(t->right, partial_sum);
    }
private:
    int sum_ = 0;
    bool result_ = false;
};
