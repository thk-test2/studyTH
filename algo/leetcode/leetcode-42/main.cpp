#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();

        bool always_decrease = true;
        int cur = height[0];
        for (int i = 1; i < N; ++i) {
            if (height[i] >= cur) {
                always_decrease = false;
                break;
            }
        }

        int i = always_decrease ? N - 1 : 0;
        int j = always_decrease ? N - 2 : 1;
        int total = 0, temp = 0;
        bool found = false;
        while ((i >= 0 && i < N) && (j >= 0 && j < N)) {
            if (height[i] > height[j]) {
                found = false;
                temp += (height[i] - height[j]);
                if (j > 0 && j < N - 1) {
                    always_decrease ? j-- : j++;
                    continue;
                }
            }
            else {
                found = true;
                total += temp;
                temp = 0;
                i = j;
                j = always_decrease ? i - 1 : i + 1;
                continue;
            }
            if (j <= 0 || j >= N - 1) {
                if (!found) {
                    height[i]--;
                    temp = 0;
                    j = always_decrease ? i - 1 : i + 1;
                }
            }
        }
        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solution s;
    //vector<int> v{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    vector<int> v{ 4,2,0,3,2,5 };
    cout << s.trap(v);

	return 0;
}