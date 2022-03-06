#include <iostream>

using namespace std;

constexpr auto SIZE = 10010;

struct Node {
	int val = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node Pool[SIZE];
int pSize;

Node* newNode(int key) {
	Node* tmp = &Pool[pSize++];
	tmp->val = key;
	return tmp;
}

Node* findTarget(Node* node, int target) {
	if (!node) return nullptr;

	if (node->val == target) {
		return node;
	}
	else {
		Node* tempLeft = findTarget(node->left, target);
		if (!tempLeft) {
			Node* tempRight = findTarget(node->right, target);
			return tempRight;
		}
		else {
			return tempLeft;
		}
	}
	return node;
}

void preOrder(Node* node) {
	if (!node) return;

	cout << node->val << " ";
	preOrder(node->left);
	preOrder(node->right);
}

Node* insert(Node* node, int target, int childVal) {
	if (!node) {
		node = newNode(target);
		node->left = newNode(childVal);
	}
	else {
		if (node->val == target) {
			if (!node->left) {
				node->left = newNode(childVal);
			}
			else if (!node->right) {
				node->right = newNode(childVal);
			}
		}
		else {
			Node* temp = findTarget(node->left, target);
			if (temp) {
				insert(temp, target, childVal);
			}
			else {
				temp = findTarget(node->right, target);
				insert(temp, target, childVal);
			}
		}
	}
	return node;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T, N, E;
	cin >> T;

	for (int test = 1; test <= T; ++test) {
		cin >> N >> E;
		int p, c;

		Node* root = nullptr;
		for (int i = 0; i < E; ++i) {
			cin >> p >> c;
			root = insert(root, p, c);
		}

		cout << "#" << test << " ";
		preOrder(root);
		cout << "\n";
	}
	return 0;
}