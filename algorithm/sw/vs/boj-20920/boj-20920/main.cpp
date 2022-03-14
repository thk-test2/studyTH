#include <iostream>

using namespace std;

constexpr auto MAX_SIZE = 100100;

using ll = long long;

struct Node {
	string word;
	int cnt = 0;
	Node* next = nullptr;
};

struct SortNode {
	string word;
	int cnt = 0;
};

Node Pool[MAX_SIZE];
int pSize = 0;

Node* bucket[MAX_SIZE];

ll usedHash[MAX_SIZE];
int uSize = 0;

SortNode sortingArr[MAX_SIZE];
SortNode b[MAX_SIZE];
int sSize = 0;

Node* myAlloc(string val, Node* next) {
	Pool[pSize] = { val, 1, next};
	return &Pool[pSize++];
}

ll myhash(string val) {
	int hash = 5381;
	for (auto& itr : val) {
		hash = (((hash << 5) + hash) + itr) % MAX_SIZE;
	}
	return hash % MAX_SIZE;
}

void insert(string val) {
	ll hash = myhash(val);

	for (Node* nd = bucket[hash]; nd; nd = nd->next) {
		if (nd->word == val) {
			nd->cnt++;
			return;
		}
	}
	if (!bucket[hash])
		usedHash[uSize++] = hash;
	bucket[hash] = myAlloc(val, bucket[hash]);
}

bool isHigerPriority(SortNode a, SortNode b) {
	if (a.cnt > b.cnt) return true;
	else if (a.cnt == b.cnt) {
		if (a.word.size() > b.word.size()) return true;
		else if (a.word.size() == b.word.size()) {
			return a.word < b.word;
		}
	}
	return false;
}

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (isHigerPriority(sortingArr[i], sortingArr[j]))
			b[k++] = sortingArr[i++];
		else
			b[k++] = sortingArr[j++];
	}
	while (i <= mid) b[k++] = sortingArr[i++];
	while (j <= end) b[k++] = sortingArr[j++];
	for (i = start; i <= end; i++)
		sortingArr[i] = b[i - start];
}

void sort(int start, int end) {
	if (start == end) return;

	int mid = (start + end) / 2;
	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	string temp;
	for (int i = 0; i < N; ++i) {
		cin >> temp;
		if (temp.length() >= M)
			insert(temp);
	}

	for (int i = 0; i < uSize; ++i) {
		ll hash = usedHash[i];
		for (Node* nd = bucket[hash]; nd; nd = nd->next) {
			sortingArr[sSize].cnt = nd->cnt;
			sortingArr[sSize].word = nd->word;
			sSize++;
		}
	}
	sort(0, sSize);
	for (int i = 0; i < sSize; ++i) {
		cout << sortingArr[i].word << "\n";
	}
	return 0;
}