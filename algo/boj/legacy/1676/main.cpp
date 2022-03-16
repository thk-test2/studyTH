#include <iostream>

using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;

    if (N == 0) {
        cout << cnt;
        return 0;
    }

    for (int i = 1; i <= N ; i++) {
        if (i % 5 == 0)
            cnt++;
        if (i % 25 == 0)
            cnt++;
        if(i % 125 == 0)
            cnt++;
    }
    cout << cnt;

    return 0;
}
