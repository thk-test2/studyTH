#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, L, x;
    deque<pair<int, int>> dq;
    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        while (dq.size() && dq.front().second <= i - L)
            dq.pop_front();
        cin >> x;
        while (dq.size() && dq.back().first >= x)
            dq.pop_back();
        dq.push_back({ x,i });
        cout << dq.front().first << " ";
    }
    return 0;
}