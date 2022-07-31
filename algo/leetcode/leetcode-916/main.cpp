#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isExist(unordered_map<char, int>& um, unordered_map<char, int>& um2) {
        for (auto& tmp : um2) {
            // cout << tmp.first << ", " << tmp.second << ", " << um.count(tmp.first) << "\n";
            if (um.count(tmp.first)) {
                if (um[tmp.first] < tmp.second)
                    return false;
            }
            else {
                return false;
            }
        }
        return true;
    }

    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int N = words1.size(), M = words2.size();

        unordered_map<char, int> um[N];
        for (int i = 0; i < N; ++i) {
            for (auto& c : words1[i])
                um[i][c]++;
        }

        set<string> ms2;
        for (int i = 0; i < M; ++i) {
            ms2.insert(words2[i]);
        }

        unordered_map<char, int> um2;
        for (auto& s : ms2) {
            int sSize = s.size();

            vector<int> cnts(26, 0);
            for (int i = 0; i < sSize; ++i) {
                cnts[s[i] - 'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                if (cnts[i] == 0) continue;
                um2[i + 'a'] = max(um2[i + 'a'], cnts[i]);
            }
        }

        vector<string> ans;
        int um2Size = um2.size();
        for (int i = 0; i < N; ++i) {
            if (isExist(um[i], um2)) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}