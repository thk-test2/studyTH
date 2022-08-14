#include <iostream>

using namespace std;

constexpr auto SIZE = 100001;

int arr[SIZE];
int minTree[SIZE * 4];
int maxTree[SIZE * 4];

int makeMinTree(int idx, int start, int end) {
	if (start == end) return minTree[idx] = arr[start];
	int mid = (start + end) / 2;
	int leftVal = makeMinTree(idx * 2, start, mid);
	int rightVal = makeMinTree(idx * 2 + 1, mid + 1, end);
	return minTree[idx] = min(leftVal, rightVal);
}

int makeMaxTree(int idx, int start, int end) {
	if (start == end) return maxTree[idx] = arr[start];
	int mid = (start + end) / 2;
	int leftVal = makeMaxTree(idx * 2, start, mid);
	int rightVal = makeMaxTree(idx * 2 + 1, mid + 1, end);
	return maxTree[idx] = max(leftVal, rightVal);
}

int getMinVal(int idx, int start, int end, int left, int right) {
	if (start > right || end < left) return 1000000001;
	if (start >= left && end <= right) return minTree[idx];
	
	int mid = (start + end) / 2;
	int leftVal = getMinVal(idx * 2, start, mid, left, right);
	int rightVal = getMinVal(idx * 2 + 1, mid + 1, end, left, right);
	return min(leftVal, rightVal);
}

int getMaxVal(int idx, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return maxTree[idx];

	int mid = (start + end) / 2;
	int leftVal = getMaxVal(idx * 2, start, mid, left, right);
	int rightVal = getMaxVal(idx * 2 + 1, mid + 1, end, left, right);
	return max(leftVal, rightVal);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}
	makeMinTree(1, 1, N);
	makeMaxTree(1, 1, N);

	int a, b;
	for (int i = 1; i <= M; ++i) {
		cin >> a >> b;
		cout << getMinVal(1, 1, N, a, b) << " ";
		cout << getMaxVal(1, 1, N, a, b) << "\n";
	}
	return 0;
}