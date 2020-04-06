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
        if (t == nullptr) {
            if (partial_sum == sum_)
                result_ = true;
            return;
        }        
        partial_sum += t->val;
        
        scanTree(t->left, partial_sum);
        scanTree(t->right, partial_sum);
    }
private:
    int sum_ = 0;
    bool result_ = false;
};
