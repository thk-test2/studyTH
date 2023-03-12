#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();

        for (int k = 0; k < N / 2; ++k) {
            int val = matrix[k][k];
            matrix[k][k] = 9999;
            traverse(k, k, val, N - k, matrix);
        }
    }

    void traverse(int i, int j, int val, int N, vector<vector<int>>& matrix) {
        int ni = j, nj = matrix.size() - 1 - i;

        if (matrix[ni][nj] == 9999) {
            matrix[ni][nj] = val;
            if (nj < N - 2) {
                nj++;
                int temp = matrix[ni][nj];
                matrix[ni][nj] = 9999;
                traverse(ni, nj, temp, N, matrix);
            }
        }
        else {
            int temp = matrix[ni][nj];
            matrix[ni][nj] = val;
            traverse(ni, nj, temp, N, matrix);
        }
    }
};

int main() {
    vector<vector<int>> matrix{ {1,2,3 }, { 4,5,6 }, { 7,8,9 } };
    //vector<vector<int>> matrix{ {5, 1, 9, 11},{2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16} };
    //vector<vector<int>> matrix{ {1,2},{3,4} };
    Solution s;
    s.rotate(matrix);
	
	return 0;
}