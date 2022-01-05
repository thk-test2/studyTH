#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, n;
    cin >> N;
    vector<int> A, B;

    for (int i = 0; i < 2*N; i++) {
        cin >> n;
        if (i < N)
            A.push_back(n);
        else
            B.push_back(n);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    int minimum = 0;
    for (int i = 0; i < N; i++) {
        minimum += A[i]*B[i];
    }
    cout << minimum;

    return 0;
}
