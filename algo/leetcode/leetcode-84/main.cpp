#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int cur_height = heights[st.top()];
                st.pop();
                int idx = st.empty() ? -1 : st.top();
                ans = max(ans, cur_height * (i - idx - 1));
            }
            st.push(i);
        }
        return ans;
    }
};

int main() {
    //vector<int> h{ 2, 1, 5, 6, 2, 3 };
    //vector<int> h{ 2, 4 };
    vector<int> h{ 2, 1, 2 };
    Solution s;
    s.largestRectangleArea(h);

	return 0;
}