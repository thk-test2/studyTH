#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		string text, pattern;
		cin >> text >> pattern;

		int textSize = text.size();
		int patternSize = pattern.size();
		int i = 0, patternCnt = 0;

		while (i < textSize) {
			if (text[i] == pattern[0]) {
				if (text.substr(i, patternSize) == pattern) {
					patternCnt++;
					i += patternSize;
					continue;
				}
			}
			patternCnt++;
			i++;
		}
		cout << "#" << test << " " << patternCnt << "\n";
	}
	return 0;
}