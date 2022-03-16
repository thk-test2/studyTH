#include <iostream>

using namespace std;

int main()
{
    int T = 0;
    cin >> T;

    int n = 0;
    for (int i = 0; i < T; i++) {
        cin >> n;
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int j = 4; j<=n; j++) {
            dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
        }
        cout << dp[n] << endl;
    }

    return 0;
}
