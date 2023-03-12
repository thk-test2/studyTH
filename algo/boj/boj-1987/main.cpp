#include <iostream>

using namespace std;

char arr[21][21];
bool visited[21][21];
bool alpha[26];
int R, C;

int dirI[] = { -1, 1, 0, 0 };
int dirJ[] = { 0, 0, -1, 1 };
int maximum = 0;

void travel(int i, int j, int cnt) {
	for (int k = 0; k < 4; ++k) {
		int nI = i + dirI[k], nJ = j + dirJ[k];
		if (nI < 0 || nI >= R || nJ < 0 || nJ >= C) continue;
		if (visited[nI][nJ] || alpha[arr[nI][nJ] - 'A']) continue;
		visited[nI][nJ] = true;
		alpha[arr[nI][nJ] - 'A'] = true;
		travel(nI, nJ, cnt + 1);
		visited[nI][nJ] = false;
		alpha[arr[nI][nJ] - 'A'] = false;
	}
	if (maximum < cnt)
		maximum = cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	string str;
	for (int i = 0; i < R; ++i) {
		cin >> str;
		for (int j = 0; j < C; ++j) {
			arr[i][j] = str[j];
		}
	}
	visited[0][0] = true;
	alpha[arr[0][0] - 'A'] = true;
	travel(0, 0, 1);
	cout << maximum;
	return 0;
}