#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, edges;
    cin >> N;
    cin >> edges;

    vector<int> v[101];
    int a, b;
    for (int i = 1; i <= edges; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bool inserted[101];
    for (int i = 1 ; i<=N; i++)
        inserted[i] = false;

    queue<int> q;
    q.push(1);
    inserted[1] = true;
    int cnt = -1;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        cnt++;

        for (auto& neighbor : v[temp]) {
            if (inserted[neighbor] == false) {
                q.push(neighbor);
                inserted[neighbor] = true;
            }
        }
    }
    cout << cnt;

    return 0;
}
