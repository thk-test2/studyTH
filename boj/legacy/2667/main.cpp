#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[25][25];
char area[25][25];

void checkarea(int i, int j, int N, char prev, int& cnt) {
    if (visited[i][j] == false) {
        if(area[i][j] == prev) {
            visited[i][j] = true;
            cnt++;

            if (i < N-1)
                checkarea(i+1, j, N, area[i][j], cnt);
            if (j < N-1)
                checkarea(i, j+1, N, area[i][j], cnt);
            if (i > 0)
                checkarea(i-1, j, N, area[i][j], cnt);
            if (j > 0)
                checkarea(i, j-1, N, area[i][j], cnt);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    char t;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
           cin >> t;
           area[i][j] = t;
           visited[i][j] = false;
        }
    }
    vector<int> group;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            int cnt = 0;
            if (visited[i][j] == false) {
                if (area[i][j] == '0') {
                    visited[i][j] = true;
                } else {
                    checkarea(i, j, N, area[i][j], cnt);
                    group.push_back(cnt);
                }
            }
        }
    }
    sort(begin(group), end(group));
    cout << group.size() << endl;
    for (const auto& itr: group)
        cout << itr << endl;

    return 0;
}
