#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

using tp = tuple<int, int, int>;

struct MyComp {
    bool operator()(pair<string, tp> n, pair<string, tp> m) {
        tp a = n.second;
        tp b = m.second;

        if (get<0>(a) == get<0>(b)) {
            if (get<1>(a) == get<1>(b)) {
                if (get<2>(a) == get<2>(b)) {
                    return n.first < m.first;
                }
                else {
                    return get<2>(a) > get<2>(b);
                }
            } else {
                return get<1>(a) < get<1>(b);
            }
        } else {
            return get<0>(a) > get<0>(b);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    string str;
    int a, b, c;
    vector<pair<string, tp>> v;
    for (int i = 0; i < N; i++) {
        cin >> str >> a >> b >> c;
        v.push_back(make_pair(str, make_tuple(a, b, c)));
    }
    sort(v.begin(), v.end(), MyComp());

    for (const auto& itr: v)
        cout << itr.first << "\n";
    return 0;
}
