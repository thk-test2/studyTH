#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum = accumulate(gas.begin(), gas.end(), 0);
        int cost_sum = accumulate(cost.begin(), cost.end(), 0);
        if (gas_sum < cost_sum) return -1;

        int N = gas.size();
        int ans = -1;

        int i = 0;
        while (i < N) {
            if (gas[i] == 0 || gas[i] < cost[i]) {
                ++i; continue;
            }

            int j = i, cur = 0;
            while (true) {
                cur += gas[j];
                if (cost[j] != 0) {
                    cur -= cost[j];
                    if (cur < 0) {
                        i = j + 1; break;
                    }
                }

                ++j;
                j %= N;
                if (j == i) {
                    ans = j; break;
                }
            }
            if (ans != -1) break;
        }
        return ans;
    }
};

int main() {
	
	return 0;
}