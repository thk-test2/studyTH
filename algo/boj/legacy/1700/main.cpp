#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

/*
3 100
56 71 70 25 52 77 76 8 68 71 51 65 13 23 7 16 19 54 95 18 86 74 29 76 61 93 44 96 32 72 64 19 50 49 22 14 7 64 24 83 6 3 2 76 99 7 76 100 60 60 6 50 90 49 27 51 37 61 16 84 89 51 73 28 90 77 73 39 78 96 78 13 92 54 70 69 62 78 7 75 30 67 97 98 19 86 90 90 2 39 41 58 57 84 19 8 52 39 26 7
80

3 10
6 7 4 8 6 4 9 1 1 9
3

3 14
1 4 3 2 5 4 3 2 5 3 4 2 3 4
4
*/

struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> v;

    int temp;
    for (int i = 0; i<K; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> tab;
    set<int> s;
    int cnt = 0;

    for (int i = 0; i<K; i++) {
        if ( (s.size() == N) && (s.find(v[i]) == s.end())) {
            int candidate = tab.top().first;
            s.erase(s.find(candidate));
            tab.pop();
            cnt++;
        }

        int next_index = v.size();
        auto itr = find(v.begin()+i+1, v.end(), v[i]);
        if (itr != v.end()) {
            next_index = distance(v.begin(), itr);
        }
        tab.push(make_pair(v[i], next_index));
        s.insert(v[i]);
    }

    cout << cnt;

    return 0;
}
