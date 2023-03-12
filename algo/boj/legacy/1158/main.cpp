#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int a[N];
    bool visited[N];

    for (int i = 0; i<N ; i++) {
        a[i] = i+1;
        visited[i] = false;
    }

    cout << "<";
    int i = 0, cnt = 0, total = 0;
    while (1) {
        if (visited[i] == false)
            cnt++;
        if (cnt == K) {
            visited[i] = true;
            cnt = 0;
            total++;
            if (total == N) {
                cout << a[i];
                break;
            }
            else {
                cout << a[i] << ", ";
            }
        }
        i = (++i) % N;
    }
    cout << ">";

    return 0;
}
