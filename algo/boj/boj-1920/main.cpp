#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binarySearch(vector<int>& A, int N, int n) {
	int start = 0, end = N - 1, mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (A[mid] < n) {
			start = mid + 1;
		}
		else if (A[mid] > n) {
			end = mid - 1;
		}
		else break;
	}
	return start <= end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int> A(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(begin(A), end(A));

	cin >> M;
	int n;
	for (int i = 0; i < M; ++i) {
		cin >> n;
		cout << binarySearch(A, N, n) << "\n";
	}
	return 0;
}