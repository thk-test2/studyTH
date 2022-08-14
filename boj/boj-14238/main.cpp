#include <iostream>
#include <cstring>

using namespace std;

int memo[51][51][51][3][3];
int cnt[3];
string S;

int checknode(int a, int b, int c, int p1, int p2) {
	if (a + b + c == S.size()) return 1;
	if (memo[a][b][c][p1][p2] != -1) return memo[a][b][c][p1][p2];

	int ret = 0;
	if (a < cnt[0]) {
		ret = checknode(a + 1, b, c, 0, p1);
		if (ret) {
			cout << "A";
			return ret;
		}
	}
	if (b < cnt[1]) {
		if (p1 != 1) {
			ret = checknode(a, b + 1, c, 1, p1);
			if (ret) {
				cout << "B";
				return ret;
			}
		}
	}
	if (c < cnt[2]) {
		if (p1 != 2 && p2 != 2) {
			ret = checknode(a, b, c + 1, 2, p1);
			if (ret) {
				cout << "C";
				return ret;
			}
		}
	}
	return memo[a][b][c][p1][p2] = ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> S;
	for (int i = 0; i < S.size(); ++i) {
		cnt[S[i] - 'A']++;
	}
	memset(memo, -1, sizeof(memo));
	if (!checknode(0, 0, 0, 0, 0))
		cout << "-1";
	
	return 0;
}