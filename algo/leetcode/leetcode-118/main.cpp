#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i = 0; i < numRows; ++i) {
            pascal.push_back({});

            for (int j = 0; j <= i; ++j) {
                if (j == 0) {
                    pascal[i].push_back(1);
                }
                else if (j == i) {
                    pascal[i].push_back(1);
                }
                else {
                    int t = pascal[i - 1][j - 1] + pascal[i - 1][j];
                    pascal[i].push_back(t);
                }
            }
        }
        return pascal;
    }
};

int main() {
    Solution s;
    s.generate(5);
	return 0;
}