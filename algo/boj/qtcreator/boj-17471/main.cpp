#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX = 11;

int people[MAX];
vector<int> node[MAX];
bool selected[MAX];
bool visit[MAX];

int n;
int ans = INT_MAX;

bool isConnected(vector<int>& v, bool flag) {
    fill(begin(visit), end(visit), false);
    queue<int> q;
    visit[v[0]] = true;
    q.push(v[0]);
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto value: node[x]) {// 노드 안에 있는 값 다 꺼내서 탐색할 곳 큐에 넣어주기
            if (selected[value] != flag || visit[value]) continue;
            cnt++;
            visit[value] = true; // 이미 갔던 노드는 못 가도록 check 표시
            q.push(value);
        }
    }

    return v.size() == cnt; // 탐색한 노드 개수와 구역의 노드 개수가 같다면 모두 다 연결됨
}

bool isOk() {
    vector<int> a;
    vector<int> b;

    for (int i = 1; i <= n; i++) {
        if (selected[i]) a.push_back(i);
        else b.push_back(i);
    }
    if (a.empty() || b.empty())
        return false;
    if (!isConnected(a, true))
        return false;
    if (!isConnected(b, false))
        return false;
    return true;
}

void calcu() {
    int a_sum = 0;
    int b_sum = 0;

    for (int i = 1; i <= n; i++) {
        if (selected[i]) a_sum += people[i]; // 선택된 구역
        else b_sum += people[i]; // 선택이 안된 구역으로 나눠준다.
    }
    ans = min(ans, abs(a_sum - b_sum));
}

void dfs(int start, int depth) {
    if (depth >= 1) {
        if (isOk()) {
            calcu();
        }
    }

    for (int i = start; i <= n; i++) {
        if (selected[i]) continue;
        selected[i] = true;
        dfs(i + 1, depth + 1);
        selected[i] = false;
    }
}

void combi() {
    vector<int> v;

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            v.push_back(0);
        }
        for (int j = 1; j <= i; j++) {
            v.push_back(1);
        }

        do {
            for (int j = 1; j <= n; j++) {
                if (v[j-1] == 1) {
                    selected[j] = true;
                }
            }
            if (isOk()) {
                calcu();
            }
            fill(begin(selected), end(selected), false);
        } while (next_permutation(v.begin(), v.end()));
        v.clear();
    }
}

void solution() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> people[i];
    }
    for (int i = 1; i <= n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            node[i].push_back(tmp);
            node[tmp].push_back(i);
        }
    }
//    dfs(1, 0);
    combi();

    ans == INT_MAX ? cout << -1 << "\n"
                             : cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solution();

    return 0;
}
