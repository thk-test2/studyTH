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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        scan_p(p);
        scan_q(q);
        
        if (p_vec.size() != q_vec.size())
            return false;
        
        auto p_itr = p_vec.begin();
        auto q_itr = q_vec.begin();
        while(p_itr != p_vec.end() && q_itr != q_vec.end()) {
            if (*p_itr != *q_itr) {
                return false;
            }
            p_itr++;
            q_itr++;
        }
        return true;
    }
    void scan_p(TreeNode* p) {
        if (p == nullptr) {
            p_vec.push_back(-1);
            return;
        }

        //cout << "p:"<< p->val << endl;
        p_vec.push_back(p->val);   

        scan_p(p->left);
        scan_p(p->right);
    }
    void scan_q(TreeNode* q) {
        if (q == nullptr) {
            q_vec.push_back(-1);
            return;
        }

        //cout << "q:"<< q->val << endl;
        q_vec.push_back(q->val);   

        scan_q(q->left);
        scan_q(q->right);
    }
private:
    vector<int> p_vec;
    vector<int> q_vec;
};
