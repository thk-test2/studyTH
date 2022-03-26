#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	int j = 0;
	vector<int> table(patternSize, 0);
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

vector<int> kmp(string text, string pattern) {
	vector<int> result;
	vector<int> table = makeTable(pattern);
	int textSize = text.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < textSize; ++i) {
		while (j > 0 && text[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == patternSize - 1) {
				result.push_back(i - patternSize + 2);
				j = table[j];
			}
			else {
				++j;
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L;
	string str;
	cin >> L;
	cin >> str;

	vector<int> table = makeTable(str);
	cout << table.size() - table.back();
	return 0;
}