#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <sstream>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int min = INT8_MAX;
        int partial = 0;
        int distance = 0;
        int ret_partial = 0;
        for (int i=0; i< nums.size()-2 ; i++)
        {
            for (int j=i+1 ; j < nums.size()-1 ; j++)
            {
                for (int k=j+1 ; k < nums.size() ; k++)
                {
                    partial = nums.at(i) + nums.at(j) + nums.at(k);

                    distance = abs(target - partial);

                    if (distance < min) {
                        min = distance;
                        ret_partial = partial;
                    }
                }
            }
        }
        return ret_partial;
    }
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

    int target;
    cin >> target; 

    Solution sol;
    int ret = sol.threeSumClosest(vec, target);

    cout << ret << endl;

    return 0;
}