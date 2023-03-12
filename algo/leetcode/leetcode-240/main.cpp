#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool answer = false;
        for (int i = 0; i < matrix.size(); ++i) {
            int temp = binarySearch(matrix, i, target);
            // cout << i << ", " << temp << "\n";
            if (temp != -1)
                return true;
        }
        return answer;
    }

    int binarySearch(vector<vector<int>>& matrix, int i, int target) {
        int start = 0, end = matrix[i].size() - 1;
        int mid = -1;

        while (start <= end) {
            mid = (start + end) / 2;
            if (matrix[i][mid] > target) {
                end = mid - 1;
            }
            else if (matrix[i][mid] < target) {
                start = mid + 1;
            }
            else {
                break;
            }
        }
        return start > end ? -1 : mid;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}