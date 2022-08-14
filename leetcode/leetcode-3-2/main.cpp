#include <iostream>
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
			//if (um.count(str[end]) == 0) {
			if (um[str[end]] == 0) {
				num++;
				um[str[end]] = 1;
				end++;
			}
			else {
				num--;
				um[str[start]] = 0;
				//um.erase(str[start]);
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
    string str;
    Solution s;
	for (int test = 1; test <= T; ++test) {
        cin >> str;
        int ret = s.lengthOfLongestSubstring(str);
		cout << "#" << test << ", " << ret << "\n";
	}

	unordered_map<char, int> test;
	
	//cout << test.count(1) << "\n";
	test[1]++;
	//cout << test.count(1) << ", " << test[1] << "\n";
	test[1]--;
	//cout << test.count(1) << ", " << test[1] << "\n";
	test.erase(1);
	cout << test.count(1) << "\n";
	cout << test.count(1) << ", " << test[1] << "\n";

	return 0;
}