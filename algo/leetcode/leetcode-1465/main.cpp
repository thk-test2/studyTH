#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        hCuts.push_back(0), hCuts.push_back(h);
        vCuts.push_back(0), vCuts.push_back(w);

        sort(begin(hCuts), end(hCuts));
        sort(begin(vCuts), end(vCuts));

        auto max_h = 0, max_v = 0;
        for (auto i = 0; i < hCuts.size() - 1; ++i)
            max_h = max(max_h, hCuts[i + 1] - hCuts[i]);
        for (auto i = 0; i < vCuts.size() - 1; ++i)
            max_v = max(max_v, vCuts[i + 1] - vCuts[i]);
        return (long)max_h * max_v % 1000000007;
    }
};

int main() {
    Solution s;
    //vector<int> h{ 1 };
    //vector<int> v{ 2,1,5 };
    //cout << s.maxArea(2, 7, h, v);

    vector<int> h{ 2 };
    vector<int> v{ 2 };
    cout << s.maxArea(1000000000, 1000000000, h, v) << "\n";

    int h1 = 1000000000, h0 = 2, v1 = 2, v0 = 0;
    int hlen = (h1 - h0) % 1000000007;
    int vlen = (v1 - v0) % 1000000007;
    int max_area = 0, temp = (hlen * vlen) % 1000000007;
    cout << max(max_area, temp);

	return 0;
}