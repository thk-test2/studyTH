#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int area[n+1][m+1];
        for (int i = 1; i<= n ; i++) {
            for (int j=1 ; j<=m; j++) {
                if( i==1 || j==1 ) area[i][j] = 1;
                else area[i][j] = area[i-1][j] + area[i][j-1];
            }
        }
        return area[n][m];
    }
};

int main () {

    int M, N;
    std::cin >> M;
    std::cin >> N; 

    Solution sol;
    int ret = sol.uniquePaths(M, N);

    std::cout << ret << std::endl;

    return 0;
}