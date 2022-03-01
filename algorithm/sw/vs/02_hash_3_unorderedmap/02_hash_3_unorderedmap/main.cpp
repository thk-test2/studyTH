#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;

struct Node {
	int key;
	int val;
	Node* next;
};

Node buf[100];
int bufCnt = 0;

Node* bucket[10];

Node* myAlloc(int key, int val, Node* next) {
	buf[bufCnt] = { key, val, next };
	return &buf[bufCnt++];
}

void addNode(int from, int key, int val) {
	for (Node* p = bucket[from]; p != nullptr; p = p->next) {
		if (p->key == key) {
			p->val = val;
			return;
		}
	}
	bucket[from] = myAlloc(key, val, bucket[from]);
}

int hashFunc(unsigned int key) {
	return key % 97;
}

int vect[5] = { 10, 20, 50, -33, -36 };

void insert(int key, int val) {
	int hashCode = hashFunc(key);
	addNode(hashCode, key, val);
}

int getVal(int n) {
	int hashCode = hashFunc(n);
	for (Node* p = bucket[hashCode]; p != nullptr; p = p->next) {
		if (p->key == n)
			return p->val;
	}
	return 0;
}

void init() {
	for (int i = 0; i < 5; i++) {
		//m[vect[i]] = 1;
		insert(vect[i], 1);
	}
}

int main() {
	init();

	int n;
	cin >> n;

	cout << getVal(n) << "\n";
	
	insert(n, 999);
	cout << getVal(n) << "\n";

	////if (m[n] == 1) cout << "O\n";
	//if (m.count(n) > 0) cout << "O\n";
	//else cout << "X\n";

	return 0;
}