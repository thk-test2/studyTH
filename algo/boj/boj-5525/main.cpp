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

int kmp(string text, string pattern) {
	vector<int> table = makeTable(pattern);
	int textSize = text.size(), patternSize = pattern.size();
	int j = 0;

	int cnt = 0;
	for (int i = 0; i < textSize; ++i) {
		while (j > 0 && text[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == patternSize - 1) {
				cnt++;
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string text, pattern("I");
	int N, M;
	cin >> N;
	cin >> M;
	cin >> text;

	for (int i = 0; i < N; ++i) {
		pattern += "OI";
	}
	
	cout << kmp(text, pattern);
	return 0;
}