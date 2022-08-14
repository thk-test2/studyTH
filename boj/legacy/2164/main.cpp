#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1;
        return 0;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (1) {
        q.pop();
        q.push(q.front());
        q.pop();

        if (q.size() == 1)
            break;
    }

    cout << q.front() << endl;

    return 0;
}
