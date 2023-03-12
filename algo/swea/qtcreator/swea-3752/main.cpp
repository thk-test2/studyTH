#include <iostream>
#include <vector>
#include <set>

using namespace std;

int selected[100] = {false};
int arr[100];
int N;

void score(int I, int index, int cnt, set<int>& s) {
    if (cnt == I) {
        int result = 0;
        for (int i = 0; i < N; i++) {
            if (selected[i])
                result += arr[i];
        }
        s.insert(result);
    }
    for (int i = index; i < N; i++) {
        if (selected[i])
            continue;
        selected[i] = true;
        score(I, i, cnt+1, s);
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
        int t;
        for (int i = 0; i < N; i++) {
            cin >> t;
            arr[i] = t;
        }

        set<int> s;
        s.clear(); s.insert(0);
        for (int i = 1; i <= N; i++) {
            score(i, 0, 0, s);
            fill(begin(selected), end(selected), false);
        }
        cout << "#" << test_case << " " << s.size() << "\n";
    }
    return 0;
}
