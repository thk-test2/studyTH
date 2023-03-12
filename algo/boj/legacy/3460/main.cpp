#include <iostream>
#include <bitset>

using namespace std;

void solution(int n) {
    bitset<20> bits = n;

    for (int i = 0; i < 20; i++) {
        bitset<20> mask = 1 << i;
        auto test = (bits & mask);
        if (test.count() == 1) {
            cout << i << " ";
        }
    }
}

int main()
{
    int T, n;
    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> n;
        solution(n);
    }
    return 0;
}
