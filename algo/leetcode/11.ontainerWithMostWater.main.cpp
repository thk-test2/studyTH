#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int base_height = 0;
        int max = 0;
        int partial_1 = 0;
        int partial_2 = 0;
        for (int i = 0; i < height.size()-1 ; i++)
        {
            base_height = height.at(i);
            for (int j=i+1; j < height.size() ; j++)
            {
                if (base_height >= height.at(j))
                    partial_2 = (j-i) * height.at(j);
                else
                    partial_1 = (j-i) * base_height;
                
                if (partial_1 > max)
                    max = partial_1;
                else if (partial_2 > max)
                    max = partial_2;
            }
        }
        return max;
    }
};

int main() {

    int N;
    vector<int> vec;

    while (cin >> N) {
        vec.push_back(N);
    }
    // for (const auto& itr : vec) {
    //     cout << itr << endl;
    // }

    Solution sol;
    int ret = sol.maxArea(vec);

    cout << ret << endl;

    return 0;
}