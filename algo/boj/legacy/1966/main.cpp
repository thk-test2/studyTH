#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using data_ = pair<int, bool>;

int main()
{
    int T, N, M;
    cin >> T;

    vector<data_> q;
    int n;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            cin >> n;
            j == M ? q.push_back(make_pair(n, true))
                   : q.push_back(make_pair(n, false));
        }
        int cnt = 0;
        while (true) {
            auto temp = q.front();
            q.erase(q.begin());

            if (find_if(q.begin(), q.end(), [&temp](data_ d){ return temp.first < d.first;})
                    != q.end()) {
                q.push_back(temp);
                continue;
            }
            cnt++;
            if (temp.second)
                break;
        }
        cout << cnt << endl;
        q.clear();
    }

    return 0;
}
