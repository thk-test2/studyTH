#include <iostream>

using namespace std;

#include <vector>

int solution(string &S, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(S.length() <= K)
        return 1;

    int currentIndex = 0;
    int prevIndex = 0;

    int count = 0;

    string mainStr, temp;
    while (currentIndex != string::npos)
    {
        currentIndex = S.find(" ", prevIndex);
        temp = S.substr(prevIndex, currentIndex - prevIndex);

        if (mainStr.empty()) {
            if (temp.length() <= K) {
                mainStr.append(temp);
                count++;
            }
        } else {
            if (mainStr.length() + temp.length() < K)
            {
                mainStr.append(" ");
                mainStr.append(temp);
            } else if (temp.length() <= K)
            {
                mainStr.clear();
                mainStr.append(temp);
                count++;
            }
        }
        prevIndex = currentIndex + 1;
        cout << mainStr << ", ";
    }
    return count;
}

int main()
{
    string s("Hello Iam Taehyun");
    cout << solution(s, 8) << endl;

    string s1("Codility We test coders");
    cout << solution(s1, 14) << endl;

//    string s2("To crop or not to crop");
//    cout << solution(s2, 21) << endl;
}
