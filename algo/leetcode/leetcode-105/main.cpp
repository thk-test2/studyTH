#include <iostream>
#include <vector>

using namespace std;

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
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         TreeNode* ret = construct(preorder, inorder, 0, preorder.size(), 0, inorder.size());
         return ret;
     }

     TreeNode* construct(vector<int>& preorder, vector<int>& inorder,
         int pstart, int pend, int istart, int iend) {
         TreeNode* node = nullptr;
         if (pstart == pend) return node;

         auto itr = find(inorder.begin() + istart, inorder.begin() + iend, preorder[pstart]);
         if (itr != inorder.end()) {
             node = new TreeNode(*itr);
             if (itr != inorder.begin() + istart) {
                 int len = distance(inorder.begin() + istart, itr);
                 node->left = construct(preorder, inorder, pstart + 1, pstart + len + 1, istart, istart + len);

                 node->right = construct(preorder, inorder, pstart + 1 + len, pend, istart + 1 + len, iend);
             }
             else {
                 node->right = construct(preorder, inorder, pstart + 1, pend, istart + 1, iend);
             }
         }
         return node;
     }
 };

int main() {
    Solution s;
    vector<int> pre{ 3,9,20,15,7 };
    vector<int> in{ 9,3,15,20,7 };
    //vector<int> pre{ 1, 2 };
    //vector<int> in{ 2, 1 };
    //vector<int> pre{ 1, 2 };
    //vector<int> in{ 1, 2 };
    TreeNode* root = s.buildTree(pre, in);
	
	return 0;
}