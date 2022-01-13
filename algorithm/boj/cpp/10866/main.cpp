#include <iostream>
#include <deque>

using namespace std;

//push_front X: 정수 X를 덱의 앞에 넣는다.
//push_back X: 정수 X를 덱의 뒤에 넣는다.
//pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//size: 덱에 들어있는 정수의 개수를 출력한다.
//empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
//front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
//back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

int main()
{
    int N;
    cin >> N;
    deque<int> dq;

    int n;
    string cmd;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        if (cmd == "push_front") {
            cin >> n;
            dq.push_front(n);
        } else if (cmd == "push_back") {
            cin >> n;
            dq.push_back(n);
        } else if (cmd == "pop_front") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        } else if (cmd == "pop_back") {
            if (dq.empty()) {
                cout << -1 << endl;
            } else {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        } else if (cmd == "size") {
            cout << dq.size() << endl;
        } else if (cmd == "empty") {
            cout << (dq.empty() ? 1 : 0) << endl;
        } else if (cmd == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << endl;
        } else if (cmd == "back") {
            cout << (dq.empty() ? -1 : dq.back()) << endl;
        }
    }

    return 0;
}
