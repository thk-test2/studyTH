#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; ++i) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string text;
	while (true) {
		cin >> text;
		if (text == ".") break;

		vector<int> table = makeTable(text);
		int textSize = text.size();
		int patternSize = table[textSize - 1];
		if (textSize % (textSize - patternSize)) {
			cout << "1\n";
		}
		else {
			cout << textSize / (textSize - patternSize) << "\n";
		}
	}
	return 0;
}