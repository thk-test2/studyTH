#include <iostream>

using namespace std;

int N, M;
bool selected[10];
int make_num[10];
int nCnt = 1;

void permu(int cnt) {
	if (cnt == M) {
		for (int i = 1; i < nCnt; ++i) {
			cout << make_num[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; ++i) {
		make_num[nCnt++] = i;
		permu(cnt + 1);
		make_num[nCnt--] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	permu(0);

	return 0;
}