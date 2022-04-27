#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string str) {
		int ans = 0;
		int start = 0, end = 0;
		unordered_map<char, int> um;
		int num = 0;

		while (start <= end && end < str.size()) {
			if (um.count(str[end]) == 0) {
				num++;
				um[str[end]] = 1;
				end++;
			}
			else {
				num--;
				um.erase(str[start]);
				start++;
			}
			ans = max(ans, num);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	cin.ignore();
	for (int test = 1; test <= T; ++test) {
		string str;
		getline(cin, str);
		Solution s;
		cout << s.lengthOfLongestSubstring(str) << "\n";
	}
	return 0;
}