#include <iostream>

using namespace std;

bool isPrime(int num){
    if (num < 2)
        return false;

    for (int i = 2; i*i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}

int main()
{
    int M, N;
    int sum = 0, min;
    bool flag = false;
    cin >> M;
    cin >> N;

    for (int i = M; i <= N ; i++) {
        if (isPrime(i)) {
            sum += i;
            if (!flag) {
                min = i;
                flag = true;
            }
        }
    }
    if (!flag)
        cout << -1;
    else {
        cout << sum << endl << min;
    }
    return 0;
}
