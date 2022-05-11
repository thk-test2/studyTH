#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> used;

        used.push_back(nums[0]);
        um[nums[0]]++;

        int numSize = nums.size();
        for (int i = 1; i < numSize; ++i) {
            if (um.count(nums[i]) == 0 && nums[i] != nums[i - 1]) {
                used.push_back(nums[i]);
            }
            um[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (auto itr : used) {
            pq.push(make_pair(itr, um[itr]));
        }

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}