#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[21][21];
bool selected[21];
int N, minimum;

void checknode(int index, int cnt) {
	if (cnt == N / 2) {
		vector<int> start, link;
		for (int i = 1; i <= N; ++i) {
			selected[i] ? start.push_back(i) : link.push_back(i);
		}
		int startSum = 0, linkSum = 0;
		for (int i = 0; i < N / 2; ++i) {
			for (int j = 0; j < N / 2; ++j) {
				if (i == j) continue;
				startSum += arr[start[i]][start[j]];
				linkSum += arr[link[i]][link[j]];
			}
		}
		minimum = min(minimum, abs(startSum - linkSum));
		return;
	}
	for (int i = index + 1; i <= N; ++i) {
		if (selected[i]) continue;
		selected[i] = true;
		checknode(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> arr[i][j];
		}
	}
	minimum = 987654321;
	checknode(1, 0);
	cout << minimum;
	return 0;
}