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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;

        int height = 0;
        if (root)
            height = maxHeight(root, 1);
        else
            return answer;
        cout << height;

        for (int i = 0; i < height; ++i) {
            answer.push_back({});
        }
        levelOrder(answer, root, 0);
        return answer;
    }

    int maxHeight(TreeNode* node, int height) {
        int ret = height;
        if (node->left)
            ret = max(ret, maxHeight(node->left, height + 1));
        if (node->right)
            ret = max(ret, maxHeight(node->right, height + 1));
        return ret;
    }

    void levelOrder(vector<vector<int>>& answer, TreeNode* node, int height) {
        answer[height].push_back(node->val);
        if (node->left)
            levelOrder(answer, node->left, height + 1);
        if (node->right)
            levelOrder(answer, node->right, height + 1);
    }
};

int main() {
	
	return 0;
}