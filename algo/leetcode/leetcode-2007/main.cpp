#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> um;
        sort(changed.begin(), changed.end());

        for (auto& n : changed) um[n]++;

        vector<int> ans;
        int Size = changed.size(), i = -1;
        Size = (Size % 2 == 1) ? Size / 2 + 1 : Size / 2;

        while (ans.size() < Size) {
            ++i;
            int n = changed[i];
            if (um[n] == 0) continue;
            um[n]--;

            if (n % 2 == 1) {
                if (um.count(n * 2) != 0 && um[n * 2] > 0) {
                    um[n * 2]--;
                    ans.push_back(n);
                }
                else {
                    return {};
                }
            }
            else {
                if (um.count(n / 2) != 0 && um[n / 2] > 0) {
                    um[n / 2]--;
                    ans.push_back(n);
                }
                else if (um.count(n * 2) != 0 && um[n * 2] > 0) {
                    um[n * 2]--;
                    ans.push_back(n);
                }
                else {
                    return {};
                }
            }
        }
        return ans;
    }
};

int main() {
	
	return 0;
}