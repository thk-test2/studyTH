#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[10];
bool selected[10];
int madeNum[10];
int nCnt = 0;

void combi(int index, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < nCnt; ++i) {
			cout << madeNum[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (selected[i]) continue;
		selected[i] = true;
		madeNum[nCnt++] = arr[i];
		combi(i, cnt + 1);

		selected[i] = false;
		madeNum[nCnt--];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	combi(0, 0);

	return 0;
}