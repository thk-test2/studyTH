#include <iostream>
#include <algorithm>

using namespace std;

using ull = unsigned long long;
constexpr auto SIZE = 100001;

struct HashNode {
	string str;
	int cnt = 0;
	HashNode* next = nullptr;
};

struct SortNode {
	string str;
	int cnt;
};

HashNode Pool[SIZE * 5];
int pSize;
HashNode* bucket[SIZE];
ull usedHash[SIZE];
int uSize;

SortNode SortArr[SIZE];
int sSize;
int N, M;

HashNode* myAlloc(string str, int cnt, HashNode* next) {
	Pool[pSize] = { str, cnt, next };
	return &Pool[pSize++];
}

bool Compare(SortNode a, SortNode b) {
	if (a.cnt == b.cnt) {
		if (a.str.length() == b.str.length()) {
			return a.str < b.str;
		}
		return a.str.length() > b.str.length();
	}
	return a.cnt > b.cnt;
}

ull myhash(string str) {
	ull hash = 5381;
	int c, index = 0;
	while (c = str[index++]) {
		hash = (((hash << 5) + hash) + c) % SIZE;
	}
	return hash % SIZE;
}

void insert(string str) {
	ull hash = myhash(str);

	HashNode* node = bucket[hash];
	for (; node; node = node->next) {
		if (node->str == str) {
			node->cnt++;
			return;
		}
	}
	if (!bucket[hash])
		usedHash[uSize++] = hash;
	bucket[hash] = myAlloc(str, 1, bucket[hash]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string str;
	for (int i = 0; i < N; ++i) {
		cin >> str;
		if (str.length() < M) continue;
		insert(str);
	}

	for (int i = 0; i < uSize; ++i) {
		ull hash = usedHash[i];
		HashNode* node = bucket[hash];
		for (; node; node = node->next) {
			SortArr[sSize].str = node->str;
			SortArr[sSize++].cnt = node->cnt;
		}
	}
	sort(SortArr, SortArr + sSize, Compare);
	for (int i = 0; i < sSize; ++i)
		cout << SortArr[i].str << "\n";
	return 0;
}