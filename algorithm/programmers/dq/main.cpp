#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;

    for (auto& itr : operations) {

        for (const auto& itr2: dq)
            cout << itr2 << ", ";
        cout << endl;

        if (*itr.begin() == 'I') {
            string tmp = itr.substr(2, itr.length());
            dq.push_back(stoi(tmp));
            sort(dq.begin(), dq.end());
        } else if (*itr.begin() == 'D') {
            if (dq.empty())
                continue;
            if (*(itr.begin()+2) == '-') {
                dq.pop_front();
            } else {
                dq.pop_back();
            }
        }
    }
    if (dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    cout << endl;
    for (const auto& itr2: answer)
        cout << itr2 << ", ";
    cout << endl;
    return answer;
}

int main()
{
    cout << "Hello World!" << endl;
    solution({"I 16","D 1"});
    solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
    solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});

    return 0;
}
