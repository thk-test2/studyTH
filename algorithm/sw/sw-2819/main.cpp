#include <iostream>
#include <set>

using namespace std;

char arr[4][4];
int dir_i[4] = {-1, 1, 0, 0};
int dir_j[4] = {0, 0, -1, 1};
set<string> s;

void dfs(int i, int j, string temp) {
    if (temp.size() == 7) {
        s.insert(temp);
        return;
    }
    for (int index = 0; index < 4; index++) {
        int ni = i + dir_i[index];
        int nj = j + dir_j[index];

        if (ni < 0 || ni >= 4 || nj < 0 || nj >= 4) continue;

        dfs(ni, nj, temp+arr[ni][nj]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int k = 0; k < T; k++) {
        char t = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> t;
                arr[i][j] = t;
            }
        }
        string temp;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs(i, j, temp+arr[i][j]);
            }
        }

        cout << "#" << k+1 << " " << s.size() << "\n";
        s.clear();
    }

    return 0;
}
