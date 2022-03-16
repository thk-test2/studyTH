#include <iostream>

using namespace std;

int solution(int N, int K) {
    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        if ( (N % i) == 0) {
            cnt++;
            if (cnt == K) {
                return i;
            }
        }
    }
    return 0;
}

int main()
{
    int N, K;
    cin >> N;
    cin >> K;

    int ret = solution(N, K);
    cout << ret << endl;

    return 0;
}
