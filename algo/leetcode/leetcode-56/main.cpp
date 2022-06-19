#include <iostream>

using namespace std;

bool Compare(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        if (a[1] == b[1]) return false;
        return a[1] > b[1];
    }
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int N = intervals.size();
        if (N <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), Compare);
        vector<vector<int>> answer;

        int s = intervals[0][0], e = intervals[0][1];
        for (int i = 1; i < N; ++i) {
            int ns = intervals[i][0], ne = intervals[i][1];
            if (ns >= s && ns <= e) {
                if (ne > e) {
                    e = ne;
                }
            }
            else {
                // no overlap
                answer.push_back({ s, e });
                s = ns, e = ne;
            }
            if (i == N - 1)
                answer.push_back({ s, e });
        }
        return answer;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}