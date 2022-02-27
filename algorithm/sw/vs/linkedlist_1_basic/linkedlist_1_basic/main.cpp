#include <iostream>

using namespace std;

struct Node {
	int x;
	Node* next;
};

Node* head = nullptr;
Node* last = nullptr;

void addNode(int t) {
	if (head == nullptr) {
		head = new Node();
		head->x = t;
		head->next = nullptr;
		last = head;
		return;
	}

	last->next = new Node();
	last->next->x = t;
	last->next->next = nullptr;
	last = last->next;
}

int main() {
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);

	Node* p = head;
	while (p != nullptr) {
		printf("%d ", p->x);
		p = p->next;
	}

	Node* old;
	while (head != nullptr) {
		old = head;
		head = head->next;
		delete old;
	}

	return 0;
}