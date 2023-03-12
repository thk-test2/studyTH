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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0, end = nums.size();
        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeBST(start, mid, nums);
        root->right = makeBST(mid + 1, end, nums);
        return root;
    }

    TreeNode* makeBST(int start, int end, vector<int>& nums) {
        TreeNode* node = nullptr;

        if (start < end) {
            int mid = (start + end) / 2;
            node = new TreeNode(nums[mid]);
            node->left = makeBST(start, mid, nums);
            node->right = makeBST(mid + 1, end, nums);
        }

        return node;
    }
};

int main() {
	
	return 0;
}