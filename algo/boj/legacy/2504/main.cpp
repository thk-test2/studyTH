#include <iostream>
#include <stack>
#include <vector>
#include <numeric>

using namespace std;

int solution(string& str) {
    stack<pair<char, int>> st;
    int sum = 0;

    for (int i = 0; i< str.size() ; i++) {
        if ( (str[i] == '(') || (str[i] == '[') ) {
            st.push(make_pair(str[i], 1));
        } else if (str[i] == ')') {
            if (st.empty())
                return 0;
            if (st.top().first == '(') {
                int temp = st.top().second;
                temp *= 2;
                st.pop();

                if (!st.empty() && st.top().first == '+') {
                    temp += st.top().second;
                    st.pop();
                }
                if (i < str.size() - 1 && (str[i+1] == '(' || str[i+1] == '[')) {
                    st.push(make_pair('+', temp));
                }
                if (st.empty())
                    sum += temp;
                else
                    st.top().second = temp;
            }
        } else if (str[i] == ']') {
            if (st.empty())
                return 0;
            if (st.top().first == '[') {
                int temp = st.top().second;
                temp *= 3;
                st.pop();

                if (!st.empty() && st.top().first == '+') {
                    temp += st.top().second;
                    st.pop();
                }
                if (i < str.size() - 1 && (str[i+1] == '(' || str[i+1] == '[')) {
                    st.push(make_pair('+', temp));
                }
                if (st.empty())
                    sum += temp;
                else
                    st.top().second = temp;
            }
        }
    }
    if (!st.empty())
        return 0;

    return sum;
}

int main()
{
    string str;
    cin >> str;
    cout << solution(str) << endl;

    return 0;
}
