#include <iostream>

using namespace std;

bool selected[10];
int N, M;

void combi(int index, int cnt) {
	if (cnt == M) {
		for (int i = 1; i <= N; ++i) {
			if (selected[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	for (int i = index; i <= N; ++i) {
		if (selected[i]) continue;
		selected[i] = true;
		combi(i, cnt + 1);
		selected[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	combi(1, 0);

	return 0;
}