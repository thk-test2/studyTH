#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int N = matrix.size();

        priority_queue<int> pq;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                }
                else {
                    if (pq.top() > matrix[i][j]) {
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};

int main() {
	
	return 0;
}