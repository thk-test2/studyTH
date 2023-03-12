#include <iostream>

using namespace std;

int vect[5] = { 1, 34, 65, 25, 77 };
string strs[4] = { "ABCD", "QWE", "XCVXA", "asdffefdfa" };

struct Node {
	//int x;
	string str;
	Node* next;
};

Node buf[100];
int bufCnt;

Node* head[10];

//Node* myAlloc(int x, Node* next) {
//	buf[bufCnt] = { x, next };
//	return &buf[bufCnt++];
//}
//
//void addNode(int from, int x) {
//	head[from] = myAlloc(x, head[from]);
//}
//
//// unsigned로 받으면 음수 처리 가능
//int hashFunc(unsigned int key) {
//	return key % 10;
//}
//
//void init() {
//	for (int i = 0; i < 5; i++) {
//		int hashCode = hashFunc(vect[i]);
//		addNode(hashCode, vect[i]);
//	}
//}

Node* myAlloc_2(string x, Node* next) {
	buf[bufCnt] = { x, next };
	return &buf[bufCnt++];
}

void addNode_2(int from, string x) {
	head[from] = myAlloc_2(x, head[from]);
}

int hashFunc_2(string key) {
	unsigned int sum = 1;
	for (int i = 0; i < key.length(); i++) {
		sum *= key[i] + 32;
	}
	return sum % 3;
}

void init_2() {
	for (int i = 0; i < 4; i++) {
		int hashCode = hashFunc_2(strs[i]);
		addNode_2(hashCode, strs[i]);
	}
}

int main() {
	init_2();

	string str;
	cin >> str;

	int code = hashFunc_2(str);
	for (Node* p = head[code]; p != nullptr; p = p->next) {
		if (p->str == str) {
			cout << "O\n";
			return 0;
		}
	}
	cout << "X\n";

	/*init();

	int n;
	cin >> n;

	int code = hashFunc(n);
	for (Node* p = head[code]; p != nullptr; p = p->next) {
		if (p->x == n) {
			cout << "O\n";
			return 0;
		}
	}
	cout << "X\n";*/

	return 0;
}