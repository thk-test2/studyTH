#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& A, int t) {
	int start = 0, end = A.size() - 1, mid;
	int cnt = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (A[mid] > t) {
			end = mid - 1;
		}
		else if (A[mid] < t) {
			start = mid + 1;
		}
		else {
			cnt++;
			break;
		}
	}
	return cnt;
}

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
		cout << search(A, t) << " ";
	}
	return 0;
}