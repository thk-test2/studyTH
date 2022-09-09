#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        if (prop.empty()) return 0;

        sort(prop.begin(), prop.end(), comp);
        int cnt = 0, maxn = -987654321;
        for (int i = prop.size() - 1; i >= 0; --i) {
            if (prop[i][1] < maxn)
                cnt++;
            maxn = max(maxn, prop[i][1]);
        }
        return cnt;
    }
};

int main() {
	
	return 0;
}