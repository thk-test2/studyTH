#include <iostream>
#include <queue>

using namespace std;

char arr[100][100];
int inserted[100][100];

int cnt[100][100];
int dirI[4] = {1, 0, -1, 0};
int dirJ[4] = {0, 1, 0, -1};

void bfs(int i, int j, int N, int M) {
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    inserted[i][j] = true;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        int i = p.first; int j = p.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nextI = i+dirI[k];
            int nextJ = j+dirJ[k];
            if ((nextI >= 0 && nextI < N) && (nextJ >= 0 && nextJ < M)) {
                if (arr[nextI][nextJ] == '1' && inserted[nextI][nextJ] == false) {
                    q.push(make_pair(nextI, nextJ));
                    inserted[nextI][nextJ] = true;
                    cnt[nextI][nextJ] = cnt[i][j] + 1;
                }
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    char temp;
    for (int i = 0; i< N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> temp;
            arr[i][j] = temp;
            inserted[i][j] = false;
            cnt[i][j] = 1;
        }
    }

    bfs(0, 0, N, M);
    cout << cnt[N-1][M-1];

    return 0;
}
