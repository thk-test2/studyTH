#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> um;

        int sSize = s.size();
        for (int i = 0; i < sSize; ++i) {
            um[s[i]]++;
        }

        bool success = true;
        int tSize = t.size();
        for (int i = 0; i < tSize; ++i) {
            if (um.find(t[i]) != um.end() && um[t[i]] > 0) {
                um[t[i]]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}