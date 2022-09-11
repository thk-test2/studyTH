#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
        int k) {
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i)
            ess[i] = { efficiency[i], speed[i] };

        sort(ess.begin(), ess.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> pq;
        long sumS = 0, res = 0;
        for (auto& [e, s] : ess) {
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9 + 7);
    }
};

int main() {
	
	return 0;
}