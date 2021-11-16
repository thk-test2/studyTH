#include <iostream>

using namespace std;

void solution(int N, int K) {
    if (N < K)
        swap(N, K);

    int n1 = N, n2 = K;
    while (n1 % n2 != 0) {
        int temp;
        temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    cout << n2 << endl << N / n2 * K;
}

int main()
{
    int N, K;
    cin >> N;
    cin >> K;

    solution(N, K);

    return 0;
}
