#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    long long int dp[N+1];
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i<=N; i++) {
        dp[i] = dp[i-1]%10007 + dp[i-2]%10007;
    }
    cout << dp[N]%10007;

    return 0;
}
