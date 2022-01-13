#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    map<string, int> m;

    int cnt = 0;
    string temp;
    for (int i = 0; i < N+M; i++) {
        cin >> temp;
        m[temp]++;
        if (m[temp] == 2)
            cnt++;
    }

    cout << cnt << endl;
    for (auto& itr: m) {
        if (itr.second == 2) {
            cout << itr.first << endl;
        }
    }

    return 0;
}
