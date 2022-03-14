#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	string temp;
	temp += pattern[0];
	int j = 0;
	for (int i = 1; i < patternSize; ++i) {
		temp += pattern[i];
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void kmp(string original, string pattern) {
	vector<int> table = makeTable(pattern);
	int originalSize = original.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < originalSize; i++) {
		while (j > 0 && original[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (original[i] == pattern[j]) {
			if (j == patternSize - 1) {
				cout << i - patternSize + 2 << " matched.\n";
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string original = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	kmp(original, pattern);

	return 0;
}