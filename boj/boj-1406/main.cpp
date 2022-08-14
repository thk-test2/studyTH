#include <iostream>

// 48 ms

using namespace std;

struct Node {
	char val;
	Node* prev;
	Node* next;
};
Node* head;
Node* cur;

Node Pool[500100 * 2];
int pSize;

Node* myAlloc(char val, Node* prev, Node* next) {
	Pool[pSize] = { val, prev, next };
	return &Pool[pSize++];
}

void addLeft(char val) {
	if (!head) {
		if (!cur)
			cur = myAlloc('\0', nullptr, nullptr);
		head = myAlloc(val, nullptr, cur);
		cur->prev = head;
		return;
	}
	Node* temp = myAlloc(val, cur->prev, cur);
	if (cur->prev) {
		cur->prev->next = temp;
		cur->prev = temp;
	}
	else {
		cur->prev = temp;
		head = cur->prev;
	}
}

void deleteLeft() {
	if (!cur->prev) return;

	if (cur->prev) {
		if (cur->prev->prev) {
			cur->prev->prev->next = cur;
			cur->prev = cur->prev->prev;
		}
		else {
			//cur->prev->next = nullptr;
			cur->prev = nullptr;
			head = cur->next;
		}
	}
}

void moveLeft() {
	if (!cur->prev) return;
	
	if (cur->prev) {
		cur->prev->next = cur->next;
		if (cur->next)
			cur->next->prev = cur->prev;

		if (cur->prev->prev) {
			cur->prev->prev->next = cur;
			cur->next = cur->prev;

			cur->prev = cur->prev->prev;
			cur->next->prev = cur;
		}
		else {
			cur->next = cur->prev;
			cur->prev = nullptr;
			cur->next->prev = cur;
		}
	}
}

void moveRight() {
	if (!cur->next) return;

	if (cur->next) {
		if (cur->prev)
			cur->prev->next = cur->next;
		cur->next->prev = cur->prev;

		if (cur->next->next) {
			cur->next->next->prev = cur;
			cur->prev = cur->next;

			cur->next = cur->next->next;
			cur->prev->next = cur;
		}
		else {
			cur->prev = cur->next;
			cur->next = nullptr;
			cur->prev->next = cur;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str;
	int M;
	cin >> str;
	for (auto& itr : str) {
		addLeft(itr);
	}

	cin >> M;
	char cmd, val;
	for (int i = 0; i < M; ++i) {
		cin >> cmd;
		if (cmd == 'L') {
			moveLeft();
		}
		else if (cmd == 'D') {
			moveRight();
		}
		else if (cmd == 'B') {
			deleteLeft();
		}
		else if (cmd == 'P') {
			cin >> val;
			addLeft(val);
		}
	}
	while (head) {
		if (head->val)
			cout << head->val;
		head = head->next;
	}
	return 0;
}