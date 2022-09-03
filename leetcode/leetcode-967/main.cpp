#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int n;
    int k;
public:
    vector<int> numsSameConsecDiff(int _n, int _k) {
        n = _n; k = _k;

        vector<int> ans;
        for (int i = 1; i < 10; ++i)
            checknode(1, i, ans);
        return ans;
    }

    void checknode(int level, int num, vector<int>& ans) {
        if (level == n) {
            ans.push_back(num);
            return;
        }

        if (k == 0) {
            checknode(level + 1, num * 10 + num % 10, ans);
        }
        else {
            if (num % 10 + k < 10) {
                checknode(level + 1, num * 10 + num % 10 + k, ans);
            }
            if (num % 10 - k >= 0) {
                checknode(level + 1, num * 10 + num % 10 - k, ans);
            }
        }
    }
};

int main() {
	
	return 0;
}