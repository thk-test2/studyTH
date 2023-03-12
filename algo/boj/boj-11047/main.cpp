#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> A;

	int a;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		A.push_back(a);
	}
	int cnt = 0;
	while (K) {
		int maximum = *(upper_bound(A.begin(), A.end(), K) - 1);
		cnt += K / maximum;
		K -= K/maximum * maximum;
	}
	cout << cnt;
	return 0;
}