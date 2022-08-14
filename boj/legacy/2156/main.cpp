#include <iostream>

using namespace std;

int main()
{
    int N, n;
    cin >> N;

    int dp[N], arr[N];
    for (int i = 0; i < N; i++) {
        cin >> n;
        arr[i] = n; dp[i] = 0;
    }

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(max(dp[1], arr[0]+arr[2]), arr[1]+arr[2]);

    for (int i = 3; i < N; i++) {
        dp[i] = max(max(dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i]), dp[i-1]);
    }

    int maximum = 0;
    for (int i = 0; i < N; i++) {
        maximum = max(maximum, dp[i]);
    }
    cout << maximum;

    return 0;
}
