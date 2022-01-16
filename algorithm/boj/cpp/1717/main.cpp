#include <iostream>

using namespace std;

int find(int parent[], int node) {
    if (parent[node] == node)
        return node;
    else
        return parent[node] = find(parent, parent[node]);
}

void unionParents(int parent[], int a, int b) {
    int pa = find(parent, a);
    int pb = find(parent, b);

    pa > pb ? parent[pa] = pb : parent[pb] = pa;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int parent[n+1];
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    int cmd, a, b;
    for (int i = 0; i < m; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            unionParents(parent, a, b);
        }
        else {
            if (find(parent, a) == find(parent, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
