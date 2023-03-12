#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        int n = strs.size();
        unordered_map<string, int> um;
        for (int i = 0; i < n; ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());

            if (um.find(str) != um.end()) {
                int val = um[str];
                answer[val].push_back(strs[i]);
            }
            else {
                vector<string> temp;
                temp.push_back(strs[i]);
                answer.push_back(temp);
                um[str] = answer.size() - 1;
            }
        }

        return answer;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {

		cout << "#" << test << "\n";
	}

	return 0;
}