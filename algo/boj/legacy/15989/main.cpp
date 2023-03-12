#include <iostream>

using namespace std;

int main()
{
    int T, n;
    cin >> T;

    int dp[10001][4];
    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;

    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;

    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    int j = 4;
    for (; j <= 10000; j++) {
        dp[j][1] = dp[j-1][1];
        dp[j][2] = dp[j-2][1] + dp[j-2][2];
        dp[j][3] = dp[j-3][1] + dp[j-3][2] + dp[j-3][3];
    }

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << endl;
    }
    return 0;
}
