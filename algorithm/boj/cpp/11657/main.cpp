#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int N, M;
vector<pair<int,int>> arr[501];
long long dp[501];

bool belman(int start) {
    fill(begin(dp), end(dp), INF);
    dp[start] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[j] != INF) {
                for (const auto& itr: arr[j]) {
                    int next = itr.second;
                    long long nextDistance = dp[j] + itr.first;
                    if (dp[next] > nextDistance) {
                        if (i == N)
                            return false;
                        dp[next] = nextDistance;
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        arr[A].push_back(make_pair(C, B));
    }

    if (belman(1)) {
        for (int i = 2; i <= N; i++) {
            dp[i] != INF
                    ? cout << dp[i] << "\n"
                              : cout << -1 << "\n";
        }
    } else
        cout << -1 << "\n";
    return 0;
}
