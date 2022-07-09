#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> memo(n, -1000000001);
        memo[0] = nums[0];

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push({ 0, memo[0] });
        // cout << pq.top().second;

        for (int i = 1; i < n; ++i) {
            pair<int, int> cur;
            while (!pq.empty()) {
                cur = pq.top();
                if (i - cur.first > k)
                    pq.pop();
                else
                    break;
            }
            memo[i] = max(memo[i], memo[cur.first] + nums[i]);
            pq.push({ i, memo[i] });
        }
        // O(N*K) approach
        // for (int i = 1; i < n; ++i) {
        //     for (int j = 1; j <= k; ++j) {
        //         if (i-j < 0) break;
        //         if (memo[i-j] != -1000000001)
        //             memo[i] = max(memo[i], memo[i-j] + nums[i]);                
        //     }
        // }
        return memo[n - 1];
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}