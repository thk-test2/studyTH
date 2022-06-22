#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void search(stack<pair<char, int>>& st, string& text, string& pattern) {
	int textSize = text.size(), patternSize = pattern.size();
	int match_cnt = 0;
	for (int i = 0; i < textSize; ++i) {
		if (text[i] == pattern[match_cnt]) {
			match_cnt++;
		}
		else if (text[i] == pattern[0]) {
			match_cnt = 1;
		}
		else {
			match_cnt = 0;
		}
		st.push({ text[i], match_cnt });

		if (match_cnt == patternSize) {
			for (int k = 0; k < match_cnt; ++k)
				st.pop();
			match_cnt = st.empty() ? 0 : st.top().second;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<pair<char, int>> st;
	string text, pattern;
	cin >> text;
	cin >> pattern;

	search(st, text, pattern);
	if (st.empty()) {
		cout << "FRULA";
		return 0;
	}

	string answer;
	while (!st.empty()) {
		answer += st.top().first;
		st.pop();
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}