#include <iostream>
#include <cstring>

using namespace std;

using ull = unsigned long long;

constexpr auto LM = 200010;
constexpr auto SIZE = 1 << 16;

int L;
ull h, wei[LM] = { 1 };
char str[LM];

struct Node {
	char* key;
	Node* next;
};

Node Pool[LM];
int pSize = 0;
Node* bucket[SIZE];

Node* myAlloc(char* key, Node* next) {
	Pool[pSize] = { key, next };
	return &Pool[pSize++];
}

void init() {
	pSize = 0;
	h = 0;
	memset(bucket, false, sizeof(bucket));
}

bool strncmp(char* a, char* b, int len) {
	int i = 0;
	while (i < len) {
		if (a[i] != b[i]) return false;
		++i;
	}
	return true;
}

bool check(int mid) {
	init();
	for (int i = 0; i < L; ++i) {
		h = h * 31 + str[i];
		if (i >= mid - 1) {
			h -= wei[mid - 1] * str[i - mid + 1];
			int hidx = h % SIZE;
			Node* p = bucket[hidx];
			for (; p; p = p->next) {
				if (strncmp(p->key, &str[i - mid + 1], mid))
					return true;
			}
			bucket[hidx] = myAlloc(&str[i - mid + 1], bucket[hidx]);
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> L;
		cin >> str;
		
		init();
		for (int i = 1; i <= L; ++i) {
			wei[i] = wei[i - 1] * 31;
		}

		int low = 0, high = L - 1, ans = 0;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (check(mid)) {
				ans = mid;
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		cout << "#" << test << " " << ans << "\n";
	}
	return 0;
}