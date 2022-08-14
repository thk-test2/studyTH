#include <iostream>

using namespace std;

//bool Compare(pair<char, int> a, pair<char, int> b) {
//    return a.second > b.second;
//}

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         if (n==0) return tasks.size();

//         int alpha[26] = {0,};
//         for (auto& itr: tasks)
//             alpha[itr - 'A']++;

//         vector<pair<char, int>> sorted;
//         for (int i = 0; i < 26; ++i) {
//             if (alpha[i] == 0) continue;
//             sorted.push_back({'A'+ i, alpha[i]});
//         }
//         sort(sorted.begin(), sorted.end(), Compare);
//         int idle = (sorted[0].second - 1) * n;

//         for (int k = 1; k < sorted.size(); ++k) {
//             int dec = min(sorted[k].second, sorted[0].second - 1);
//             if (idle - dec < 0)
//                 return tasks.size();
//             idle -= dec;
//         }
//         return tasks.size() + idle;
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> um;

        int maxcnt = 0;
        for (auto& itr : tasks) {
            um[itr]++;
            maxcnt = max(maxcnt, um[itr]);
        }

        int answer = (n + 1) * (maxcnt - 1);
        for (auto& itr : um) {
            if (itr.second == maxcnt)
                answer++;
        }
        int N = tasks.size();
        return max(N, answer);
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}