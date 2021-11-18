#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if (num < 2)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;
    return true;
}

int solution(vector<int> A) {
    int cnt = 0;
    for (const auto& number : A) {
        if (isPrime(number)) {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int N, n;
    vector<int> A;
    cin >> N;

    for (int i = 0; i < N ; i++) {
        cin >> n;
        A.push_back(n);
    }
    cout << solution(A);
    return 0;
}
