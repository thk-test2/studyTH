#include <iostream>

using namespace std;

#include <vector>

int solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (K >= S.length())
        return 1;

    vector<string> result;
    int previous = 0;
    int current = 0;

    current = S.find(' ');
    string substring;
    while(1) {
        string temp = S.substr(previous, current - previous);
        if ( (substring.length() + temp.length() + 1) <= K) {
            if (substring.empty()) {
                substring = temp;
            } else {
                substring.append(" ");
                substring.append(temp);
                result.push_back(substring);
                substring.clear();
            }
        }
        previous = current + 1;
        current = S.find(' ', previous);
        if (current == string::npos) {
            if(!substring.empty())
                result.push_back(substring);
            break;
        }
    }
    string temp2 = S.substr(previous, current - previous);
    if (temp2.length() <= K)
        result.push_back(temp2);

    if (result.empty())
        return -1;

    for (const auto& it: result)
    {
        cout << it << ", ";
    }

    return result.size();
}

int main()
{
    string s("Hello Iam Taehyun");
    cout << solution(s, 7) << endl;

//    string s1("Codility We test coders");
//    cout << solution(s1, 14) << endl;

//    string s2("To crop or not to crop");
//    cout << solution(s2, 21) << endl;
}
