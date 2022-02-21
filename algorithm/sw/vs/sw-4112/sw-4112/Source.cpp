#include <iostream>
#include <queue>
#define MAX 141
using namespace std;

struct Node {
    int r, c, cur, move;              // 행, 열, 번호, 움직인 거리
};
int T, map[MAX + 1][MAX + 1];
const int dr[] = { -1, -1, 0, 0, 1, 1 }, dc[] = { -1, 0, -1, 1, 0, 1 };
pair<int, int> p[MAX * (MAX + 1) / 2 + 1];

int solve(int start, int target)
{
    queue<Node> q;
    bool visited[MAX * (MAX + 1) / 2 + 1] = { false, };

    q.push({ p[start].first, p[start].second, start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.cur == target)
            return node.move;

        for (int d = 0; d < 6; d++) {
            int R = node.r + dr[d];
            int C = node.c + dc[d];
            if (R > 0 && R <= MAX && C > 0 && C <= MAX && map[R][C] && !visited[map[R][C]]) {
                visited[map[R][C]] = true;
                q.push({ R, C, map[R][C], node.move + 1 });
            }
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    int n = 0;
    for (int i = 1; i <= MAX; i++) {
        for (int j = 1; j <= i; j++) {
            map[i][j] = ++n;
            p[n].first = i, p[n].second = j;
        }
    }
    int a, b;
    for (int test = 1; test <= T; test++) {
        cin >> a >> b;
        cout << "#" << test << ' ' << solve(a, b) << "\n";
    }

    return 0;
}
