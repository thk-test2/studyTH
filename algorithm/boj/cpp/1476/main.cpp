#include <iostream>

using namespace std;

int main()
{
    int E, S, M;
    cin >> E >> S >> M;

    int e = 1;
    int s = 1;
    int m = 1;

    int i = 1;
    while (1) {
        if (e == E && s == S && m == M)
            break;
        i++;
        e = i%15;
        s = i%28;
        m = i%19;
        if (e == 0)
            e = 15;
        if (s == 0)
            s = 28;
        if (m == 0)
            m = 19;
    }

    cout << i;

    return 0;
}
