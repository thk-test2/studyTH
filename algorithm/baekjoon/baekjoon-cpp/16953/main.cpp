#include <iostream>
#include <climits>

using namespace std;

void dfs(long long A, long long B, int& minimum, int& cnt, bool& possible) {
    if (B < A) {
        possible = false;
        return;
    }
    if (B == A) {
        minimum = min(minimum, cnt);
        return;
    }
    if (B % 10 == 1) {
        B = B/10;
    } else if (B % 2 == 0) {
        B = B/2;
    } else {
        possible = false;
        return;
    }
    cnt++;

    dfs(A, B, minimum, cnt, possible);
}

int main()
{
    long long A, B;
    cin >> A >> B;

    int cnt = 0;
    int minimum = INT_MAX;
    bool possible = true;
    dfs(A, B, minimum, cnt, possible);

    if (possible)
        cout << minimum + 1;
    else
        cout << -1;

    return 0;
}
