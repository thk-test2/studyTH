#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int prefix[100][100];
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int M = matrix.size(), N = matrix[0].size();

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {

                prefix[i][j] = matrix[i][j];
                if (i > 0)
                    prefix[i][j] += prefix[i - 1][j];
                if (j > 0)
                    prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0)
                    prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }

        int max_sum = -987654321;
        for (int a = 0; a < M; ++a) {
            for (int b = 0; b < N; ++b) {
                for (int c = a; c < M; ++c) {
                    for (int d = b; d < N; ++d) {
                        // (a, b) ~ (c, d) гу
                        int sum = prefix[c][d];
                        if (a > 0)
                            sum -= prefix[a - 1][d];
                        if (b > 0)
                            sum -= prefix[c][b - 1];
                        if (a > 0 && b > 0)
                            sum += prefix[a - 1][b - 1];

                        if (sum < k && sum > max_sum)
                            max_sum = sum;
                        else if (sum == k)
                            return sum;
                    }
                }
            }
        }
        return max_sum;
    }
};

int main() {

    Solution s;
    vector<vector<int>> v{ {2, 2, -1} };
    int k = 0;
    cout << s.maxSumSubmatrix(v, k);
	
	return 0;
}