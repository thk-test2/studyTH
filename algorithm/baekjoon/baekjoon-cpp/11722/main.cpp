#include <iostream>

using namespace std;

int main()
{
    int N, n;
    cin >> N;

    int dp[1001];
    int arr[1001];
    for (int i = 1; i <= N; i++) {
        cin >> n;
        arr[i] = n;
    }

    int result = 0;
    for (int i = 1; i<=N; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        result = max(result, dp[i]);
    }
    cout << result;

    return 0;
}
