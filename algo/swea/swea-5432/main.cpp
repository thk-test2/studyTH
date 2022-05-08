#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		string input;
		cin >> input;

		stack<char> st;
		int cnt = 0;
		int Size = input.size();
		for (int i = 0; i < Size; ++i) {
			if (input[i] == '(') {
				st.push(input[i]);
			}
			else {
				st.pop();
				cnt += (input[i - 1] == '(') ? st.size() : 1;
			}
		}
		cout << "#" << test << " " << cnt << "\n";
	}
	return 0;
}