#include <iostream>
#include <set>

using namespace std;

constexpr auto SIZE = 500010;
using ull = unsigned long long;

struct Node {
	string name;
	Node* next;
};

Node* bucket[SIZE];
Node Pool[SIZE];
int pSize;

Node* myAlloc(string name, Node* next) {
	Pool[pSize] = { name, next };
	return &Pool[pSize++];
}

ull myhash(string str) {
	ull hash = 5381;
	int c, idx = 0;
	while (c = str[idx]) {
		hash = (((hash << 5) + hash) + c) % SIZE;
		idx++;
	}
	return hash % SIZE;
}

void insert(string name) {
	ull hash = myhash(name);
	bucket[hash] = myAlloc(name, bucket[hash]);
}

bool isExist(string name) {
	ull hash = myhash(name);
	Node* node = bucket[hash];
	for (; node; node = node->next) {
		if (node->name == name) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	string input;
	for (int i = 0; i < N; ++i) {
		cin >> input;
		insert(input);
	}
	set<string> s;
	for (int i = 0; i < M; ++i) {
		cin >> input;
		if (isExist(input)) {
			s.insert(input);
		}
	}
	cout << s.size() << "\n";
	for (auto& itr : s) {
		cout << itr << "\n";
	}
	return 0;
}