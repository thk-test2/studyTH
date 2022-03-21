#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[10];
bool selected[10];

void combi(int index, int cnt, vector<int>& makeNum) {
	if (cnt == M) {
		for (const auto& itr : makeNum) {
			cout << itr << " ";
		}
		cout << "\n";
		return;
	}

	int prev = 0;
	for (int i = 0; i < N; ++i) {
		if (selected[i] || arr[i] == prev) continue;
		selected[i] = true;
		makeNum.push_back(arr[i]);
		prev = arr[i];
		combi(i, cnt + 1, makeNum);

		selected[i] = false;
		makeNum.pop_back();
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
	vector<int> makeNum;
	combi(0, 0, makeNum);
	return 0;
}