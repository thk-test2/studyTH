#include <iostream>
#include <queue>
#include <vector>

using namespace std;
 
struct node {
    long long cost;
    int start;
    int target;
};

struct Compare {
    bool operator() (const node& a, const node& b) const {
        return a.cost > b.cost;
    }
};

int T, N, x, y;
double E;
long long X[1000], Y[1000];
int Parent[1000] = { -1 };
long long minimum_cost = 0;

int find_parent(int x) {
    if (Parent[x] == x) return x;
    return Parent[x] = find_parent(Parent[x]);
}

bool same_parent(int x, int y) {
    int px = find_parent(x);
    int py = find_parent(y);
    return px == py;
}

void Union(int x, int y) {
    int px = find_parent(x);
    int py = find_parent(y);

    //cout << py << "," << Parent[py] << "//" << px << "," << Parent[px] << "\n";
    px < py ? Parent[py] = px : Parent[px] = py;
}

void kruskal(priority_queue <node, vector<node>, Compare>& turnnels) {
    int cnt = 0;
    while (true) {
        auto temp = turnnels.top(); turnnels.pop();

        long long cost = temp.cost;
        int start = temp.start, target = temp.target;

        if (same_parent(start, target)) continue;
        Union(start, target);
        minimum_cost += cost;
        if (++cnt == N - 1) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cout << fixed;
    cout.precision(0);

    cin >> T;
    for (int test = 1; test <= T; test++) {
        cin >> N;
        priority_queue <node, vector<node>, Compare> turnnels;
        for (int i = 0; i < N; i++) {
            cin >> x; X[i] = x;
            Parent[i] = i;
        }
        for (int i = 0; i < N; i++) {
            cin >> y; Y[i] = y;
        }
        cin >> E;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                long long distance = (X[j] - X[i]) * (X[j] - X[i])
                    + (Y[j] - Y[i]) * (Y[j] - Y[i]);
                turnnels.push({ distance, i, j });
            }
        }
        kruskal(turnnels);

        cout << "#" << test << " " << (minimum_cost * E) << "\n";
        minimum_cost = 0;
    }

    return 0;
}