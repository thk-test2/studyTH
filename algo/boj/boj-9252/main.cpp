#include <iostream>
#include <vector>

using namespace std;

int memo[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string A, B;
	cin >> A >> B;
	int aSize = A.size(), bSize = B.size();
	for (int i = 1; i <= aSize; ++i) {
		for (int j = 1; j <= bSize; ++j) {
			if (A[i-1] == B[j-1])
				memo[i][j] = memo[i - 1][j - 1] + 1;
			else if (A[i-1] != B[j-1])
				memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
		}
	}
	vector<char> answer;
	int y = aSize, x = bSize;
	int val = memo[aSize][bSize];
	while (!(y == 0 || x == 0)) {
		if (val == memo[y - 1][x]) {
			y = y - 1;
		}
		else if (val == memo[y][x - 1]) {
			x = x - 1;
		}
		else {
			answer.push_back(A[y-1]);
			y = y - 1, x = x - 1;
		}
		val = memo[y][x];
	}
	cout << answer.size() << "\n";
	if (!answer.empty()) {
		for (auto itr = answer.rbegin(); itr != answer.rend(); ++itr)
			cout << *itr;
	}
	return 0;
}