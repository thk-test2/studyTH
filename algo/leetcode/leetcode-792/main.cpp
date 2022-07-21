#include <iostream>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> um;
        unordered_map<string, bool> visited;

        for (int i = 0; i < words.size(); ++i) {
            um[words[i]]++; visited[words[i]] = false;
        }

        int cnt = 0;
        for (int i = 0; i < words.size(); ++i) {
            if (visited[words[i]]) continue;
            visited[words[i]] = true;

            int j = 0, k = 0;
            while (k < s.length() && j < words[i].length()) {
                if (s[k] == words[i][j]) j++;
                k++;
            }
            if (j == words[i].length()) {
                cnt += um[words[i]];
            }
        }
        return cnt;
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