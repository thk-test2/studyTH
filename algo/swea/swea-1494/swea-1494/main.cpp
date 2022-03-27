#include <iostream>
#include <string.h>

using namespace std;

int N;
long long int answer;
int worm_x[20], worm_y[20];
bool visited[20];

void initialize() {
    answer = 9876987654321;
    memset(worm_x, 0, sizeof(worm_x));
    memset(worm_y, 0, sizeof(worm_y));
    memset(visited, false, sizeof(visited));
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> worm_x[i] >> worm_y[i];
    }
}

void cal_vector() {
    long long int x = 0, y = 0, size = 0;

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            x += worm_x[i];
            y += worm_y[i];
        }
        else {
            x -= worm_x[i];
            y -= worm_y[i];
        }
    }

    size = x * x + y * y;
    if (answer > size) answer = size;
}

void DFS(int index, int cnt) {
    if (cnt == N / 2) {
        // 지렁이 나누기
        cal_vector();

        return;
    }

    for (int i = index; i < N; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        DFS(i + 1, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    int T, testcase;

    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (testcase = 1; testcase <= T; testcase++) {
        initialize();
        input();

        // n/2 마리 먼저 선택
        DFS(0, 0);

        printf("#%d %lld\n", testcase, answer);
    }

    return 0;
}