#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> arr[1001];
int dp[1001] = {0,};

int INF = 1000000000;
int N, M;

struct MyLess {
    bool operator() (pair<int,int> a, pair<int,int>b) { return a.second > b.second; }
};

void dijkstra(int start, int to) {
    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }
    dp[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, MyLess> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();

        if (dp[current] < distance) continue;
        for (int i = 0; i < arr[current].size(); i++) {
            int next = arr[current][i].second;
            int nextDistance = distance + arr[current][i].first;

            if (nextDistance < dp[next]) {
                dp[next] = nextDistance;
                pq.push(make_pair(next, nextDistance));
            }
        }
    }
}

int main()
{
    cin >> N; cin >> M;

    int start, to, c;
    for (int i = 1; i <= M; i++) {
        cin >> start >> to >> c;
        arr[start].push_back(make_pair(c, to));
    }
    cin >> start >> to;
    dijkstra(start, to);

    cout << dp[to] << endl;
    return 0;
}
