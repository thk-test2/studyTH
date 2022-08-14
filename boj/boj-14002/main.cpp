#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];
vector<int> LIS[1001];
vector<int> answer;

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 1; i <= N; ++i) {
        LIS[i].push_back(arr[i]);
        for (int j = 1; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    LIS[i].clear();
                    LIS[i] = LIS[j];
                    LIS[i].push_back(arr[i]);
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (answer.size() < LIS[i].size())
            answer = LIS[i];
    }
    cout << answer.size() << "\n";
    for (auto itr : answer)
        cout << itr << " ";
    return 0;
}
