#include <iostream>

using namespace std;

int LCS[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string strA, strB;
	cin >> strA;
	cin >> strB;
	int aSize = strA.size(), bSize = strB.size();
	for (int i = 0; i <= aSize; ++i) {
		for (int j = 0; j <= bSize; ++j) {
			if (i == 0 || j == 0)
				LCS[i][j] = 0;
			else if (strA[i-1] == strB[j-1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
	int i = aSize, j = bSize;
	string str = "";
	while (i != 0 && j != 0) {
		if (LCS[i][j] == LCS[i - 1][j]) {
			i--;
		}
		else if (LCS[i][j] == LCS[i][j - 1]) {
			j--;
		}
		else if (LCS[i][j] == LCS[i - 1][j - 1] + 1) {
			str += strA[i-1];
			i--; j--;
		}
	}
	cout << str.size() << "\n";
	//for (auto itr = str.rbegin(); itr != str.rend(); itr++)
	//	cout << *itr;
	return 0;
}