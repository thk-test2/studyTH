#include <iostream>
#include <cstring>

using namespace std;

int N, M;
bool selected[10];
int make_num[10];
int nCnt = 1;

void combi(int cnt) {
	if (cnt == M) {
		for (int i = 1; i < nCnt; ++i) {
			cout << make_num[i] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; ++i) {
		if (selected[i]) continue;
		selected[i] = true;
		make_num[nCnt++] = i;
		combi(cnt + 1);
		selected[i] = false;
		make_num[nCnt--] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	memset(selected, false, sizeof(selected));
	combi(0);

	return 0;
}