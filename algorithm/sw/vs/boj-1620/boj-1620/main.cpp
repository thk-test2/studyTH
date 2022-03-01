#include <iostream>
#include <string>

using namespace std;

constexpr auto MAX_TABLE = 10007;

struct Node {
	string key;
	int val = 0;
	Node* next = nullptr;
};

Node Pool[MAX_TABLE * 10];
int pCnt = 0;
Node* bucket[MAX_TABLE];
string bucket2[100100];

Node* myAlloc(string key, int val, Node* next) {
	Pool[pCnt] = { key, val, next };
	return &Pool[pCnt++];
}

void addNode(int from, string key, int val) {
	bucket[from] = myAlloc(key, val, bucket[from]);
}

int hashFunc(string key) {
	unsigned long hash = 5381;
	for (int i = 0; key[i]; i++)
	{
		hash = (((hash << 5) + hash) + key[i]) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}

void insert(string key, int val) {
	int hashCode = hashFunc(key);
	addNode(hashCode, key, val);
}

int getVal(string key) {
	int hashCode = hashFunc(key);
	
	for (Node* nd = bucket[hashCode]; nd != nullptr; nd = nd->next) {
		if (nd->key == key) {
			return nd->val;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string name;
	for (int i = 1; i <= N; i++) {
		cin >> name;
		insert(name, i);
		bucket2[i] = name;
	}

	string search;
	for (int i = 1; i <= M; i++) {
		cin >> search;
		int temp = getVal(search);
		if (temp != 0) {
			cout << temp << "\n";
		}
		else {
			cout << bucket2[stoi(search)] << "\n";
		}
	}

	return 0;
}