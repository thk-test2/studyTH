#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

void BFS(vector<set<int>>& edges, int N, int V) {
    queue<int> que;
    bool inserted[N];
    for (int i = 0; i < N; i++)
        inserted[i] = false;

    que.push(V);
    inserted[V-1] = true;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        cout << temp << " ";

        for (auto& itr: edges[temp-1]) {
            if (!inserted[itr-1]) {
                que.push(itr);
                inserted[itr-1] = true;
            }
        }
    }
}

void DFS(vector<set<int>>& edges, stack<int>& st, bool inserted[]) {
    while (!st.empty()) {
        int temp = st.top();
        st.pop();
        cout << temp << " ";
        for (auto& itr : edges[temp-1]) {
            if (!inserted[itr-1]) {
                st.push(itr);
                inserted[itr-1] = true;
                DFS(edges, st, inserted);
            }
        }
    }
}

int main()
{
    int N, M, V;
    vector<set<int>> edges;

    cin >> N >> M >> V;
    bool inserted[N];
    for (int i = 0; i < N; i++) {
        inserted[i] = false;
        edges.push_back({});
    }

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        edges[a-1].insert(b);
        edges[b-1].insert(a);
    }

    stack<int> st;
    st.push(V);
    inserted[V-1] = true;
    DFS(edges, st, inserted);
    cout << endl;

    BFS(edges, N, V);

    return 0;
}
