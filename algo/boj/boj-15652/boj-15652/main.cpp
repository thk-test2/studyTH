#include <iostream>

using namespace std;

int N, M;
bool selected[10];
int make_num[10];
int nCnt = 1;

void combi(int index, int cnt) {
	if (cnt == M) {
		for (int i = 1; i < nCnt; ++i) {
			cout << make_num[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i <= N; ++i) {
		make_num[nCnt++] = i;
		combi(i, cnt + 1);
		make_num[nCnt--] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	combi(1, 0);

	return 0;
}