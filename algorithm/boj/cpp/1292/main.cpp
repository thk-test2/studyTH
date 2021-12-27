#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int A, B;
    cin >> A;
    cin >> B;

    vector<int> N;
    int k = 1;
    while(k*(k+1)/2 < B)
        k++;

    for (int i = 1; i <= k ; i++) {
        for (int j = 1; j <=i ; j++) {
            N.push_back(i);
        }
    }
    cout << accumulate(begin(N) + A - 1, begin(N) + B, 0);
    return 0;
}
