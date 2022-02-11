#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    bool vis[10001] = {false,};
    vector<int> v;

    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;

        int t; v.push_back(0);
        for (int i = 0; i < N; i++) {
            cin >> t;
            int curSize = v.size();
            for (int j = 0; j < curSize; j++) {
                int candi = t + v[j];
                if (!vis[candi]) {
                    v.push_back(candi);
                    vis[candi] = true;
                }
            }
        }

        cout << "#" << test_case << " " << v.size() << "\n";
        v.clear();
        fill(begin(vis), end(vis), false);
    }
    return 0;
}
