#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS_dp(vector<int> arr)
{
    int dp[arr.size()];

    for(int i = 0; i< arr.size(); i++)
        dp[i] = 1;

    for(int i = 1; i < arr.size(); i++)  {
        for(int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && (dp[i] < (dp[j]+1))) {
                dp[i] = dp[j]+1;
            }
        }
    }

    return *max_element(dp, dp+arr.size());
}

int LIS_binary(vector<int> arr)
{
    vector<int> lis;
    lis.push_back(INT_LEAST16_MIN);
    int length = 0;

    for(int i = 0; i< arr.size(); i++) {
        if (lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            length++;
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }

    return length;
}

int main()
{

    vector<int> arr = {10, 20, 40, 25, 20, 50, 30, 70, 85};

    cout << LIS_dp(arr) << endl;
    cout << LIS_binary(arr) << endl;

}
