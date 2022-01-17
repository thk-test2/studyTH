#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int N, E;
int v1, v2;
vector<pair<int, int>> arr[801];
long long dp[801];

struct MyLess {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int dikstra_modified(int start, int to) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyLess> pq;
    pq.push(make_pair(start, 0));

    fill(begin(dp), begin(dp)+N+1, INF);
    dp[start] = 0;

    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if (dp[current] < distance) continue;
        for (auto& itr: arr[current]) {
            int next = itr.second;
            int nextDistance = distance + itr.first;
            if (dp[next] > nextDistance) {
                dp[next] = nextDistance;
                pq.push(make_pair(next, nextDistance));
            }
        }
    }
    return dp[to];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> E;

    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(c, b));
        arr[b].push_back(make_pair(c, a));
    }
    cin >> v1 >> v2;
    long long ret = min(dikstra_modified(1, v1) + dikstra_modified(v1, v2) + dikstra_modified(v2, N),
                        dikstra_modified(1, v2) + dikstra_modified(v2, v1) + dikstra_modified(v1, N));
    if (ret <= 0 || ret >=INF)
        cout << "-1\n";
    else
        cout << ret << "\n";

    return 0;
}
