#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&x](int& a, int& b) -> bool {
            int abs_a = abs(a - x), abs_b = abs(b - x);
            if (abs_a == abs_b) {
                return a < b;
            }
            return abs_a < abs_b;
        });

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
	
	return 0;
}