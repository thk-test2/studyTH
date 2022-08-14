#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS_dp(string& S)
{
    int n = S.length();
    int dp[n];

    for (auto& it : dp) {
        it = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j< i; j++)
        {
            // dp[i]를 증가시키는 조건에 대한 고민이 필요하다.
            // 10 20 10 30 20 50
            if (S[j] <= S[i] && dp[i] < dp[j]+1)
            {
                dp[i] = dp[j]+1;
            }
        }
    }
    return S.length() - *max_element(dp, dp+n);
}

int LIS_binary1(string& v)
{
    vector<char> lis;
    lis.push_back(0);

    int length = v.length();

//    for (int i=0; i < length; i++)
    for(const auto& it : v)
    {
        if (lis.back() < it) {
            lis.push_back(it);
        } else {
            auto index = lower_bound(lis.begin(), lis.end(), it);
            *index = it;
        }
    }
    return length - (lis.size()-1);
}

// Binary search (note boundaries in the caller)
int binarySearch(vector<char>& v, int lower, int upper, char key)
{
    while (upper > lower+1) {
        int mid = lower + (upper-lower)/2;
        if(v[mid] >= key) {
            upper = mid;
        } else {
            lower = mid;
        }
    }
    return upper;
}

int LIS_binary2(string& v)
{
    vector<char> tail(v.length(), 0);
    int length = 1; // always points empty slot in tail

    tail[0] = v[0];

    for (int i = 1; i < v.length() ; i++)
    {
        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

        // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

        else {
            tail[binarySearch(tail, -1, length - 1, v[i])] = v[i];
        }
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
        cout << it << ": " << LIS_binary1(it) << endl;
        cout << it << ": " << LIS_binary2(it) << endl;
    }
}
