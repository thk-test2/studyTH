#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int N = s.size();
        int ret = divideAndConquer(s, 0, N, k);
        return ret;
    }

    int divideAndConquer(string& s, int start, int end, int k) {
        if (end < k) return 0;
        int countMap[26] = { 0 };

        for (int i = start; i < end; ++i) {
            countMap[s[i] - 'a']++;
        }

        int ret = end - start;
        for (int mid = start; mid < end; mid++) {
            if (countMap[s[mid] - 'a'] >= k) continue;
            int midNext = mid + 1;
            while (midNext < end && countMap[s[midNext] - 'a'] < k) midNext++;
            return ret = max(divideAndConquer(s, start, mid, k),
                divideAndConquer(s, midNext, end, k));
        }
        cout << end << ", " << start << ", " << ret << "\n";
        return ret;
    }

    //     bool isValid(unordered_map<char, int>& um, int k) {
    //         for (auto& t : um) {
    //             if (t.second < k) return false;
    //         }
    //         return true;
    //     }

    //     int longestSubstring(string s, int k) {
    //         int N = s.size(), ans = 0;
    //         for (int i = 0; i < N; ++i) {
    //             unordered_map<char, int> um;
    //             for (int j = i; j < N; ++j) {
    //                 um[s[j]]++;
    //                 if (isValid(um, k))
    //                     ans = max(ans, j-i+1);
    //             }
    //         }
    //         return ans;
    //     }
};

int main() {
	
	return 0;
}