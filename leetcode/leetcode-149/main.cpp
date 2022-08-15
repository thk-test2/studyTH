#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    float calIncl(vector<int>& a, vector<int>& b) {
        if (b[0] > a[0]) {
            return ((float)b[1] - a[1]) / (b[0] - a[0]);
        }
        else if (b[0] < a[0]) {
            return ((float)a[1] - b[1]) / (a[0] - b[0]);
        }
        else {
            return FLT_MAX;
        }
    }

    int maxPoints(vector<vector<int>>& points) {
        int N = points.size();
        if (N == 1) return 1;

        int max_val = 0;
        for (int i = 0; i < N - 1; ++i) {
            unordered_map<float, int> inclmap;
            for (int j = i + 1; j < N; ++j) {
                float incl = calIncl(points[i], points[j]);
                // cout << incl << "\n";
                inclmap[incl]++;
                max_val = max(max_val, inclmap[incl] + 1);
            }
        }
        return max_val;
    }
};

int main() {
	
	return 0;
}