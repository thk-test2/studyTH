#include <iostream>
#include <cstring>

using namespace std;

using ull = unsigned long long;
constexpr auto SIZE = 200001;

struct Node {
	char* str;
	Node* next;
};

Node Pool[SIZE * 5];
int pSize;
Node* bucket[SIZE];

ull wei[SIZE];
char text[SIZE];
int N;

Node* myAlloc(char* str, Node* next) {
	Pool[pSize] = { str, next };
	return &Pool[pSize++];
}

bool strncmp(char* a, char* b, int len) {
	for (int i = 0; i < len; ++i) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

bool check(int length) {
	ull hash = 0;
	pSize = 0;
	memset(bucket, false, sizeof(bucket));

	for (int i = 0; i < N; ++i) {
		hash = hash * 31 + text[i];
		if (i < length - 1) continue;
		
		hash = hash - wei[length - 1] * text[i - length + 1];
		int hidx = hash % SIZE;
		if (bucket[hidx]) {
			for (Node* node = bucket[hidx]; node; node = node->next) {
				if (strncmp(node->str, &text[i - length + 1], length))
					return true;
			}
		}
		bucket[hidx] = myAlloc(&text[i - length + 1], bucket[hidx]);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> text;

	wei[0] = 1;
	for (int i = 1; i <= N; ++i) {
		wei[i] = wei[i - 1] * 31;
	}

	int start = 0, end = N - 1;
	int answer = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (check(mid)) {
			answer = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << answer;
	return 0;
}