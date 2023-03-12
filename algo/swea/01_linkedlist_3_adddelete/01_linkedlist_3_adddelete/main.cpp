#include <iostream>

using namespace std;

struct Node {
	int x;
	Node* next;
};

Node Pool[1000000];
int pcnt = 0;

Node* Head = nullptr;
Node* Last = nullptr;

Node* myAlloc(int x, Node* next) {
	Pool[pcnt] = { x, next };
	return &Pool[pcnt++];
}

void addNode(int x) {
	if (Head == nullptr) {
		Head = myAlloc(x, nullptr); // &Pool[pcnt++];
		Last = Head;
		return;
	}
	Last->next = myAlloc(x, nullptr); // &Pool[pcnt++];
	Last = Last->next;
}

void addNode_2(int x) {
	Head = myAlloc(x, Head);
}

bool deleteNode(int target) {
	// 0. target이 맨 앞에 있는 경우
	if (Head == nullptr) return false;
	if (Head->x == target) {
		Head = Head->next;
		return true;
	}

	// 1. target 이전 노드 찾기
	Node* nd;
	for (nd = Head; nd != nullptr; nd = nd->next) {
		if (nd->next == nullptr) return false;
		if (nd->next->x == target) break;
	}
	// 2. target 노드 삭제
	nd->next = nd->next->next;
	return true;
}

bool insertNode(int neighbor, int newValue) {
	// 1. neighbor(넣어야 할 위치) 찾기
	Node* nd;
	for (nd = Head; nd != nullptr; nd = nd->next) {
		if (nd->x == neighbor) break;
	}
	if (nd == nullptr) return false;

	// 2. neighbor 옆에 넣기
	nd->next = myAlloc(newValue, nd->next);
	return true;
}

int main() {
	addNode_2(1);
	addNode_2(2);
	addNode_2(3);
	addNode_2(4);
	addNode_2(5);
	addNode_2(6);
	addNode_2(7);

	//cout << deleteNode(7) << "\n";
	//cout << deleteNode(3) << "\n";
	//cout << deleteNode(-1) << "\n";
	//cout << deleteNode(1) << "\n";

	for (Node* nd = Head; nd != nullptr; nd = nd->next) {
		cout << nd->x << " ";
	}
	cout << "\n";

	cout << insertNode(7, 999) << "\n";
	cout << insertNode(1, 555) << "\n";
	cout << insertNode(-10, 123) << "\n";

	for (Node* nd = Head; nd != nullptr; nd = nd->next) {
		cout << nd->x << " ";
	}

	return 0;
}