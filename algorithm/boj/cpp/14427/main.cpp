#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using mydata = pair<int, int>;

struct MyLess {
    bool operator() (mydata a, mydata b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n;
    cin >> N;
//    priority_queue<mydata, vector<mydata>, MyLess> q;
    vector<mydata> q;

    for (int i = 1; i <= N; i++) {
        cin >> n;
        q.push_back(make_pair(n, i));
    }

    cin >> M;
    int cmd, I, V;
    for (int i = 1; i <= M; i++) {
        cin >> cmd;
        if (cmd == 2) {
            sort(q.begin(), q.end(), MyLess());
            cout << q.front().second << "\n";
        } else {
            cin >> I >> V;
            auto itr = find_if(q.begin(), q.end(), [&I](mydata a) { return a.second == I; });
            itr->first = V;
        }
    }

    return 0;
}
