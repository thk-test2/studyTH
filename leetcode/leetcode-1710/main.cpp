#include <iostream>

using namespace std;

struct Compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for (auto& box : boxTypes) {
            pq.push({ box[0], box[1] });
        }

        int answer = 0;
        while (!pq.empty()) {
            pair<int, int> cur = pq.top();
            // cout << cur.first << ", " << cur.second << ", " << answer << ", " << truckSize << "\n";

            if (truckSize > cur.first) {
                answer += (cur.second * cur.first);
                truckSize -= cur.first;
            }
            else {
                answer += (truckSize * cur.second);
                break;
            }
            pq.pop();
        }
        return answer;
    }
};

int main() {
	
	return 0;
}