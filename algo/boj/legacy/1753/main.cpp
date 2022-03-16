#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 1000000000;
int V, E, start;
int dp[20001];
vector<pair<int, int>> arr[20001];

struct MyLess {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

void dikstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, MyLess> pq;
    pq.push(make_pair(start, 0));

    for (int i = 1; i <= V; i++) {
        dp[i] = INF;
    }
    dp[start] = 0;

    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        if (dp[temp.first] < temp.second) continue;

        for (auto& itr : arr[temp.first]) {
            int next = itr.second;
            int nextDistance = temp.second + itr.first;
            if (dp[next] > nextDistance) {
                dp[next] = nextDistance;
                pq.push(make_pair(next, nextDistance));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    cin >> start;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(w, v));
    }

    dikstra(start);
    for (int i = 1; i <= V; i++) {
        dp[i] >= INF
                ? cout << "INF\n"
                          : cout << dp[i] << "\n";
    }

    return 0;
}
