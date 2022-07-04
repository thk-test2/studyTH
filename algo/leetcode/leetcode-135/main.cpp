#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        if (N == 0) return 0;
        else if (N == 1) return 1;

        bool onlyIncrease = true;
        for (int i = 1; i < N; ++i) {
            if (ratings[i] <= ratings[i - 1]) {
                onlyIncrease = false;
                break;
            }
        }
        if (onlyIncrease) {
            return N * (N + 1) / 2;
        }

        bool onlyDecrease = true;
        for (int i = 1; i < N; ++i) {
            if (ratings[i] >= ratings[i - 1]) {
                onlyDecrease = false;
                break;
            }
        }
        if (onlyDecrease) {
            return N * (N + 1) / 2;
        }

        vector<int> candy(N, -1);
        int sum = 0, cnt = 0;

        if (ratings[0] <= ratings[1]) {
            candy[0] = 1;
            sum += candy[0];
            cnt++;
        }
        if (ratings[N - 1] <= ratings[N - 2]) {
            candy[N - 1] = 1;
            sum += candy[N - 1];
            cnt++;
        }

        // cout << sum << ", " << cnt << "\n";
        int i = -1;
        while (cnt < N) {
            if (++i == N) i = 0;
            if (candy[i] != -1) continue;

            if (i > 0 && i < N - 1) {
                if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]) {
                    candy[i] = 1;
                    sum += candy[i];
                    cnt++;
                }
                else if (candy[i - 1] != -1 && candy[i + 1] != -1) {
                    if (ratings[i] > ratings[i - 1] && ratings[i] > ratings[i + 1]) {
                        candy[i] = max(candy[i - 1], candy[i + 1]) + 1;
                        sum += candy[i];
                        cnt++;
                    }
                    else if (ratings[i] > ratings[i - 1]) {
                        candy[i] = candy[i - 1] + 1;
                        sum += candy[i];
                        cnt++;
                    }
                    else if (ratings[i] > ratings[i + 1]) {
                        candy[i] = candy[i + 1] + 1;
                        sum += candy[i];
                        cnt++;
                    }
                }
                else if (candy[i - 1] != -1) {
                    if (ratings[i] > ratings[i - 1] && ratings[i] <= ratings[i + 1]) {
                        candy[i] = candy[i - 1] + 1;
                        sum += candy[i];
                        cnt++;
                    }
                }
                else if (candy[i + 1] != -1) {
                    if (ratings[i] > ratings[i + 1] && ratings[i] <= ratings[i - 1]) {
                        candy[i] = candy[i + 1] + 1;
                        sum += candy[i];
                        cnt++;
                    }
                }
            }
            else if (i == 0) {
                if (candy[1] != -1 && ratings[0] > ratings[1]) {
                    candy[0] = candy[1] + 1;
                    sum += candy[i];
                    cnt++;
                }
            }
            else if (i == N - 1) {
                if (candy[N - 2] != -1 && ratings[N - 1] > ratings[N - 2]) {
                    candy[N - 1] = candy[N - 2] + 1;
                    sum += candy[i];
                    cnt++;
                }
            }
        }
        // cout << cnt << "\n";
        // for (auto& itr : candy) {
        //     cout << itr << "\n";
        // }
        return sum;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	return 0;
}