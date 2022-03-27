#include <iostream>
#include <queue>

using namespace std;

struct Pipe {
public:
    Pipe(pair<int,int> a, pair<int,int> b) : rear(a), front(b) {}

    pair<int, int> rear;
    pair<int, int> front;
};

int N;
bool arr[17][17] = {false};

void findway(Pipe pipe, int& cnt) {
    queue<Pipe> q;
    q.push(pipe);

    while (!q.empty()) {
        Pipe temp = q.front();
        q.pop();

        if (temp.front.first == N && temp.front.second == N) {
            cnt++;
            continue;
        }

        // first: 세로(행), second: 가로(열)
        // 가로로 놓여있을 때
        if (temp.rear.first == temp.front.first) {
            // 오른쪽으로 밀기
            if (temp.front.second < N && arr[temp.front.first][temp.front.second+1])
                q.push(Pipe(make_pair(temp.rear.first, temp.rear.second+1),
                            make_pair(temp.front.first, temp.front.second+1)));
            // 대각선으로 밀기
            if (temp.front.first < N && temp.front.second < N
                    && arr[temp.front.first][temp.front.second+1]
                    && arr[temp.front.first+1][temp.front.second+1]
                    && arr[temp.front.first+1][temp.front.second])
                q.push(Pipe(make_pair(temp.rear.first, temp.rear.second+1),
                            make_pair(temp.front.first+1, temp.front.second+1)));
        // 세로로 놓여있을 때
        } else if (temp.rear.second == temp.front.second) {
            // 아래로 밀기
            if (temp.front.first < N && arr[temp.front.first+1][temp.front.second])
                q.push(Pipe(make_pair(temp.rear.first+1, temp.rear.second),
                            make_pair(temp.front.first+1, temp.front.second)));
            // 대각선으로 밀기
            if (temp.front.first < N && temp.front.second < N
                    && arr[temp.front.first][temp.front.second+1]
                    && arr[temp.front.first+1][temp.front.second+1]
                    && arr[temp.front.first+1][temp.front.second])
                q.push(Pipe(make_pair(temp.rear.first+1, temp.rear.second),
                            make_pair(temp.front.first+1, temp.front.second+1)));
        // 대각선으로 놓여있을 때
        } else {
            // 오른쪽으로 밀기. 가로로 놓임
            if (temp.front.second < N && arr[temp.front.first][temp.front.second+1])
                q.push(Pipe(make_pair(temp.rear.first+1, temp.rear.second+1),
                            make_pair(temp.front.first, temp.front.second+1)));
            // 아래로 밀기. 세로로 놓임
            if (temp.front.first < N && arr[temp.front.first+1][temp.front.second])
                q.push(Pipe(make_pair(temp.rear.first+1, temp.rear.second+1),
                            make_pair(temp.front.first+1, temp.front.second)));
            // 가로로 밀기
            if (temp.front.first < N && temp.front.second < N
                    && arr[temp.front.first][temp.front.second+1]
                    && arr[temp.front.first+1][temp.front.second+1]
                    && arr[temp.front.first+1][temp.front.second])
                q.push(Pipe(make_pair(temp.rear.first+1, temp.rear.second+1),
                            make_pair(temp.front.first+1, temp.front.second+1)));
        }
    }
}

int main()
{
//    scanf("%d", &N);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int t;
    for (int i = 1; i<=N; i++) {
        for (int j = 1; j<=N; j++) {
//            scanf("%d", &t);
            cin >> t;
            arr[i][j] = (t == 0 ? true : false);
        }
    }
    Pipe pipe(make_pair(1,1), make_pair(1,2));
    int cnt = 0;
    findway(pipe, cnt);

//    printf("%d", cnt);
    cout << cnt;

    return 0;
}
