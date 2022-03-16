#include <iostream>

using namespace std;

int main()
{
    string str;
    cin >> str;

    string a = "AAAA";
    string b = "BB";

    int cur = 0, prev = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str.substr(prev, i+1 - prev) == "XXXX") {
            str.replace(prev, i+1 - prev, a);
            prev = i+1;
        } else if (str.substr(prev, i+1 - prev) == "XX") {
            if (i < str.size()-1 && str[i+1] == 'X')
                continue;
            str.replace(prev, i+1 - prev, b);
            prev = i+1;
        } else if (str[i] == '.') {
            prev = i+1;
        }
    }
    if (str.find('X') != string::npos)
        cout << -1;
    else
        cout << str;

    return 0;
}
