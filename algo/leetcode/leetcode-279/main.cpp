#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        vector<int> memo(n + 1, 987654321);
        memo[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                memo[i] = min(memo[i], memo[i - j * j] + 1);
            }
        }
        return memo[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(13);
	
	return 0;
}