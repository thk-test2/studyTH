#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int arr[10][10] = {0};
bool visited[10][10] = {false};
int answer = 987654321;

void make_visit(int y, int x, int width, bool t) {
    for (int i = y ; i < y + width ; i++) {
        for (int j = x ; j < x + width ; j++) {
            visited[i][j] = t;
        }
    }
}

bool can_fill(int y, int x, int width) {
    for (int i = y ; i < y + width ; i++) {
        for (int j = x ; j < x + width ; j++) {
            if (i >= 10 || j >= 10 ||arr[i][j] == 0 || visited[i][j])
                return false;
        }
    }
    return true;
}

int max_width(int y, int x) {
    int i = 5;
    while (i > 0) {
        if (can_fill(y, x, i))
            break;
        i--;
    }
    return i;
}

void dfs(int index, vector<pair<int,int>>& v, vector<int> used_paper, int total) {
    int use = accumulate(used_paper.begin(), used_paper.end(), 0);
    if (answer < use)
        return;
    if (total == v.size()) {
        answer = min(answer, use);
        return;
    }

    int i = v[index].first; int j = v[index].second;
    if (visited[i][j]) {
        dfs(index+1, v, used_paper, total);
    }
    int width = max_width(i, j);

    for (int k = width ; k >= 1; k--) {
        if (used_paper[k] < 5) {
            used_paper[k]++;
            make_visit(i, j, k, true);
            dfs(index+1, v, used_paper, total+k*k);

            used_paper[k]--;
            make_visit(i, j, k, false);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int,int>> v;
    bool one_exist = false;
    int t;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> t;
            arr[i][j] = t;
            if (t) {
                one_exist = true;
                v.push_back(make_pair(i, j));
            }
        }
    }
    if (!one_exist) {
        cout << 0 << "\n";
        return 0;
    }

    int total = 0;
    vector<int> used_paper = {0, 0, 0, 0, 0, 0};
    dfs(0, v, used_paper, total);

    answer == 987654321 ? cout << -1 << "\n"
                                  : cout << answer << "\n";
    return 0;
}
