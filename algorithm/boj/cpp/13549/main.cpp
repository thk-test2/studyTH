#include <iostream>
#include <queue>
#include <climits>

using namespace std;

bool visited[100001] = {false,};

int findbro(int N, int K) {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    int minimum = INT_MAX;
    int cnt = 0;

    while(!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        visited[temp.first] = true;
//        cout << temp.first << ", " << temp.second << endl;

        if (temp.first == K) {
            minimum = min(minimum, temp.second);
            continue;
        }

        if (temp.first > 0 && !visited[temp.first-1])
            q.push(make_pair(temp.first-1, temp.second+1));
        if (temp.first < 100000 && !visited[temp.first+1])
            q.push(make_pair(temp.first+1, temp.second+1));
        if (temp.first <= 50000 && !visited[2*temp.first])
            q.push(make_pair(2*temp.first, temp.second));
    }
    return minimum;
}

int main()
{
    int N, K;
    cin >> N >> K;

    cout << findbro(N, K);

    return 0;
}
