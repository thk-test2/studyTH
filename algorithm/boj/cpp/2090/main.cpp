#include <iostream>
#include <vector>

using namespace std;
using i64 = long long int;

i64 gcd(i64 a, i64 b) {
    i64 n;
    if (a < b)
        swap(a, b);

    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

long long int lcm(i64 a, i64 b) {
    return a * b / gcd(a, b);
}

int main()
{
    int N, n;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }

    i64 a = 1;
    i64 b = v[0];
    for (int i=1; i<N; i++) {
        i64 lcmm = lcm(v[i], b);
        i64 temp = lcmm/v[i];
        a = lcmm / b * a + temp;
        b = lcmm;
    }

    cout << b/gcd(a,b) << "/" << a/gcd(a,b);

    return 0;
}
