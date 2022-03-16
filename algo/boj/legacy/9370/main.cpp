#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
int T, n, m, t;
int s, g, h;
vector<pair<int,int>> arr[2001];
long long dp[2001];

struct MyLess {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

int dikstra(int start, int to) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, MyLess> pq;
    pq.push(make_pair(start, 0));

    fill(begin(dp), end(dp), INF);
    dp[start] = 0;
    while(!pq.empty()) {
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        for (const auto& itr : arr[current]) {
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
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        int a, b, d, x;
        vector<int> dest;
        for (int j = 0; j < m; j++) {
            cin >> a >> b >> d;
            arr[a].push_back(make_pair(d, b));
            arr[b].push_back(make_pair(d, a));
        }
        for (int k = 0; k < t; k++) {
            cin >> x;

            int t1 = min(dikstra(s, g) + dikstra(g, h) + dikstra(h, x),
                         dikstra(s, h) + dikstra(h, g) + dikstra(g, x));
            if (t1 == dikstra(s, x)) {
                dest.push_back(x);
            }
        }
        sort(dest.begin(), dest.end());
        for (const auto& itr: dest) {
            cout << itr << " ";
        }
        cout << "\n";

        for (int i = 0; i < 2001; i++)
            arr[i].clear();
    }
    return 0;
}
