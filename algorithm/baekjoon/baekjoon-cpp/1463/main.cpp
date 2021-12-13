#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int dp[N+1];
    dp[1] = 0;

    for (int i = 2; i <=N ; i++) {
        if (i%2 != 0 && i%3 == 0) {
            dp[i] = min(dp[i/3] + 1, dp[i-1] + 1);
        } else if (i%2 == 0 && i%3 != 0) {
            dp[i] = min(dp[i/2] + 1, dp[i-1] + 1);
        } else if (i%2 == 0 && i%3 == 0) {
            dp[i] = min(dp[i/2] + 1, dp[i/3] + 1);
        } else {
            dp[i] = dp[i-1] + 1;
        }
    }
    cout << dp[N];

    return 0;
}
