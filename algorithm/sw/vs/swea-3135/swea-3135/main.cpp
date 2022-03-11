#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 1500000;

struct Node {
	int cnt = 0;
	Node* chars[26];
};

Node Pool[MAX_SIZE];
int pSize = 0;

Node* Head = nullptr;

void init(void) {
	Head = nullptr;
}

//void makeTrie(Node* node, int index, int size, char* buf) {
//	if (index == size) return;
//
//	if (!node->chars[buf[index] - 'a']) {
//		node->chars[buf[index] - 'a'] = &Pool[pSize++];
//	}
//	node->chars[buf[index] - 'a']->cnt++;
//	makeTrie(node->chars[buf[index] - 'a'], index + 1, size, buf);
//}

void makeTrie(Node* node, char* buf) {
	if (*buf == NULL) return;

	if (!node->chars[*buf - 'a']) {
		node->chars[*buf - 'a'] = &Pool[pSize++];
	}
	node->chars[*buf - 'a']->cnt++;
	makeTrie(node->chars[*buf - 'a'], buf + 1);
}

void insert(int buffer_size, char* buf) {
	if (!Head) {
		Head = &Pool[pSize++];
	}
	makeTrie(Head, buf);
}

//int searchTrie(Node* node, int index, int size, char* buf) {
//	if (!node) return 0;
//	if (index == size - 1) return node->cnt;
//
//	return searchTrie(node->chars[buf[index + 1] - 'a'], index + 1, size, buf);
//}

int searchTrie(Node* node, char* buf) {
	if (!node) return 0;
	if (*buf == NULL) return node->cnt;

	return searchTrie(node->chars[*buf - 'a'], buf + 1);
}

int query(int buffer_size, char* buf) {
	if (!Head) return 0;
	return searchTrie(Head, buf);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, N;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> N;
		init();
		int cmd;

		cout << "#" << test;
		for (int i = 0; i < N; ++i) {
			cin >> cmd;
			char buf[15] = { 0, };
			if (cmd == 1) {
				cin >> buf;

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				insert(buffer_size, buf);
			}
			else {
				cin >> buf;

				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;
				
				cout << " " << query(buffer_size, buf);
			}
		}
		cout << "\n";
	}
	return 0;
}