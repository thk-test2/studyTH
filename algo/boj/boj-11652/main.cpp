#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
constexpr auto SIZE = 100100;

struct SortNode {
	long long val;
	int cnt;
};

SortNode sortarr[SIZE];
int sSize;

long long usedNum[SIZE];
int uSize;

bool compare(SortNode a, SortNode b) {
	if (a.cnt == b.cnt)
		return a.val < b.val;
	return a.cnt > b.cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	unordered_map<long long, int> um;
	int N;
	long long n;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> n;
		if (um.count(n) == 0) {
			usedNum[uSize++] = n;
		}
		um[n]++;
	}

	for (int k = 0; k < uSize; ++k) {
		sortarr[sSize++] = { usedNum[k], um[usedNum[k]] };
	}

	sort(sortarr, sortarr + sSize, compare);
	cout << sortarr[0].val;
	return 0;
}