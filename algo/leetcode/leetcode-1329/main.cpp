#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        for (int j = 0; j < N; ++j) {
            vector<int> vsort;

            int x = 0, y = j;
            while (x < M && y < N) {
                vsort.push_back(mat[x][y]);
                x++; y++;
            }
            sort(vsort.begin(), vsort.end());

            x = 0, y = j;
            for (auto n : vsort) {
                mat[x][y] = n;
                x++; y++;
            }
        }

        for (int i = 0; i < M; ++i) {
            vector<int> vsort;

            int x = i, y = 0;
            while (x < M && y < N) {
                vsort.push_back(mat[x][y]);
                x++; y++;
            }
            sort(vsort.begin(), vsort.end());

            x = i, y = 0;
            for (auto n : vsort) {
                mat[x][y] = n;
                x++; y++;
            }
        }

        return mat;
    }
};

int main() {
	
	return 0;
}