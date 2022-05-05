#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(begin(A), end(A));
	int M;
	cin >> M;

	int t;
	for (int i = 0; i < M; ++i) {
		cin >> t;
		auto lower = lower_bound(A.begin(), A.end(), t);
		auto upper = upper_bound(A.begin(), A.end(), t);
		cout << upper - lower << " ";
	}
	return 0;
}