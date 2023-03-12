#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    while (1) {
        cin >> n; // 'a' 입력하면 성공? 실패?
        if (cin.fail()) {
            cout << "실패" << endl;

            // cin의 상태를 나타내는 비트를 reset
            cin.clear();

            // 입력 버퍼를 비운다.
            //        cin.ignore();  // 한글자 비우기
            cin.ignore(256, '\n');
            continue;
        }
    }
    cout << n << endl;
}
