#include <iostream>

using namespace std;

int main()
{
    int N, n;
    cin >> N;

    int s[N];
    int dp[N];

    for (int i = 0; i < N; i++) {
        cin >> n;
        s[i] = n;
        dp[i] = 0;
    }
    dp[0] = s[0];
    dp[1] = s[0]+s[1];
    dp[2] = max(s[0]+s[2], s[1]+s[2]);

    for (int i = 3; i < N; i++) {
        dp[i] = max(dp[i-3]+s[i-1]+s[i], dp[i-2]+s[i]);
    }
    cout << dp[N-1];

    return 0;
}
