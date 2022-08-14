#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, K;
	string str;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> K;
		cin >> str;
		set<string> s;

		for (int i = 0; i < str.size(); ++i) {
			string temp = { str[i] };
			s.insert(temp);
			for (int j = i + 1; j < str.size(); ++j) {
				temp += str[j];
				s.insert(temp);
			}
		}
		int idx = 0; string answer;
		for (auto& itr : s) {
			idx++;
			if (idx == K) {
				answer = itr;
				break;
			}
		}
		cout << "#" << test << " " << answer << "\n";
	}
	return 0;
}