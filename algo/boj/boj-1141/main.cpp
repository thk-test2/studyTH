#include <iostream>

using namespace std;

struct Node {
	char val = 0;
	Node* alpha[26] = { nullptr };
};

void makeTrie(Node* node, string str, int idx) {
	if (!node->alpha[str[idx] - 'a']) {
		node->alpha[str[idx] - 'a'] = new Node{ str[idx] };
	}
	if (idx == str.size() - 1)
		return;
	makeTrie(node->alpha[str[idx] - 'a'], str, idx + 1);
}

int getCnt(int max_cnt, Node* node) {
	bool found = false;
	for (int i = 0; i < 26; ++i) {
		if (!node->alpha[i]) continue;
		found = true;
		max_cnt = getCnt(max_cnt, node->alpha[i]);
	}
	if (!found)
		max_cnt++;
	return max_cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Node root;
	int N;
	string str;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		makeTrie(&root, str, 0);
	}
	cout << getCnt(0, &root);
	return 0;
}