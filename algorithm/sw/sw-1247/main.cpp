#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimum = INT_MAX, result = 0;
int N;
int sx, sy, ex, ey;
vector<pair<int, int>> v;

void permu(pair<int, int> arr[], bool selected[], int index, int cnt) {
    if (cnt == N) {
        for (int i = 0; i <= N; i++) {
            if (i == 0) {
                result += abs(v[i].first - sx) + abs(v[i].second - sy);
            } else if (i == N) {
                result += abs(ex - v[i-1].first) + abs(ey - v[i-1].second);
            } else {
                result += abs(v[i].first - v[i-1].first)
                        + abs(v[i].second - v[i-1].second);
            }
        }
        minimum = min(minimum, result);
        result = 0;
        return;
    }
    for (int i = index; i < N; i++) {
        if (selected[i]) continue;
        selected[i] = true;
        v.push_back(arr[i]);
        permu(arr, selected, index, cnt+1);
        v.pop_back();
        selected[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> N;
        cin >> sx >> sy >> ex >> ey;

        pair<int, int> arr[N];
        bool selected[N];
        int x, y;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            arr[i] = make_pair(x, y);
            selected[i] = false;
        }
        permu(arr, selected, 0, 0);
        cout << "#" << test_case << " " << minimum << "\n";
        minimum = INT_MAX; result = 0;
    }
    return 0;
}
