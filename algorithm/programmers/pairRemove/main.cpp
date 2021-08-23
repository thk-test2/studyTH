#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    if (s.length()%2 == 1)
        return 0;

    stack<char> st;

    for (int i = 0; i < s.length() ; ++i) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else if (s[i] == st.top()) {
            st.pop();
        }
    }
    return st.empty() ? 1 :  0;
}

int main()
{
    cout << solution("baabaa") << endl;
    cout << solution("cdcd") << endl;

    return 0;
}
