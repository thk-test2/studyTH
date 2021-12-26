#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int N;
    int t, p;
    cin >> N;

    vector<pair<int, int>> v;
    int maximum = 0;
    int dp[N+1];

    for (int i = 0; i < N; i++) {
        cin >> t >> p;
        v.push_back(make_pair(t, p));
        dp[i] = 0;
    }
    dp[N] = 0;

    for (int i = 0; i <= N; i++) {
        maximum = max(maximum, dp[i]);
        if (i + v[i].first <= N)
            dp[i + v[i].first] = max(dp[i + v[i].first], maximum + v[i].second);
    }

    cout << maximum;

    return 0;
}
