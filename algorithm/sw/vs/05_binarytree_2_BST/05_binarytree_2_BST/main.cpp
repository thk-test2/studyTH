#include <iostream>

using namespace std;

constexpr auto SIZE = 1000;

struct Node {
	int val = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

Node Pool[SIZE];
int pSize;

Node* newNode(int key) {
	Node* temp = &Pool[pSize++];
	temp->val = key;
	return temp;
}

Node* insert(Node* node, int key) {
	if (!node) {
		node = newNode(key);
	}
	else {
		if (key < node->val) {
			node->left = insert(node->left, key);
		}
		else {
			node->right = insert(node->right, key);
		}
	}
	return node;
}

Node* minValueNode(Node* node) {
	Node* current = node;

	while (current && current->left)
		current = current->left;

	return current;
}

Node* deleteNode(Node* node, int key) {
	if (!node) return node;

	if (key < node->val)
		node->left = deleteNode(node->left, key);
	else if (key > node->val)
		node->right = deleteNode(node->right, key);
	else { // 삭제할 노드를 찾은 경우
		Node* temp;
		// 노드에 자식이 하나이거나 없는 경우
		if (!node->left) {
			temp = node->right;
			return temp;
		}
		else if (!node->right) {
			temp = node->left;
			return temp;
		}
		// 노드에 자식이 둘 있는 경우
		// Successor 노드를 찾는다. (right subtree의 최소값. 즉 inorder 순회에서 다음 노드)
		temp = minValueNode(node->right);
		node->val = temp->val;
		node->right = deleteNode(node->right, temp->val);
	}
	return node;
}

int search(Node* node, int key) {
	int temp = 0;
	if (key == node->val) {
		temp = key;
	} else if (key < node->val) {
		if (node->left)
			temp = search(node->left, key);
	} else {
		if (node->right)
			temp = search(node->right, key);
	}
	return temp;
}

void inOrder(Node* node) {
	if (!node) return;

	inOrder(node->left);
	cout << node->val << "\n";
	inOrder(node->right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, t;
	cin >> N;

	Node* root = nullptr;
	for (int i = 0; i < N; ++i) {
		cin >> t;
		root = insert(root, t);
	}
	inOrder(root);

	if (search(root, 62) != 0)
		cout << "FOUND" << "\n";
	else 
		cout << "NOT FOUND" << "\n";
	
	deleteNode(root, 50);
	deleteNode(root, 62);

	inOrder(root);
	return 0;
}