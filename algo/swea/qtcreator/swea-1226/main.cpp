#include <iostream>

using namespace std;

int arr[16][16];
bool visited[16][16] = {false};
int result = 0;
pair<int, int> startP, endP;
int dirI[4] = {-1, 1, 0, 0};
int dirJ[4] = {0, 0, -1, 1};

void dfs(pair<int, int> temp) {
    int i = temp.first; int j = temp.second;
    if (i == endP.first && j == endP.second) {
        result = 1;
        return;
    }
    for (int index = 0; index < 4; index++) {
        int ni = i + dirI[index];
        int nj = j + dirJ[index];
        if (arr[ni][nj] != 1 && !visited[ni][nj]) {
            visited[ni][nj] = true;
            dfs(make_pair(ni, nj));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int test_case = 1; test_case <= 10; test_case++) {
        int T;
        cin >> T;
        string str;
        for (int i = 0; i < 16; i++) {
            cin >> str;
            for (int j = 0; j < 16; j++) {
                visited[i][j] = false;
                arr[i][j] = str[j]-'0';
                if (arr[i][j] == 2)
                    startP = make_pair(i, j);
                else if (arr[i][j] == 3)
                    endP = make_pair(i, j);
            }
        }
        dfs(startP);

        cout << "#" << test_case << " " << result << "\n";
        result = 0;
    }

    return 0;
}
