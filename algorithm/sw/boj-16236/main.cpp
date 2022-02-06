#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

int arr[20][20] = {0};
int dp[20][20] = {0};
bool visited[20][20] = {false};
int N, totaltime = 0, subtime = 0, mysize = 2, eatcnt = 0;
pair<int, int> init;

int candidateX, candidateY;

void printdp() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void dfs(stack<pair<int, int>>& s, pair<int, int> target, int elapsed) {
    while (!s.empty()) {
        auto temp = s.top();
        s.pop();

        int i = temp.first;
        int j = temp.second;
        visited[temp.first][temp.second] = true;

        cout << i << ", " << j << ", " << elapsed << "\n";

        if (i == target.first && j == target.second) {
            subtime = elapsed;

            cout << i << ", " << j << ", "
                 << eatcnt << ", " << mysize << ", "
                 << elapsed << ", " << totaltime << "\n";
            break;
        }
        if (i > 0) {
            if (!visited[i-1][j] && arr[i-1][j] <= mysize) {
                s.push(make_pair(i-1, j));
                dfs(s, target, elapsed+1);
            }
        }
        if (i < N-1) {
            if (!visited[i+1][j] && arr[i+1][j] <= mysize) {
                s.push(make_pair(i+1, j));
                dfs(s, target, elapsed+1);
            }
        }
        if (j > 0) {
            if (!visited[i][j-1] && arr[i][j-1] <= mysize) {
                s.push(make_pair(i, j-1));
                dfs(s, target, elapsed+1);
            }
        }
        if (j < N-1) {
            if (!visited[i][j+1] && arr[i][j+1] <= mysize) {
                s.push(make_pair(i, j+1));
                dfs(s, target, elapsed+1);
            }
        }
    }
}

void simul(vector<pair<int, pair<int,int>>>& fish) {
    while (fish.size() && mysize > fish.front().first) {
        int index = 0;
        vector<pair<int, int>> v;
        for (auto target = fish.begin(); target != fish.end(); target++) {
            if (target->first >= mysize)
                break;

            for (int i = 0; i<N; i++) {
                for (int j = 0; j<N; j++) {
                    visited[i][j] = false;
                    dp[i][j] = 0;
                }
            }
            visited[init.first][init.second] = true;

            stack<pair<int, int>> s;
            s.push(init);
            cout << "init: " << init.first << ", " << init.second << "\n";

            dfs(s, make_pair(target->second.first, target->second.second), 0);
            v.push_back(make_pair(subtime, index));
            index++;
        }
        sort(v.begin(), v.end());

        totaltime += v.front().first;
        int targetIndex = v.front().second;
        init.first = fish[targetIndex].second.first;
        init.second = fish[targetIndex].second.second;

        fish.erase(fish.begin() + targetIndex);
        eatcnt++;
        if (eatcnt == mysize) {
            mysize++;
            eatcnt = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    vector<pair<int, pair<int,int>>> fish;
    int t;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> t;
            if(t != 0) {
                arr[i][j] = t;
                if (t != 9)
                    fish.push_back(make_pair(t, make_pair(i, j)));
                else
                    init = make_pair(i, j);
            }
        }
    }
    sort(fish.begin(), fish.end());
    simul(fish);
    cout << totaltime;

    return 0;
}
