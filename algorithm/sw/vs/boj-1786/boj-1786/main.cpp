#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeTable(const string& pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < pattern.size(); ++i) {
		while (pattern[i] != pattern[j] && j > 0) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

vector<int> kmp(const string& text, const string& pattern) {
	vector<int> table = makeTable(pattern);
	vector<int> result;

	int textSize = text.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < text.size(); ++i) {
		while (text[i] != pattern[j] && j > 0) {
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
	
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);

	vector<int> result = kmp(text, pattern);
	cout << result.size() << "\n";
	for (const auto& itr : result) {
		cout << itr << " ";
	}
	return 0;
}