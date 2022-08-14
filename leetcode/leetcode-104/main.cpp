#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;

		preorder(root, 1);
		return answer;
	}
	void preorder(TreeNode* node, int level) {
		if (node->left) {
			preorder(node->left, level + 1);
		}
		if (node->right) {
			preorder(node->right, level + 1);
		}
		answer = max(answer, level);
	}
	int answer = 0;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {

	}
	return 0;
}