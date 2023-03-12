#include <iostream>

using namespace std;

bool visited[100][100];
char area[100][100];

void checkarea(int i, int j, int M, int N, char prev, int& cnt) {

    if (visited[i][j] == false) {
        if(area[i][j] == prev) {
            visited[i][j] = true;
            cnt++;

            if (i < M-1)
                checkarea(i+1, j, M, N, area[i][j], cnt);
            if (j < N-1)
                checkarea(i, j+1, M, N, area[i][j], cnt);
            if (i > 0)
                checkarea(i-1, j, M, N, area[i][j], cnt);
            if (j > 0)
                checkarea(i, j-1, M, N, area[i][j], cnt);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    char t;
    for (int i = 0; i<M; i++) {
        for (int j = 0; j<N; j++) {
           cin >> t;
           area[i][j] = t;
           visited[i][j] = false;
        }
    }

    int W = 0, B = 0;
    for (int i = 0; i<M; i++) {
        for (int j = 0; j<N; j++) {
            int cnt = 0;
            if (visited[i][j] == false) {
                checkarea(i, j, M, N, area[i][j], cnt);

                if (area[i][j] == 'W')
                    W += cnt*cnt;
                else
                    B += cnt*cnt;
            }
        }
    }
    cout << W << " " << B;

    return 0;
}
