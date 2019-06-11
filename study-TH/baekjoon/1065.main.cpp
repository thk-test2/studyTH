// https://www.acmicpc.net/problem/1065

#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);

    unsigned N;
    cin >> N;

    // 100, 10, 1의 자리수를 체크하는 변수
    unsigned hundread = 0;
    unsigned ten = 0;
    unsigned digit = 0;

    // 한수의 개수 세는 변수.
    unsigned count = 0;

    for (int i=1; i<= N; i++) {
        hundread = i/100;
        ten = (i%100) / 10;
        digit = i%10;

        // 100 미만으로는 무조건 한수라고 한다.
        if ( (i<100) ||
         (hundread - ten) == (ten - digit) )
            count++;

    }
    cout << count << "\n";

    return 0;
}