#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for (int i=0; i<1000; i++)
            for (int j=0; j<1000; j++)
                dp[i][j] = -1;
        int ret = recursive(triangle, 0, 0);
        
        return ret;
    }
    
    int recursive(vector<vector<int>>& triangle, int col, int pos) {
        cout << "TEST: " << col << ", " << pos << ", " << dp[col][pos] << endl;;
        if ( col >= triangle.size() || pos >= triangle.at(col).size() ) {
            cout << "TEST2: " << 0 << endl;
            return 0;
        }
        
        if (dp[col][pos] != -1 ) {
            cout << "TEST3: " << col << ", " << pos << ", " << dp[col][pos] << endl;
            return dp[col][pos];
        }
        cout << "TEST4: " << col << ", " << pos << ", " << dp[col][pos] << endl;
        int ret = min(recursive(triangle, col+1, pos),
                      recursive(triangle, col+1, pos+1))
                    + triangle.at(col).at(pos);
        dp[col][pos] = ret;
        cout << ret << endl;
        return ret;

    }
private:
    int dp[1000][1000];
    
};

int main() {

    string line;
    string word;
    getline(cin, line);
    stringstream ss(line);

    vector<int> vec;
    while (getline(ss, word, ',')) {
        vec.emplace_back(stoi(word));
    }

    Solution sol;
    // int ret = sol.minimumTotal();

    return 0;
}