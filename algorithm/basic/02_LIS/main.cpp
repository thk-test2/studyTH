#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS_dp(string& S)
{
    int dp[S.length()];
    for(int i = 0; i < S.length(); i++) {
        dp[i] = 1;
    }

    for(int i = 1; i < S.length(); i++) {
        for(int j = 0; j < i; j++) {
            if(S[j] <= S[i] && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
            }
        }
    }

    return S.length() - *max_element(dp, dp+S.length());
}

// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int LIS_binary(string& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

        // v[i] will become end candidate of an existing
        // subsequence or Throw away larger elements in all
        // LIS, to make room for upcoming grater elements
        // than v[i] (and also, v[i] would have already
        // appeared in one of LIS, identify the location
        // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return v.length() - length;
}

int main()
{
    vector<string> arr;

    arr.push_back("abcdefg");
    arr.push_back("cba");
    arr.push_back("abcb");
    arr.push_back("vwzyx");
    arr.push_back("zvwzyx");
    arr.push_back("adabcef");
    arr.push_back("fantastic");

    for (auto& it: arr){
        cout << it << ": " << LIS_dp(it) << endl;
        cout << it << ": " << LIS_binary(it) << endl;
    }
}
