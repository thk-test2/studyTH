#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int parent[], int node) {
    if (parent[node] == node)
        return node;
    else
        return parent[node] = find(parent, parent[node]);
}

void uni(int parent[], int a, int b) {
    int pa = find(parent, a);
    int pb = find(parent, b);

    pa > pb ? parent[pa] = pb : parent[pb] = pa;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> v;
    int A, B, C;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        v.push_back(make_pair(C, make_pair(A, B)));
    }
    sort(v.begin(), v.end());

    int parent[V+1];
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    int cnt = 0;
    for (const auto& itr: v) {
        if (find(parent, itr.second.first)
                != find(parent, itr.second.second)) {
            uni(parent, itr.second.first, itr.second.second);
            cnt += itr.first;
        }
    }
    cout << cnt;
    return 0;
}
